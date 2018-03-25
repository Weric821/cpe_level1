//(CPE10456, UVA10908)
#include<iostream>
using namespace std;

//以x,y為中心點，判斷周圍8格是否與中心點的字元相同，若相同回傳0，不相同回傳-1
int check(char **arr,int x,int y,char center,int row,int col)
{
    int flag=0;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            //超出範圍或是周圍有不等同於中心點字元的，直接回傳-1
            if(x+i<0 || y+j<0 || x+i>=row || y+j>=col || arr[x+i][y+j]!=center)
            {
                flag=-1;
                break;
            }
        }
    return flag;
}
int main()
{
    int case_nubmer=0;      //共有幾個case
    cin>>case_nubmer;
    while(case_nubmer--)
    {
        int row=0,col=0,input_line=0;       //輸入矩陣的row、column、幾筆中心點要輸入
        cin>>row>>col>>input_line;
        char **arr=new char*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new char [col];
            for(int j=0;j<col;j++)
                cin>>arr[i][j];
        }

        cout<<row<<" "<<col<<" "<<input_line<<endl;
        while(input_line--)
        {
            int x=0,y=0;
            cin>>x>>y;      //輸入中心點座標
            int output=0;
            int flag=0;
            for(int i=0;i<min(row/2,col/2) && flag!=-1 ; i++ , output=i)    //表示上下左右延伸i格，ex.i=1即邊長為3的正方形
            {
                for(int j=x-i;j<=x+i && flag!=-1;j++)       //將此方形的點都跑過一次，判斷字元是否都與中心點相等
                    for(int k=y-i;k<=y+i;k++)
                    {
                        if(j<0 || k<0 || j>=row || k>=col)  //超出範圍直接結束
                            flag=-1;
                        else
                            flag=check(arr,j,k,arr[x][y],row,col);

                        if(flag==-1)
                            break;
                    }
            }
            cout<<(1+2*(output+flag))<<endl;    //輸出邊長
        }
    }
}
