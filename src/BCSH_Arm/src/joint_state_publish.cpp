#include <string>
#include <ros/ros.h>
#include <iostream>
#include <sensor_msgs/JointState.h>
#include "../include/WzSerialPort.h"

using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "bcsh_state_publisher");
    ros::NodeHandle n;
    WzSerialPort w;
    //发布joint state
    ros::Publisher Pub_joint = n.advertise<sensor_msgs::JointState>("/move_group/my_arm_controller_joint_states",10);

    sensor_msgs::JointState joint_state;
    joint_state.header.stamp = ros::Time::now();
    joint_state.name.resize(4);
    joint_state.position.resize(4);
    joint_state.name[0] ="joint_1";
    joint_state.name[1] ="joint_2";
    joint_state.name[2] ="joint_3";
    joint_state.name[3] ="joint_4";

    std::string port;
    n.getParam("receive_port",port);
    w.open(&port[0], 1000000, 0, 8, 1);
    int pos_len = 11;
    char pos[pos_len];
    double result;

    ros::Rate loop_rate(30);
    while (ros::ok()) {
        //update joint_state
        if(w.receive(pos,pos_len)){
            result = (pos[9]*256*256*256+pos[8]*256*256+pos[7]*256+pos[6])/262144/40*3.14;
            cout << "current pos is  :" << result << endl;
        }
//        else
//            cout << "Read Pos Fail!!!  " << endl;
        joint_state.position[0] = 0.1;
        joint_state.position[1] = 0.2;
        joint_state.position[2] = 0.3;
        joint_state.position[3] = 0.4;

        //send the joint state and transform
        Pub_joint.publish(joint_state);

        // This will adjust as needed per iteration
        loop_rate.sleep();
    }


    return 0;
}