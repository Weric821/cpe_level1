//(CPE10408, UVA10056)
#include<iostream>
#include<math.h>
#include<set>
#include<iomanip>
using namespace std;

void game(int nubmer_of_players,float win_rate,int winner)
{
    float reg=1.0-pow((1.0-win_rate),nubmer_of_players);
    //分母為0時要特別處理
    if(reg!=0.0)
        cout<<fixed<<setprecision(4)<<(pow((1.0-win_rate),winner-1.0)*win_rate)/reg<<endl;
    else
        cout<<fixed <<setprecision(4)<<0.0<<endl;
    //fixed <<setprecision(4)，讓小數點後固定4位
}
int main()
{
    int case_nubmer=0;
    cin>>case_nubmer;
    while(case_nubmer--)
    {
        int player,win=0;
        float win_rate=0.0;
        float output=0.0;
        cin>>player>>win_rate>>win;
        game(player,win_rate,win);
    }
}
