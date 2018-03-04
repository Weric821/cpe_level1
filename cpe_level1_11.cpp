//(CPE10567, UVA10252)
#include<iostream>
#include<map>
using namespace std;

int main()
{
    string input1,input2;
    while(getline(cin,input1))
    {
        getline(cin,input2);

        //declare
        multimap<char,int> mp1;
        multimap<char,int>::iterator mp1_iter;
        multimap<char,int> mp2;
        multimap<char,int>::iterator mp2_iter;
        multimap<char,int> mp_output;
        multimap<char,int>::iterator mp_output_iter;

        //initial
        for(int i=0;i<input1.size();i++)
            mp1.insert(make_pair(input1[i],1));
        for(int i=0;i<input2.size();i++)
            mp2.insert(make_pair(input2[i],1));

        mp1_iter=mp1.begin();
        mp2_iter=mp2.begin();

        while((mp1_iter!=mp1.end())||(mp2_iter!=mp2.end()))
        {
            if(mp1_iter->first==mp2_iter->first)
            {
                mp_output.insert(make_pair(mp1_iter->first,1));
                mp1_iter++;
                mp2_iter++;
            }
            else if((mp1_iter->first>mp2_iter->first)&&mp2_iter!=mp2.end())
                mp2_iter++;
            else if((mp1_iter->first<mp2_iter->first)&&mp1_iter!=mp1.end())
                mp1_iter++;
            else
            {
                if(mp1_iter==mp1.end())
                    mp2_iter++;
                else
                    mp1_iter++;
            }
        }

        for(mp_output_iter=mp_output.begin();mp_output_iter!=mp_output.end();mp_output_iter++)
            cout<<mp_output_iter->first;
        cout<<endl;
    }
}
