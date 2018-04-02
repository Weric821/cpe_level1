//(CPE10566, UVA10242)
#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
    double arr[8]={0};  //接收每筆輸入
    while(cin>>arr[0])
    {
        multimap<double,double> mp;     //因為沒有說明哪組點會重複，故用multimap排序後，讓重複點排在一起
        multimap<double,double>::iterator iter;
        multimap<double,double>::iterator iter2;
        for(int i=1;i<8;i++)
            cin>>arr[i];

        for(int i=0;i<8;i+=2)
            mp.insert(make_pair(arr[i],arr[i+1]));

        double last[2]={10001.0};  //記錄上一組點的值為何
        long double output[2]={0.0};
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            if(iter->first==last[0]&&iter->second==last[1]) //若此組為重複點
            {
                for(iter2=mp.begin();iter2!=mp.end();iter2++)
                {
                    if(iter2->first!=iter->first || iter2->second!=iter->second)
                    {
                         output[0]+=iter2->first;   //非重複點相加
                         output[1]+=iter2->second;
                    }
                    else
                    {
                        output[0]-=iter2->first;    //扣掉重複的點座標
                        output[1]-=iter2->second;
                    }
                }
                output[0]+=iter->first;     //因為在multimap有存兩次重複點座標，故多扣一次，要加回來
                output[1]+=iter->second;
                break;
            }
            last[0]=iter->first;
            last[1]=iter->second;
        }
        cout<<fixed<<setprecision(3)<<output[0]<<" "<<output[1]<<endl;
    }
}
