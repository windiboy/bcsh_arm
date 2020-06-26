#include <iostream>
#include <string.h>
#include "../include/WzSerialPort.h"
#include "../include/MotorDriver.h"
#include "../include/cubicSpline.h"

#include <map>
#include <vector>
#include <cmath>
#include "boost/filesystem.hpp"
#include "gnuplot-iostream.h"

#define POINTS_COUNT 12



using namespace std;


void test1(){
    double x_data[POINTS_COUNT] = {0, 0.422955130, 0.598557636, 0.734591320, 0.850603738, 0.953558869, 1.056514000, 1.159469131, 1.274332912, 1.409208218, 1.585026197, 2};
    double y_data[POINTS_COUNT] = {0, 0.14881055128822188, 0.2976136037517004, 0.4464166562151788, 0.5952197086786574, 0.7440227611421358, 0.8928258136056142, 1.0416288660690929, 1.1904319185325714, 1.3392349709960498, 1.4880380234595283, 1.6368410759230068};

    double x_out = 0;
    double y_out = 0;
    Gnuplot gp;
    std::vector<std::pair<double, double> > data;

    cubicSpline spline;
    spline.loadData(x_data, y_data, POINTS_COUNT, 0, 0, cubicSpline::BoundType_First_Derivative);

    x_out = -0.008;
    for(int i=0; i<=250; i++)
    {
        x_out = x_out + 0.008;
        spline.getYbyX(x_out, y_out);
        printf("%f, %0.9f \n", x_out, y_out);
        data.push_back(std::make_pair(x_out, y_out));
        gp << "plot" << gp.file1d(data) << "with lines title 'cubic'," << endl;
    }

}
void display(){
    Gnuplot gp;

    std::vector<std::pair<double, double> > xy_pts_A;
    for(double x=-2; x<2; x+=0.01) {
        double y = x*x*x;
        xy_pts_A.push_back(std::make_pair(x, y));
    }

    std::vector<std::pair<double, double> > xy_pts_B;
    for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
        double theta = alpha*2.0*3.14159;
        xy_pts_B.push_back(std::make_pair(cos(theta), sin(theta)));
    }

    //gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    // Data will be sent via a temporary file.  These are erased when you call
    // gp.clearTmpfiles() or when gp goes out of scope.  If you pass a filename
    // (e.g. "gp.file1d(pts, 'mydata.dat')"), then the named file will be created
    // and won't be deleted (this is useful when creating a script).
    gp << "plot" << gp.file1d(xy_pts_A) << "with lines title 'cubic',"
       << gp.file1d(xy_pts_B) << "with points title 'circle'" << std::endl;
}

int main(int argumentCount, const char* argumentValues[]) 
{
	// 假设 /dev/ttyS1 已经和另外一个串口连接好了
	double target[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++)
        cout << setfill(' ') << setw(10) << target[i];
//    test1();
    //display();

	return 0;
} 