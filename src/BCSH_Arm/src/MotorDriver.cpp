#include "../include/MotorDriver.h"
#include <iostream>
using namespace std;
WzSerialPort w;



MotorDriver::MotorDriver(){
}
MotorDriver::~MotorDriver() {
    w.close();
}

bool MotorDriver::init(const char *port_name,int baudrate) {
    return w.open( port_name, baudrate, 'N', 8, 1);
}
/**
*@brief             打卡串口，自动搜索串口号
*@param id   		类型uchar 总线上存在打某一电机的ID
*@param baudrate 	类型 int 串口波特率
*@return     		类型bool true成功搜索到串口并打开,false未找到正确到串口
*/
bool MotorDriver::init(uchar id , int baudrate) {
    char portname[20];
    for(int i=0;i<10;i++)
    {
        sprintf(portname,"/dev/ttyUSB%d",i);
        if(w.open(portname, baudrate, 'N', 8, 1))
        {
            uchar recdata;
            if(readreg(id,CONFIG_ID,&recdata,1)>=0)
            {
                if(recdata==id)
                {
                    std::cout << portname << " find motor!" <<std::endl;
                    return true;
                }
                std::cout << portname << " cnanot find motor!" <<std::endl;
                w.close();
            }
            else
            {
                std::cout << portname << " cnanot find motor!" <<std::endl;
                w.close();
            }
        }
    }
    return false;
}

