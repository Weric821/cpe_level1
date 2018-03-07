//(CPE10405, UVA10038)
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int main()
{
    int number=0;
    while(cin>>number)
    {
        int *input_arr=new int [number];
        set <int> st;
        set <int>::iterator iter;

        //get input sequence & calculate the difference between successive elements
        for(int i=0;i<number;i++)
        {
            cin>>input_arr[i];
            if(i>=1)
               st.insert(abs(input_arr[i]-input_arr[i-1]));
        }

        int COUNT=1;
        for(iter=st.begin();iter!=st.end();iter++)
        {
            if(*iter!=COUNT)
            {
                COUNT=-1;
                break;
            }
            COUNT++;
        }

        if(COUNT==-1)
            cout<<"Not jolly"<<endl;
        else
            cout<<"Jolly"<<endl;
    }
}
