//
// Created by yang on 2020/6/25.
//

#ifndef ARM_SE_ARMDRIVER_H
#define ARM_SE_ARMDRIVER_H

#include "../include/MotorDriver.h"
#include "../include/Kinematics.h"
#include "../include/gnuplot-iostream.h"
#include "../include/cubicSpline.h"

#define PI 3.1415926


uchar id[4] = {11, 12, 13, 14};
int max_speed[4] = {1000,1000,1000,1000};
int max_acc[4] = {1000,1000,1000,1000};
int home_pos[4] = {0,0,0,850};
int ratio[4] = {40,40,40,40};

int Baudrate = 1000000;
double current_angle[4]{0,0,0,0};
double current_pos[3]={0,0,0};

class ArmDriver {
public:


    ArmDriver();
    ~ArmDriver();
    int connect_check();
    int motor_init();
    int read_angle();
    int read_pos();
    int write_angle(double *target);
    int write_pos(double target_x, double target_y, double rotation, double gripper, double platform);
    int interpolation(double start_x, double start_y, double end_x, double end_y, int points, double rotation, double gripper, double platform);


    };


#endif //ARM_SE_ARMDRIVER_H
