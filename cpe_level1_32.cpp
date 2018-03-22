//(CPE10419, UVA10190)
#include<iostream>
#include<set>
using namespace std;

int main()
{
   int input1=0,input2=0,final_number=1;

   while(cin>>input1>>input2)
   {
        set<int> st;
        set<int>::iterator iter;

        while(input1>1 && input2!=0)
        {
            st.insert((-1)*input1);     //st由小排到大，故*(-1)反向排序，最後輸出再*(-1)即為由大排到小
            final_number=input1%input2; //紀錄input1是否為input2的倍數
            if(final_number!=0)         //若不是則Boring
                break;
            input1/=input2;
        }
        st.insert((-1)*input1);         //最後的1插入set中

        if(final_number!=0)
             cout<<"Boring!"<<endl;
        else
        {
            for(iter=st.begin();iter!=st.end();iter++)
            {
                if(iter!=st.begin())
                    cout<<" "<<*iter*(-1);
                else
                    cout<<*iter*(-1);
            }
            cout<<endl;
        }
        final_number=1;     //初始化
   }
}
