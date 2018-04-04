//(CPE22811, UVA299)
#include<iostream>
using namespace std;
int main()
{
    int case_number=0;
    cin>>case_number;     //總共有幾筆輸入
    while(case_number--)
    {
        int arr_size=0;
        cin>>arr_size;    //要排序陣列的大小
        int *arr=new int [arr_size];
        for(int i=0;i<arr_size;i++)
            cin>>arr[i];

        int output=0;     //統計交換次數
        for(int i=0;i<arr_size;i++)
            for(int j=i+1;j<arr_size;j++)
            {
                if(arr[i]>arr[j])
                {
                    swap(arr[i],arr[j]);
                    output++;
                }
            }

        cout<<"Optimal train swapping takes "<<output<<" swaps."<<endl;
        delete[] arr;
    }
}
