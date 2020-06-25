#include "../include/Kinematics.h"
#include <iostream>

//以机器人正前方为x轴正方向  竖直向上为y轴正方向
int ang2pos(double *x, double *y , double thet1, double thet2){
    *x = L1*cos(thet1)+L2*cos(thet1+thet2);
    *y = L1*sin(thet1)+L2*sin(thet1+thet2);
    return 1;
}
int pos2ang(double x, double y , double *thet1, double *thet2){
    double c2,s2;
    c2 = (x*x+y*y-L1*L1-L2*L2)/(2*L1*L2);
    if(c2 >= -1 && c2 <= 1) {
        s2 = -1 * sqrt(1 - c2 * c2);
        *thet2 = atan2(s2, c2);
        *thet1 = atan2(y, x) - atan2(L2 * s2, L1 + L2 * c2);
        return 1;
    } else
        return -1;
}
int angle_acc_calculation(double x__, double y__ , double thet1, double thet2, double *thet1__, double *thet2__){
    double a11,a12,a21,a22;
    a11 = -1*L1*sin(thet1)-L2*sin(thet1+thet2);
    a12 = -L2*sin(thet1+thet2);
    a21 = L1*cos(thet1)+L2*cos(thet1+thet2);
    a22 = L2*cos(thet1+thet2);
    *thet1__ = abs(a11*x__+a21*y__ );
    *thet2__ = abs(a21*x__+a22*y__ );
}