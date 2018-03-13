//(CPE10480, UVA11461)
#include<iostream>
using namespace std;

int main()
{
    int arr[100001]={0};    //用array存目前平方數個數累加
    for(int i=1;i*i<=100000;i++)    //平方數的位置先填1
        arr[i*i]=1;
    for(int i=1;i<100001;i++)       //累加
        arr[i]=arr[i-1]+arr[i];

    int input1,input2;
    while(cin>>input1>>input2&&(input1!=0||input2!=0))
    {
        cout<<arr[input2]-arr[input1-1]<<endl;
    }
}
