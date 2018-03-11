//(CPE10454, UVA10812)
#include<iostream>
using namespace std;

int main()
{
    int case_number=0;
    cin>>case_number;
    while(case_number--)
    {
        long long int sum,difference=0;
        cin>>sum>>difference;

        //若分數總和小於差值或總和、差值為奇數，則無解
        if(sum-difference<0||(sum-difference)%2==1||(sum+difference)%2==1)
            cout<<"impossible"<<endl;
        else
            cout<<(sum+difference)/2<<" "<<(sum-difference)/2<<endl;
    }
}
