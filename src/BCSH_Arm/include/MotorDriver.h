//
// Created by yang on 2020/2/8.
//

#ifndef BCSH_ARM_MOTORDRIVER_H
#define BCSH_ARM_MOTORDRIVER_H

#include "../include/WzSerialPort.h"
#include <string>


class MotorDriver {
public:
    MotorDriver();
    ~MotorDriver();
    int init(char* port_name);
    int add_wayPoint();
    bool track_path();

    int enable(char id);
    int disable(char id);
    int pos_control(char id, double target, int ratio);
    char* get_pos(char id, char *result);
    char check(char *data, int len);
};


#endif //BCSH_ARM_MOTORDRIVER_H
