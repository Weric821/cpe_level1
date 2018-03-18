//(CPE10403, UVA10019)
#include<iostream>
#include<sstream>
#include<bitset>
using namespace std;

int main()
{
    int casenumber=0;
    cin>>casenumber;
    while(casenumber--)
    {
        int input=0;
        cin>>input;

        stringstream ss;
        string b1_dec_string;
        string b2_hex_string;
        int b1=0;
        int b2=0;

        //將10進位轉成17bits的二進位，存成string
        ss<<bitset<17>(input);
        ss>>b1_dec_string;
        ss.clear();

        //先將10進位當成16進位轉換，再將其值存回input
        ss<<input;
        ss>>hex>>input;
        ss.clear();

        //將input轉成17bits的二進位，存成string
        ss<<bitset<17>(input);
        ss>>b2_hex_string;

        //計算兩個string之中各別1的個數
        for(int i=0;i<17;i++)
        {
            if(b1_dec_string[i]=='1')
                b1++;
            if(b2_hex_string[i]=='1')
                b2++;
        }

        cout<<b1<<" "<<b2<<endl;
    }
}
