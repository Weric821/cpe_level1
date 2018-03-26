//(CPE10424, UVA10221)
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

#define Earth_radius 6440
#define PI acos(0.0)*2          //獲取精確PI，因cos(PI/2)=0，所以PI=acos(0.0)*2
int main()
{
    double distance=0,angle=0;
    string min_deg;

    while(cin>>distance>>angle>>min_deg)
    {
        if(min_deg=="min")      //角分轉角度
            angle/=(float)60;

        if(angle>180)           //鈍角轉銳角
            angle=360-angle;

        double R=Earth_radius+distance;     //實際半徑，地球半徑+衛星高度
        double angle_radian=(float)angle*PI/180;    //角度轉弧度，因math.h中cos要以弧度為輸入單位
        double cos_angle=cos(angle_radian);

        double output1=R*angle_radian;      //弧長=半徑*弧度
        double output2=R*pow((2*(1-cos_angle)),0.5);  //a^2 + b^2 - 2*a*b*cos(angle) = c^2 ，c為所求，餘弦定理

        cout<<fixed<<setprecision(6)<<output1<<" "<<fixed<<setprecision(6)<<output2<<endl;  //取到小數以下六位
    }
}
