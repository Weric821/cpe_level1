//(CPE10410, UVA10062)
#include<iostream>
#include<map>
using namespace std;
int main()
{
    string input;
    int flag=0;

    while(getline(cin,input))
    {
        map<int,int> mp;
        multimap<int,int> mp2;
        map<int,int>::iterator iter;
        multimap<int,int>::iterator iter2;
        //此題先依據頻率由小到大排序，再依據ascii由大到小排序
        for(int i=0;i<input.size();i++)
            mp[(-1)*input[i]]++;            //以ascii由大到小排序
        for(iter=mp.begin();iter!=mp.end();iter++)
            mp2.insert(make_pair(iter->second,iter->first));    //由頻率由小到大排序

        if(flag!=0)
            cout<<endl;
        for(iter2=mp2.begin();iter2!=mp2.end();iter2++)
            cout<<(-1)*iter2->second<<" "<<iter2->first<<endl;

        flag=1;
    }
}
