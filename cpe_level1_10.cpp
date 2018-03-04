//(CPE10473, UVA11332)
#include<iostream>
using namespace std;

int main()
{
    long long int input=1;
    while(cin>>input&&(input!=0))
    {
        long long int sum_register=0;
        while(input>9)
        {
            while(input>0)
            {
                sum_register+=input%10;
                input/=10;
            }
            input=sum_register;
            sum_register=0;
        }
        cout<<input<<endl;
    }
}
