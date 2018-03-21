//(CPE10517, UVA10050)
#include<iostream>
#include<set>
using namespace std;

int main()
{
   int case_number=0;
   cin>>case_number;

   while(case_number--)
   {
       int days=0,numbers=0,input=0;
       cin>>days>>numbers;

       set<int> st;    //運用set會除去重複數字的性質來排除重複計算同一天的問題

       for(int i=0;i<numbers;i++)
       {
            cin>>input;
            for(int i=2,tmp=input ; tmp<=days ; i++)
            {
                if(tmp%7!=0 && tmp%7!=6)    //no hartals on weekly holidays
                    st.insert(tmp);
                tmp=input*i;
            }
       }
       cout<<st.size()<<endl;
   }
}
