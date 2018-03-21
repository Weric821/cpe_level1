//(CPE10421, UVA10193)
#include<iostream>
#include<bitset>
using namespace std;
unsigned long GCD(unsigned long a,unsigned long b)  //輾轉相除法求最大公因數
{
    if(b<a)
        GCD(b,a);
    if(a!=0)
        GCD(b%a,a);
    else
        return b;
}
int main()
{
   int case_number=0;
   cin>>case_number;

   for(int i=1;i<=case_number;i++)
   {
       string input1,input2;
       cin>>input1>>input2;

       //將string當成2進位數，並且轉成dec存成unsigned long
       unsigned long input1_dec=bitset<32>(input1).to_ulong();
       unsigned long input2_dec=bitset<32>(input2).to_ulong();

       unsigned long output=GCD(input1_dec,input2_dec);
       if(output!=1)
            cout<<"Pair #"<<i<<": All you need is love!"<<endl;
       else
            cout<<"Pair #"<<i<<": Love is not all you need!"<<endl;
   }
}
