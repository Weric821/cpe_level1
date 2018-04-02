//(CPE10409, UVA10057)
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int input=0;
    while(cin>>input)
    {
        int *arr=new int [input];
        for(int i=0; i<input ; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+input);       //將輸入排序

        int output[2][2];          //存入中位數與它出現的次數，偶數時可能有兩個可能的中位數
        output[0][0]=arr[(input-1)/2];
        output[1][0]=arr[input/2];

        for(int i=0 , COUNT_1=0 , COUNT_2=0; i<input ; i++ , output[0][1] = COUNT_1 ,  output[1][1] = COUNT_2)
        {
            //COUNT計算中位數出現次數
            if(arr[i]==output[0][0])
                COUNT_1++;
            if(arr[i]==output[1][0])
                COUNT_2++;
        }

        if(output[0][0]==output[1][0])      //若為單一中位數
            cout<<output[0][0]<<" "<<output[0][1]<<" ";
        else if(output[0][1]>output[1][1])  //若有兩個中位數，且前面的數出現次數多，總合距離短
            cout<<output[0][0]<<" "<<output[0][1]<<" ";
        else if(output[0][1]<output[1][1])  //若有兩個中位數，且後面的數出現次數多，總合距離短
            cout<<output[1][0]<<" "<<output[1][1]<<" ";
        else                        //若有兩個中位數，且兩個出現次數一樣多，選誰總合距離都一樣
            cout<<output[0][0]<<" "<<output[0][1]+output[1][1]<<" ";
        cout<<abs(output[0][0]-output[1][0])+1<<endl;
    }
}
