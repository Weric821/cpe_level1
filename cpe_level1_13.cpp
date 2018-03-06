//(CPE22131, UVA272)
#include<iostream>
using namespace std;

int main()
{
    string input;
    int flag=0;
    while(getline(cin,input))
    {
        for(int i=0;i<input.size();i++)
        {
            if(input[i]=='"')
            {
                switch (flag)
                {
                    case 0:
                        cout<<"``"; //first "
                        flag=1;
                        break;
                    case 1:
                        cout<<"''"; //second "
                        flag=0;
                        break;
                }
            }
            else
                cout<<input[i];
        }
        cout<<endl;
    }
}
