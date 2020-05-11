//action服务端的相关定义，请加入到驱动节点的头文件中
#include "actionlib/server/action_server.h"
//action服务端的目标控制句柄定义，与接收的目标相关联后，可以用来实现action的信息反馈等操作
#include "actionlib/server/server_goal_handle.h"
#include "control_msgs/FollowJointTrajectoryAction.h"
#include "ros/ros.h"
#include "gnuplot-iostream.h"
#include <sensor_msgs/JointState.h>
#include "../include/cubicSpline.h"
#include "../include/MotorDriver.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

cubicSpline spline0,spline1,spline2,spline3;
//定义四个电机
MotorDriver m1,m2,m3,m4;
//画图所需参数
Gnuplot gp;
string port;


class ArmDriver
{
protected:

    ros::NodeHandle nh_;
    ros::Publisher Pub_joint = nh_.advertise<sensor_msgs::JointState>("/move_group/my_arm_controller_joint_states",10);
    //定义action服务端
    actionlib::ActionServer<control_msgs::FollowJointTrajectoryAction>  as_;
    //定义action服务端目标控制句柄
    actionlib::ServerGoalHandle<control_msgs::FollowJointTrajectoryAction> goal_handle_;
    //用来反馈action目标的执行情况，客户端由此可以得知服务端是否执行成功了
    control_msgs::FollowJointTrajectoryResult result_;

    std::string action_name_;
    sensor_msgs::JointState joint_state;


public:

    ArmDriver(std::string name) :
            as_(nh_, name, boost::bind(&ArmDriver::goalCB, this, _1), false),
            action_name_(name)
    {
        as_.start();
    }

    void goalCB( actionlib::ServerGoalHandle<control_msgs::FollowJointTrajectoryAction> gh)
    {
        //疑点1：什么要将形参复制一份？
        //因为我们要修改这个参数，但又不#include "../include/MotorDriver.h"能直接改形参所指向的那个目标对象，那样做会破坏原始数据，是编程所不推荐的，这里复制一个副本，目的就是要修改这个数据而不破坏原始数据。
        actionlib::ActionServer<control_msgs::FollowJointTrajectoryAction>::Goal goal = *gh.getGoal();    //make a copy that we can modify

        //将之前定义的句柄与传入的action目标绑定在一起，
        goal_handle_ = gh;
        //初始化joint state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(4);
        joint_state.position.resize(4);
        joint_state.name[0] ="joint_1";
        joint_state.name[1] ="joint_2";
        joint_state.name[2] ="joint_3";
        joint_state.name[3] ="joint_4";
        //获取路径点个数
        int len;
        len = end(goal.trajectory.points)-begin(goal.trajectory.points);
        cout << "points numbers :" << len << endl;
        //添加路点
        double data_x[len];
        double data0[len],data1[len],data2[len],data3[len];
        for(int i =0; i<len; i++){
            data_x[i] = goal.trajectory.points[i].time_from_start.toSec();
            data0[i] = goal.trajectory.points[i].positions[0];
            data1[i] = goal.trajectory.points[i].positions[1];
            data2[i] = goal.trajectory.points[i].positions[2];
            data3[i] = goal.trajectory.points[i].positions[3];
        }
        //插值所需变量
        double x_out = 0;
        double y0 = 0, y1=0, y2=0, y3=0;

        std::vector<std::pair<double, double> > data_out,data_in;
        //画插值之前的路径点
        for(int i=0; i<=len; i++){
            data_in.push_back(std::make_pair(data_x[i], data1[i]));
        }
        nh_.getParam("send_port",port);
        //初始化电机，打开串口
        m1.init(&port[0]);
        //三次曲线插值
        spline0.loadData(data_x, data0, len, 0, 0, cubicSpline::BoundType_First_Derivative);
        spline1.loadData(data_x, data1, len, 0, 0, cubicSpline::BoundType_First_Derivative);
        spline2.loadData(data_x, data2, len, 0, 0, cubicSpline::BoundType_First_Derivative);
        spline3.loadData(data_x, data3, len, 0, 0, cubicSpline::BoundType_First_Derivative);

        //按周期发送给电机
        x_out = -0.004;
        while ((abs(y0-data0[len-1])>0.002)||(abs(y1-data1[len-1])>0.002)||(abs(y2-data2[len-1])>0.002)||(abs(y3-data3[len-1])>0.002))
        {
            x_out = x_out + 0.004;
            //取得插值的y值
            spline0.getYbyX(x_out, y0);
            spline1.getYbyX(x_out, y1);
            spline2.getYbyX(x_out, y2);
            spline3.getYbyX(x_out, y3);
            //画插值之后的曲线
            data_out.push_back(std::make_pair(x_out, y1));
//            printf("%f, %0.9f \n", x_out, y_out);
            //串口发送位置，假设电机id为1 2 3 4
            m1.pos_control(0x01,y0,40);
            m2.pos_control(0x02,y1,40);
            m3.pos_control(0x03,y2,40);
            m4.pos_control(0x04,y3,40);
        }
        joint_state.position[0] = y0;
        joint_state.position[1] = y1;
        joint_state.position[2] = y2;
        joint_state.position[3] = y3;
        //send the joint state
        Pub_joint.publish(joint_state);
        //画图显示
        gp << "plot" << gp.file1d(data_out) << "with lines title 'position[0].out',"
           << gp.file1d(data_in) << "with points title 'position[0].in'" << endl;

        //告诉客户端成功了
        goal_handle_.setAccepted();
        result_.error_code = result_.SUCCESSFUL;
        goal_handle_.setSucceeded(result_);
    }
};


int main(int argc, char** argv)
{
    ros::init(argc, argv, "arm_driver");

    ArmDriver armdriver("my_arm_controller/follow_joint_trajectory");
    ros::spin();

    return 0;
}