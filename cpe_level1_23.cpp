//(CPE23621, UVA11063)
#include<iostream>
#include<map>
using namespace std;

int main()
{
    int array_size=0;   //數列幾筆資料
    int Case_count=1;   //計數目前為第幾Case

    while(cin>>array_size)
    {
        int *arr=new int [array_size];
        for(int i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }

        map<int,int> mp;    //以map紀錄兩兩總和出現次數，超過1跳出
        int flag=0;         //若兩兩總和有重複，flag==1
        for(int i=0;i<array_size&&(flag!=1);i++)
        {
            for(int j=i;j<array_size;j++)
            {
                mp[arr[i]+arr[j]]++;
                if(mp[arr[i]+arr[j]]>1)
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1)
            cout<<"Case #"<<Case_count<<": It is not a B2-Sequence."<<endl;
        else
            cout<<"Case #"<<Case_count<<": It is a B2-Sequence."<<endl;

        Case_count++;
        delete[] arr;

        string reg;   //空一列
        getline(cin,reg);
        getline(cin,reg);
    }
}
