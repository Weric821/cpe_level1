//(CPE22801, UVA12019)
#include<iostream>
using namespace std;

const int days[13]={31,28,31,30,31,30,31,31,30,31,30,31};
const string week[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
    int case_number=0;
    cin>>case_number;
    while(case_number--)
    {
        int input1,input2=0;
        cin>>input1>>input2;

        int total=0;
        for(int i=0;i<input1-1;i++)
            total+=days[i];

        total+=input2;
        cout<<week[(total+4)%7]<<endl;
    }
}
