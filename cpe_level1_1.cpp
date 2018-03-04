//(CPE10406, UVA10041)
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    int total_case=0;

    cin>>total_case;        //input case number
    while(total_case--)
    {
        int number_input=0;
        int output[2]={0};

        cin>>number_input;      //first number in front is total number in one case
        int *arr=new int[number_input];

        for(int i=0;i<number_input;i++)
        {
             cin>>arr[i];
        }

        sort(arr,arr+number_input-1);   //find median

        for(int i=0;i<number_input;i++)
        {
             output[0]+=abs(arr[number_input/2-1]-arr[i]);
             output[1]+=abs(arr[number_input/2]-arr[i]);
        }

        cout<<min(output[0],output[1])<<endl;
    }
}
