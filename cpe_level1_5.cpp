//(CPE10460, UVA10929)
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
   string input;
   while(cin>>input&&(input!="0"))
   {
       long long int number1=0;
       long long int number2=0;

       for(int i=0;i<input.size();i++)
       {
            if(i%2==0)
                number1+=(input[i]-'0');
            else
                number2+=(input[i]-'0');
       }

       long long int output=abs(number1-number2);

       if(output%11==0)
            cout<<input<<" is a multiple of 11."<<endl;
       else
            cout<<input<<" is not a multiple of 11."<<endl;
   }
}
