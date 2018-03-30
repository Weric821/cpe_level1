//(CPE10447, UVA10642)
#include<iostream>
using namespace std;

int main()
{
   int input=0;
   cin>>input;

   for(int j=1;j<=input;j++)
   {
       int x1=0,x2=0,y1=0,y2=0;
       cin>>x1>>y1>>x2>>y2;     //此題目x,y軸跟一般的座標系相反
       long long int length=0;
       length+=((x2+y2)-(x1+y1));   //兩斜線之間有幾條連接線

       for(int i=(x1+y1);i<=(x2+y2);i++)    //每條斜線距離相加
            length+=i;

       length-=x1;    //扣掉頭尾距離
       length-=y2;
       cout<<"Case "<<j<<": "<<length<<endl;
   }
}
