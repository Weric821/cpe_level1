//(CPE10478, UVA11349)
#include<iostream>
using namespace std;

int main()
{
    int case_number=0;
    cin>>case_number;
    for(int test=1;test<=case_number;test++)
    {
        char reg=' ';
        int matrix_size=0;
        //以reg接收'N'、'='兩個字元
        cin>>reg>>reg>>matrix_size;

        long long int **arr=new long long int* [matrix_size];
        int flag=0;   //flag=0則Symmetric，flag=1則Non-symmetric
        for(int i=0;i<matrix_size;i++)
        {
            arr[i]=new long long int [matrix_size];
            for(int j=0;j<matrix_size;j++)
            {
                arr[i][j]=0;
                cin>>arr[i][j];
                if(arr[i][j]<0)  //若元素有負數則Non-symmetric
                    flag=1;
            }
        }

        if(flag!=1)
        {
            for(int i=0;i<matrix_size;i++)
            {
                for(int j=0;j<matrix_size;j++)
                {
                    if(arr[i][j]!=arr[matrix_size-i-1][matrix_size-j-1])    //非以中心點對稱即為Non-symmetric
                        flag=1;
                }
            }
        }

        if(flag==0)
            cout<<"Test #"<<test<<": Symmetric."<<endl;
        else
            cout<<"Test #"<<test<<": Non-symmetric."<<endl;

        delete[] arr;
    }
}
