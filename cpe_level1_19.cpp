//(CPE10453, UVA10783)
#include<iostream>
using namespace std;

int main()
{
    int case_number=0;

    //arr存取前面odd相加累積的值，且往後推延兩格，故arr[3]=1，arr[5]=4
    int arr[103]={0};
    for(int i=3;i<103;i+=2)
    {
        arr[i]=arr[i-2]+(i-2);
    }


    cin>>case_number;
    for(int i=1;i<=case_number;i++)
    {
        int input1,input2=0;
        cin>>input1>>input2;

        input1+=(1-(input1%2));  //若下界為偶數則加一使之變為奇數
        input2-=(1-(input2%2));  //若上界為偶數則減一使之變為奇數

        cout<<"Case "<<i<<": "<<arr[input2+2]-arr[input1]<<endl;
    }
}
