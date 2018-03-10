//(CPE10417, UVA10170)
#include<iostream>
using namespace std;

int main()
{
    //start:起始人數，days:目標日期
    long long int start,days=0;
    while(cin>>start>>days)
    {
        //n人住n天，計算days天時住著幾人
        //以COUNT計算總天數是否超過days
        long long int COUNT=start;
        while(days>COUNT)
        {
            start++;
            COUNT+=start;
        }
        cout<<start<<endl;
    }
}
