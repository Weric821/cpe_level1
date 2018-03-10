//(CPE10431, UVA10268)
#include<iostream>
#include<sstream>
#include<stack>
#include<math.h>
using namespace std;

int main()
{
    int x=0;
    while(cin>>x)
    {
        string input;
        getline(cin,input); //接收cin後面的換行字元
        getline(cin,input); //實際係數接收

        stringstream ss;    //將input由string轉成一個一個int系數，並丟入stack
        ss<<input;
        stack<int> sk;
        int reg=0;
        while(!ss.eof())
        {
            ss>>reg;
            sk.push(reg);
        }
        long long int output=0;       //輸出
        int COUNT=0;        //計數x的指數次方
        while(!sk.empty())
        {
            //計算x的指數-1次方為多少
            long long int x_exponent=1;
            for(int i=0;i<COUNT-1;i++)
                x_exponent*=x;

            //每一項微分之後帶入x進行運算
            output+=COUNT*sk.top()*x_exponent;
            sk.pop();
            COUNT++;
        }
        cout<<output<<endl;
    }
}
