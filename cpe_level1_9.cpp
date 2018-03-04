//(CPE10425, UVA10222)
#include<iostream>
using namespace std;

string arr="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
    string input;
    getline(cin,input);

    for(int i=0;i<input.size();i++)
    {
        if(input[i]>='A'&&input[i]<='Z')
            input[i]=input[i]-'A'+'a';

        if(input[i]!=' ')
            cout<<arr[arr.find(input[i])-2];
        else
            cout<<" ";
    }
    cout<<endl;
}
