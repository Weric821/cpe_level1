//(CPE10461, UVA10931)
#include<iostream>
#include<sstream>
#include<bitset>
using namespace std;

int main()
{
    long long int input=1;
    while(cin>>input && input!=0)
    {
        stringstream ss;
        string output_str;
        ss<<bitset<35>(input);  //將input以二進位輸出成string，總bits數為35bits
        ss>>output_str;
        ss.clear();

        int output=0;   //紀錄二進位總共1的個數
        int flag=0;     //output_str第一個1出現後flag=1，保存有效位元
        for(int i=0;i<output_str.size();i++)
        {
            if(output_str[i]=='1')
            {
                output++;
                flag=1;
            }
            if(flag==1)
                ss<<output_str[i];
        }
        ss>>output_str;

        cout<<"The parity of "<<output_str<<" is "<<output<<" (mod 2)."<<endl;
    }
}
