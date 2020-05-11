//
// Created by yang on 2020/2/8.
//

#include "../include/MotorDriver.h"
#include <iostream>
using namespace std;
WzSerialPort w;
MotorDriver::MotorDriver(){
}
MotorDriver::~MotorDriver() {
}

int MotorDriver::init(char *port_name) {
    if(w.open( port_name, 1000000, 0, 8, 1))
        cout << "connect to send port:" << port_name << endl;
    else
        cout << "canot connect to send port:" << port_name << endl;
}

int MotorDriver::enable(char id) {
    int len = 8;
    char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = 0x62;
    data[6] = 0x01;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;

}
char MotorDriver::check(char *data, int len) {
    char result = 0x00;
    for(int i = 2; i < len; i++){
        result = result+data[i];
    }
    return (result&0xff)^0xff;

}
int MotorDriver::disable(char id) {
    int len = 8;
    char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = 0x62;
    data[6] = 0x00;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;

}
int MotorDriver::pos_control(char id, double target, int ratio) {
    int len = 11;
    char data[len];
    char pos[4];
    int actual;
    actual = int(target/3.14*262144*ratio);
    pos[0] = actual/(256*256*256);
    pos[1] = actual%(256*256*256)/(256*256);
    pos[2] = actual%(256*256*256)%(256*256)/256;
    pos[3] = actual%(256*256*256)%(256*256)%256;

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x07;
    data[4] = 0x03;
    data[5] = 0xA6;
    data[6] = pos[3];
    data[7] = pos[2];
    data[8] = pos[1];
    data[9] = pos[0];
    data[10] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}
char* MotorDriver::get_pos(char id, char *result) {
    int len = 8;
    char data[len];
    int pos_len = 11;
    char pos[pos_len];
    //data = 'FE EF '+self.motro_id+' 04 02 AC 04 '+self.check(self.motro_id+' 04 02 AC 04 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x02;
    data[5] = 0xAC;
    data[6] = 0x04;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len)){
        w.receive(pos,pos_len);
        return pos;
    }
    else
        cout << "Read Position Fail!!!" << endl;
}
