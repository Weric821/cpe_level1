//(CPE10404, UVA10035)
#include<iostream>
#include<cmath>

using namespace std;
int main()
{
   long long int number1,number2=0;

   while(cin>>number1>>number2&&(number1!=0||number2!=0))
   {
       int output=0;
       int carry=0;
       while(number1>0||number2>0)
       {
            if((number1%10+number2%10+carry)>9)
            {
                 carry=1;
                 output++;
            }
            else
                 carry=0;
            number1/=10;
            number2/=10;
       }
       if(output==0)
            cout<<"No carry operation."<<endl;
       else if(output==1)
            cout<<output<<" carry operation."<<endl;
       else
            cout<<output<<" carry operations."<<endl;
   }
}
