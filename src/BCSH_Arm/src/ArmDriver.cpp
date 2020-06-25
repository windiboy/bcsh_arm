//
// Created by yang on 2020/6/25.
//

#include "../include/ArmDriver.h"

MotorDriver motor;

ArmDriver::ArmDriver(){

}
ArmDriver::~ArmDriver(){
}
int ArmDriver::connect_check() {
    std::cout << "############### connect check! ###############" <<std::endl;

    if(!motor.init(10,Baudrate))
        return -1;
    ArmDriver::read_angle();
    std::cout << "############### connect check is ok! ###############" <<std::endl;
    return 1;
}
int ArmDriver::motor_init(){
    for(int i=0;i<=3;i++){
        motor.setMaxSpeed(id[i],max_speed[i]);
        motor.setAcc(id[i],max_acc[i]);

        motor.enable(id[i]);
        motor.mSleep(10);
    }
    for(int i=0;i<=3;i++) {
        motor.setPos(id[i],home_pos[i]);
        motor.mSleep(10);
    }
    motor.enable(10);
    motor.mSleep(10);

    ArmDriver::read_pos();
}
int ArmDriver::read_angle() {
    int pos[3];
    for(int i=0;i<=2;i++) {
        if (!motor.getPos(id[i], &pos[i])) {
            std::cout << id[i] << "motor: getpos failed!!!" << std::endl;
            return -1;
        }
        motor.mSleep(10);
        current_angle[i] = pos[i] * PI * 2 / (262144 * ratio[i]);
        current_angle[0] = -current_angle[0];
//        std::cout << id[i] <<"motor pos: " << current_angle[i] << std::endl;
    }
}
int ArmDriver::read_pos() {
    ArmDriver::read_angle();
    ang2pos(&current_pos[0],&current_pos[1],current_angle[0],current_angle[1]);
    for(int i=0;i<=2;i++) {
        std::cout << i << "motor pos: " << current_pos[i] << std::endl;
    }
}
int ArmDriver::write_angle(double *target) {
    int pos[5];

    if(!(target[0]>=-PI/2 && target[0]<=PI/2 &&
         target[1]>=-PI*3/2 && target[1]<=PI*3/2 &&
         target[2]>=-PI && target[2]<=PI &&
         target[3]>=0 && target[3]<=1 &&
         target[4]>=0 && target[4]<=0.25)){
        std::cout << "############### out of range! ###############" <<std::endl;
        return -1;
    }

    for(int i=0;i<=2;i++) {

        pos[i] = target[i]*262144*ratio[i]/(PI*2);
        pos[0] = -pos[0];
        pos[2] = -pos[2];

//        std::cout << "target pos: " << pos[i] << std::endl;
        motor.setPos(id[i], pos[i]);
        motor.mSleep(10);
    }

    pos[3] = target[3]*(850-450)+450;
//    std::cout << "target pos: " << pos[3] << std::endl;
    motor.setPos(id[3], pos[3]);
    motor.mSleep(10);

    pos[4] = target[4]*-262144*500/0.25;
//    std::cout << "target pos: " << pos[4] << std::endl;
    motor.setPos(10, pos[4]);
    motor.mSleep(10);
}
int ArmDriver::write_pos(double target_x, double target_y, double rotation, double gripper, double platform) {
    double target[5];
    pos2ang(target_x,target_y, &target[0],&target[1]);
    target[2] = rotation;
    target[3] = gripper;
    target[4] = platform;

//    std::cout << target[0] << "  " << target[1] << std::endl;
    ArmDriver::write_angle(target);
}
int ArmDriver::interpolation(double start_x, double start_y, double end_x, double end_y, int points, double rotation,
                             double gripper, double platform) {
    int POINTS_COUNT = 3;
    double x_data[POINTS_COUNT] = {start_x, (start_x+end_x)/2, end_x};
    double y_data[POINTS_COUNT] = {start_y, (start_y+end_y)/2, end_y};

    double x_out = 0;
    double y_out = 0;
    Gnuplot gp;
    std::vector<std::pair<double, double> > data;

    cubicSpline spline;
    spline.loadData(x_data, y_data, POINTS_COUNT, 0, 0, cubicSpline::BoundType_First_Derivative);

    x_out = start_x;
    for(int i=0; i<points; i++)
    {
        spline.getYbyX(x_out, y_out);

//        printf("%f, %0.9f \n", x_out, y_out);
//        data.push_back(std::make_pair(x_out, y_out));
//        gp << "plot" << gp.file1d(data) << "with lines title 'cubic'," << std::endl;

        ArmDriver::write_pos(x_out,y_out,rotation,gripper,platform);
        x_out = x_out + (end_x-start_x)/points;
    }
}
