//(CPE11076, UVA11417)
#include<iostream>
using namespace std;

int GCD(int a,int b)    //輾轉相除法求最大公因數
{
    if(a>b)
        GCD(b,a);
    if(a!=0)
        GCD(b%a,a);
    else
        return b;

}
int main()
{
    int N=0;
    while(cin>>N && (N!=0))
    {
        int G=0;
        for(int i=1;i<N;i++)
            for(int j=i+1;j<=N;j++)
            {
                G+=GCD(i,j);
            }
        cout<<G<<endl;
    }
}
