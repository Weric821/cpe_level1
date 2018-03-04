//(CPE10414, UVA10101)
#include<iostream>
#include<stack>

using namespace std;

string arr1[4]={"shata","hajar","lakh","kuti"};
int arr2[4]={100,10,100,100};
int main()
{
    long long int input=0;
    while(cin>>input)
    {
        stack <int> sk;
        stack <string> sk2;
        int control=0;
        while(1)
        {
            sk.push(input%arr2[control%4]);
            if(control==0)
                sk2.push("");
            else
                sk2.push(arr1[(control-1)%4]);
            input/=arr2[control%4];

            if(input==0)
                break;
            control++;
        }
        control=0;
        while(1)
        {
            if(sk.top()!=0)
                cout<<sk.top()<<" "<<sk2.top();
            else
            {
                if(sk2.top()=="kuti")
                    cout<<sk2.top();
            }

            sk.pop();
            sk2.pop();
            control++;
            if(sk.empty())
                break;
            else
            {
                if(sk.top()!=0||sk2.top()=="kuti")
                    cout<<" ";
            }
        }
        cout<<endl;
    }
}
