//(CPE10413, UVA10093)
#include<iostream>
#include<fstream>
using namespace std;

string arr="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
long long int power(int x,int n)    //計算x的n次方
{
    long long int output=1;
    for(int i=0;i<n;i++)
        output*=x;
    return output;
}
int main()
{
    string input;
    while(cin>>input)
    {
        int MAX=-1;     //記下input中最大的字元
        for(int i=0;i<input.size();i++)
        {
            if(arr.find(input[i])<arr.size())   //判斷input中最大的數字為多少，base必大於其
                MAX=max(MAX,(int)arr.find(input[i]));
            else
            {
                MAX=-1;
                break;
            }
        }
        MAX++;

        while(MAX!=-1&&MAX<=arr.size())
        {
            long long int SUM=0;
            long long int reg=0;

            //計算input在以MAX為base情況下的十進位值為多少，最後存到SUM
            for(int i=0;i<input.size();i++)
            {
                reg=power(MAX,input.size()-1-i);
                SUM+=arr.find(input[i])*reg;
            }

            if(SUM%(MAX-1)==0)  //SUM要能整除於base-1
                break;
            else
                MAX++;
        }

        if(MAX>0&&MAX<=arr.size())
            cout<<MAX<<endl;
        else    //若沒有符合base或有例外字元，則MAX==0
            cout<<"such number is impossible!"<<endl;
    }
}
