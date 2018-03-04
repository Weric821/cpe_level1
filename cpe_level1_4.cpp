//(CPE10400, UVA100)
#include<iostream>

using namespace std;
void n3add1(int i,int j,int output)
{
    if(i>j)
    {
        n3add1(j,i,output);
    }
    else
    {
        for(int start=i;start<=j;start++)
        {
            long long int reg=start;
            int Count=0;
            while(reg!=1)
            {
                if(reg%2==1)
                    reg=(reg)*3+1;
                else
                    reg/=2;
                Count++;
            }
            Count++;
            output=max(Count,output);
        }
        cout<<i<<" "<<j<<" "<<output<<endl;
    }
}
int main()
{
   int number1,number2=0;
   while(cin>>number1>>number2)
       n3add1(number1,number2,0);
}
