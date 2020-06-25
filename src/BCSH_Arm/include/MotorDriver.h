//
// Created by yang on 2020/2/8.
//

#ifndef BCSH_ARM_MOTORDRIVER_H
#define BCSH_ARM_MOTORDRIVER_H

#include <string>
#include "WzSerialPort.h"


class MotorDriver {
public:
    enum MOTOR_RAM
    {
        PD_SERIAL0 = 0x00,
        PD_SERIAL1 = 0x04,
        PD_SERIAL2 = 0x08,
        PD_HW_VER = 0x0C,
        PD_SW_VER = 0x0D,
        CONFIG_ID = 0x0E,
        CONFIG_BR = 0x0F,

        EN_ELE_CAL = 0x60,
        EN_USR_CAL,
        EN_MOTOR,
        EN_BRAKE,
        EN_SaveConfig,
        EN_RESET_FACTORY,
        USR_CAL_POS0 = 0x70,
        USR_CAL_POS1,
        USR_CAL_POS2,
        USR_CAL_POS3,
        TAEGET_CURRENT0 = 0xBE,
        TAEGET_CURRENT1,
        TARGET_SPEED0 = 0xA0,
        TARGET_SPEED1,
        ACC0,
        ACC1,
        MAX_SPEED0,
        MAX_SPEED1,
        TARGET_POS0,
        TARGET_POS1,
        TARGET_POS2,
        TARGET_POS3,
        SPEED0,
        SPEED1,
        POS0,
        POS1,
        POS2,
        POS3,
        CURRENT0,
        CURRENT1,
        SYS_ERROR0,
        SYS_ERROR1,
        SYS_MOTOR_TEMP_0,
        SYS_MOTOR_TEMP_1,
        SYS_VOL0,
        SYS_VOL1,
        SYS_POWER0,
        SYS_POWER1,
    };


    MotorDriver();
    ~MotorDriver();
    bool init(const char* port_name,int baudrate);
    bool init(uchar id ,int baudrate);
    int add_wayPoint();
    bool track_path();

    int enable(char id);
    int disable(char id);
    int brakeEnable(char id);
    int brakeDisable(char id);
    int calEleAngle(char id);
    int calUsrPos(char id , int calpos);

    int setAcc(char id , int acc);
    int setMaxSpeed(char id,int maxspeed);

    int setSpeed(char id,int speed);
    int setPos(char id,int pos);
    int setAcc_MaxSpeed_Pos(char id , int pos, int maxspeed,int acc);
    int setPos_n(char id,int posn);
    int pos_control(char id, double target, int ratio);
    int getPos(char id, int *pos);
    char check(unsigned char *data, int len);

    int readreg(unsigned char id ,unsigned char reg,unsigned char *buff, int len);

    void mSleep(int mtime);
    void uSleep(int utime);


};


#endif //BCSH_ARM_MOTORDRIVER_H
