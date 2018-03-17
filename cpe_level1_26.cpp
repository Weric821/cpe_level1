//(CPE10401, UVA948)
#include<iostream>
#include<sstream>
#include<map>
using namespace std;

int main()
{
    map<int,int> fib;
    map<int,int>::iterator iter;

    //先以map建立fib列表
    //題目上fib[0]、fib[1]不列入顯示
    fib[2]=1;
    fib[3]=2;
    for(int i=4;fib[i-2]+fib[i-1]<=100000000;i++)
        fib[i]=fib[i-2]+fib[i-1];

    int inputcase=0;    //輸入資料筆數
    cin>>inputcase;
    while(inputcase--)
    {
        long long int input_number=0;
        cin>>input_number;

        int flag=0;     //當有第一個1出現時才開始要補0到中間
        cout<<input_number<<" = ";
        stringstream ss;

        //map iterator 時fib.end()並非存資料，故在計算前先將iter--
        for(iter=fib.end();iter!=fib.begin();)
        {
            iter--;
            if(input_number>=iter->second)
            {
                input_number-=iter->second;
                ss<<1;
                flag=1;
            }
            else
            {
                if(flag==1)     //前面有1，後面如果沒有符合的位元要補0
                    ss<<0;
            }
        }

        string output;
        ss>>output;
        cout<<output<<" (fib)"<<endl;
    }
}