char MotorDriver::check(unsigned char *data, int len) {
    uchar result = 0x00;
    for(int i = 2; i < len - 1; i++){
        result += data[i];
    }
    result = ~result;
    return result;

}
int MotorDriver::enable(char id) {
    int len = 8;
    unsigned char data[len];
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
int MotorDriver::disable(char id) {
    int len = 8;
    unsigned char data[len];
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

int MotorDriver::brakeEnable(char id){
    int len = 8;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = EN_BRAKE;
    data[6] = 0x01;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}
int MotorDriver::brakeDisable(char id){
    int len = 8;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = EN_BRAKE;
    data[6] = 0x00;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::calEleAngle(char id){
    int len = 8;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = EN_ELE_CAL;
    data[6] = 0x01;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::calUsrPos(char id, int calpos){
    int len = 11;
    unsigned char data[len];

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x07;
    data[4] = 0x03;
    data[5] = USR_CAL_POS0;
    data[6] = calpos&0xFF;
    data[7] = (calpos>>8)&0xFF;
    data[8] = (calpos>>16)&0xFF;
    data[9] = (calpos>>24)&0xFF;
    data[10] = MotorDriver::check(data, len);
    if(!w.send(data, len))
        return -1;
    mSleep(10);
    len = 8;
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x03;
    data[5] = EN_USR_CAL;
    data[6] = 0x01;
    data[7] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}


int MotorDriver::setSpeed(char id,int speed) {
    int len = 9;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x05;
    data[4] = 0x03;
    data[5] = TARGET_SPEED0;//0xA0
    data[6] = speed & 0xFF;
    data[7] = (speed>>8) & 0xFF;
    data[8] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}
int MotorDriver::setAcc(char id, int acc){
    int len = 9;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x05;
    data[4] = 0x03;
    data[5] = ACC0;
    data[6] = acc & 0xFF;
    data[7] = (acc>>8) & 0xFF;
    data[8] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::setMaxSpeed(char id, int maxspeed){
    int len = 9;
    unsigned char data[len];
    //data = 'FE EF '+self.motor_id+' 04 03 62 01 '+self.check(self.motor_id+' 04 03 62 01 ')
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x05;
    data[4] = 0x03;
    data[5] = MAX_SPEED0;
    data[6] = maxspeed & 0xFF;
    data[7] = (maxspeed>>8) & 0xFF;
    data[8] = MotorDriver::check(data, len);
    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::setPos(char id, int target) {
    int len = 11;
    unsigned char data[len];

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x07;
    data[4] = 0x03;
    data[5] = TARGET_POS0;
    data[6] = target&0xFF;
    data[7] = (target>>8)&0xFF;
    data[8] = (target>>16)&0xFF;
    data[9] = (target>>24)&0xFF;
    data[10] = MotorDriver::check(data, len);

    if(w.send(data, len))
        return 1;
    else
        return -1;
}
int MotorDriver::setAcc_MaxSpeed_Pos(char id , int pos, int maxspeed,int acc)
{
    int len = 15;
    unsigned char data[len];

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x0B;
    data[4] = 0x03;
    data[5] = ACC0;

    data[6] = acc&0xFF;
    data[7] = (acc>>8)&0xFF;


    data[8] = maxspeed&0xFF;
    data[9] = (maxspeed>>8)&0xFF;

    data[10] = pos&0xFF;
    data[11] = (pos>>8)&0xFF;
    data[12] = (pos>>16)&0xFF;
    data[13] = (pos>>24)&0xFF; 

    data[14] = MotorDriver::check(data, len);

    if(w.send(data, len))
        return 1;
    else
        return -1;

}

int MotorDriver::setPos_n(char id, int target_n) {
    int len = 11;
    unsigned char data[len];
    int target = target_n*262144;

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x07;
    data[4] = 0x03;
    data[5] = TARGET_POS0;
    data[6] = target&0xFF;
    data[7] = (target>>8)&0xFF;
    data[8] = (target>>16)&0xFF;
    data[9] = (target>>24)&0xFF;
    data[10] = MotorDriver::check(data, len);

    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::pos_control(char id, double target, int ratio) {
    int len = 11;
    unsigned char data[len];
    int actual;

    actual = int(target/3.1415926*262144*ratio);
    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x07;
    data[4] = 0x03;
    data[5] = 0xA6;
    data[6] = actual&0xFF;
    data[7] = (actual>>8)&0xFF;
    data[8] = (actual>>16)&0xFF;
    data[9] = (actual>>24)&0xFF;
    data[10] = MotorDriver::check(data, len);

    if(w.send(data, len))
        return 1;
    else
        return -1;
}

int MotorDriver::getPos(char id, int *pos){
    uchar buffer[4];
    if(readreg(id,POS0,buffer,4)==4)
    {
        (*pos) = static_cast<int>(static_cast<unsigned int>(buffer[3]<<24)&0xFF000000);
        (*pos) |= ((buffer[2]<<16)&0xFF0000);
        (*pos) |= ((buffer[1]<<8)&0xFF00);
        (*pos) |= (buffer[0]&0xFF);
        return 1;
    }
    return -1;
}
//char* MotorDriver::get_pos(char id, char *result) {
//    int len = 8;
//    unsigned char data[len];
//    int pos_len = 11;
//    char pos[pos_len];
//    //data = 'FE EF '+self.motro_id+' 04 02 AC 04 '+self.check(self.motro_id+' 04 02 AC 04 ')
//    data[0] = 0xFE;
//    data[1] = 0xEF;
//    data[2] = id;
//    data[3] = 0x04;
//    data[4] = 0x02;
//    data[5] = 0xAC;
//    data[6] = 0x04;
//    data[7] = MotorDriver::check(data, len);

//    if(w.send(data, len)){
//        w.receive(pos,pos_len);
//        return pos;
//    }
//    else
//        cout << "Read Position Fail!!!" << endl;
//}



int MotorDriver::readreg(unsigned char id ,unsigned char reg,unsigned char *buff, int len)
{
    int size = 8;
    uchar data[1024];
    uchar rec_data[1024];

    data[0] = 0xFE;
    data[1] = 0xEF;
    data[2] = id;
    data[3] = 0x04;
    data[4] = 0x02;
    data[5] = reg;
    data[6] = static_cast<uchar>(len);
    data[7] = MotorDriver::check(data, size);
    for(int i=0;i<256;i++)
    {
        rec_data[i]= 0;
    }
    w.clear();

    if(w.send(data, size))
    {
        int readlen = 0,count=0;
        int totallen=0;
        do{
            count++;
            readlen = w.receive(rec_data,256);
            uSleep(100);
        }while(readlen<=0 && count<50);//receive first stage:begin receive data
        if(count>=50)//timeout
            return -1;
        totallen = readlen;
        do{
            uSleep(100);
            readlen = w.receive(&rec_data[totallen-1],256);
            totallen += readlen;
        }while(readlen!=0);//receive second stage:no more receive data
        //FE EF 0D 07 E0 AC 54 FD 03 00 0B
        if(totallen == len+7)
        {

            if(rec_data[0]==0xFE && rec_data[1]==0xEF)//head1 head2 id
            {
                if(rec_data[2]==id || rec_data[2]==0xFF)
                {

                    if(rec_data[3] == static_cast<uchar>(len+3))
                    {
                        uchar checktemp = MotorDriver::check(rec_data, totallen);
                        if(rec_data[totallen-1] == checktemp)
                        {
                            for(int i=0;i<len;i++)
                            {
                                buff[i] = rec_data[i+6];
                            }
                            return len;
                        }
                    }
                }
            }
        }
        return -1;
    }
    else
        return -1;
}

void MotorDriver::mSleep(int mtime)
{
    struct timeval tv;
    unsigned long usec = static_cast<unsigned long>(mtime*1000) ;
    tv.tv_sec = usec / 1000000;
    tv.tv_usec = usec % 1000000;

    int err;
    do {
        err = select(0, NULL, NULL, NULL, &tv);
    } while(err < 0 && errno == EINTR);
}
void MotorDriver::uSleep(int usec)
{
    struct timeval tv;
    tv.tv_sec = usec / 1000000;
    tv.tv_usec = usec % 1000000;

    int err;
    do {
        err = select(0, NULL, NULL, NULL, &tv);
    } while(err < 0 && errno == EINTR);
}

