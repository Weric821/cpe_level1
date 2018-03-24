//(CPE10458, UVA10922)
#include<iostream>
#include<sstream>
using namespace std;

int nine_degree(string number,int COUNT)
{
    long long int tmp=0;
    COUNT++;    //計算the depth of the recursion
    for(int i=0;i<number.size();i++)    //所有位數相加
    {
        tmp+=(number[i]-'0');
    }

    stringstream ss;
    if(tmp<10)  //若小於10判斷是否為9的倍數
    {
        if(tmp%9==0)
            return COUNT;
        else
            return -1;
    }
    else
    {
        ss<<tmp;
       return nine_degree(ss.str(),COUNT);
    }
}
int main()
{
    string input;
    while(cin>>input && (input!="0"))
    {
        int output=nine_degree(input,0);
        if(output!=-1)
            cout<<input<<" is a multiple of 9 and has 9-degree "<<output<<"."<<endl;
        else
            cout<<input<<" is not a multiple of 9."<<endl;
    }
}
