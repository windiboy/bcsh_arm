# BCSH_Arm

#### 介绍
本项目是BCSH开发的一款面向教学的柔性机械臂。

#### 软件环境
Ubuntu18.04  Ros-Melodic 


#### 所作工作

1. 根据实际机械臂建立URDF模型

   ![2020-02-14 14-39-33 的屏幕截图](/home/yang/图片/2020-02-14 14-39-33 的屏幕截图.png)

2. 建立bcsh_moveit_config包

3. 编写moveit客户端 , 服务端, 获取moveit规划路径

4. 编写电机驱动类 , 实现与真实机械臂通信
####  软件架构

![控制框架](/media/yang/2A7A72637A722C27/Users/yang/Desktop/实验室/BCSH课程研发要求/控制框架.png)

1. 首先，设置机械臂的初始姿态，其姿态需与实体机械臂的姿态一致，否则规划的运动会出现偏差，然后通过C++/Python设置机械臂需要到达的终点坐标及其末端姿态。
2. 其次，使用预设置好的逆运动学算法插件计算机械臂运动学逆解并使用Moveit的运动规划完成设定起点到终点的轨迹规划。
3. 然后通过ActionClient接收规划结果并以目标信息的格式发送到ActionServer中，在ActionServer对数据进行二次处理，将规划的路径转换进行插值,  计算出速度和加速度信息,  并发送给电机进行执行;  ActionServer完成数据的处理后，会发送执行成功的信息到ActionClient，以接收下一批数据。
4. 最后下位机通过RS485串口，检测数据是否有效，若有效则对数据按照不同关节再次进行处理并发送到对应关节舵机，最终实现对实体机械臂的控制。同时将各关节状态返回给上位机实现闭环控制。

#### 关键代码说明

1.  MotorDriver 类 包含对电机的使能 位置控制 读取位置等一系列操作
2.  WzSerialPort 类 串口通信类
3.  cubicSpine 类 三次曲线插值类
4.  gnuplot-iostream 类 画图分析类
5.  my_arm_servers.cpp moveit服务端 
6.  joint_state_publish.cpp 关节信息更新节点
7.  low_level_controllers.launch 启动文件

#### 效果展示

注:需要配合bcsh_moveit_config使用

`roslaunch BCSH_Arm low_level_controllers.launch`

`roslaunch bcsh_moveit_config test1.0.launch`

![2020-02-14 14-36-50 的屏幕截图](/home/yang/图片/2020-02-14 14-36-50 的屏幕截图.png)