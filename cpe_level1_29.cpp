//(CPE10466, UVA11005)
#include<iostream>
#include<map>
using namespace std;

//要將十進位數字轉成2~36進位的數字，看在哪個進位表示出來的數字墨水花費最少
int main()
{
   int input_casenumber=0;  //case數目
   cin>>input_casenumber;

   for(int casenumber=1;casenumber<=input_casenumber;casenumber++)
   {
       cout<<"Case "<<casenumber<<":"<<endl;
       int arr[36]={0};     //存放0~9、A~Z墨水花費各為多少
       for(int i=0;i<36;i++)
            cin>>arr[i];

       int inputnumber=0;   //在此墨水花費表下，有幾組數字要計算
       cin>>inputnumber;

       while(inputnumber--)
       {
           long long int input=0;

           cin>>input;

           multimap<int,int> mp;
           multimap<int,int>::iterator iter;

           //tmp=input，把tmp轉成i進位，且以sum計算總墨水花費，並且存入multimap
           for(int i=2,tmp=input ; i<=36 ; i++,tmp=input)
           {
               int sum=0;
               while(tmp>0)
               {
                   sum+=arr[tmp%i];
                   tmp/=i;
               }
               mp.insert(make_pair(sum,i));
           }
           cout<<"Cheapest base(s) for number "<<input<<": ";

           //有可能有多組解，一樣都為最少花費的都要輸出
           for(iter=mp.begin() ; iter!=mp.end() && iter->first==mp.begin()->first ; iter++)
           {
               if(iter!=mp.begin())
                   cout<<" "<<iter->second;
               else
                   cout<<iter->second;
           }
           cout<<endl;
       }
       if(casenumber!=input_casenumber) //case之間要多加一列空白列
           cout<<endl;
   }
}
