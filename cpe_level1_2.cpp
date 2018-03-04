//(CPE10407, UVA10055)
#include<iostream>
#include<cmath>

using namespace std;
int main()
{
   long long int number1,number2=0;

   while(cin>>number1>>number2)
   {
       long long int output=abs(number1-number2);
       cout<<output<<endl;
   }
}
