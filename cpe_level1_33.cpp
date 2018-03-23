//(CPE10428, UVA10235)
#include<iostream>
#include<sstream>
#include<set>
using namespace std;

int main()
{
    //將質數存到set中，質數只有可能是6n+1或6n-1(排除2、3的倍數)
    set<int> st;
    set<int>::iterator iter;
    st.insert(2);
    st.insert(3);
    for(int i=1;6*i+1<1000000;i++)
    {
        int flag1=0;
        int flag2=0;
        for(iter=st.begin();iter!=st.end();iter++)  //判斷此數是否會被前面的質數整除
        {
            if((6*i+1)%(*iter)==0)
                flag1=1;
            if((6*i-1)%(*iter)==0)
                flag2=1;
            if((*iter)*(*iter)>(6*i+1)) //只需判斷到此數的平方根之前即可，因為可整除就會是前半數字*後半數字，故在前半就會檢查出來
                break;
        }
        if(flag1!=1)
            st.insert(6*i+1);
        if(flag2!=1)
            st.insert(6*i-1);
    }

     long long int input=0;
     while(cin>>input)
     {
         if(st.find(input) == st.end()) //若不再set中，則此數非質數
             cout<<input<<" is not prime."<<endl;
         else
         {
             stringstream ss;
             string tmp;
             long long int inverse_input=0;
             ss<<input;
             ss>>tmp;
             ss.clear();
             for(int i=tmp.size()-1;i>=0;i--)
                ss<<tmp[i];
             ss>>inverse_input;

             if(st.find(inverse_input) != st.end() && input!=inverse_input) //若數字顛倒為質數且與原數不相同，為emirp
                 cout<<input<<" is emirp."<<endl;
             else
                 cout<<input<<" is prime."<<endl;
         }
     }
}
