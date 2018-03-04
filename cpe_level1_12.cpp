//(CPE21914, UVA490)
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    string input;
    stack<string> sk;
    int COUNT=0;
    int MAX=0;

    //get input and push it into stack
    while(getline(cin,input))
    {
        sk.push(input);
        MAX=max(MAX,(int)(input.size()));
        COUNT++;
    }

    //create an array to store Rotating Sentences
    char **output_array=new char* [MAX];
    for(int i=0;i<MAX;i++)
    {
        output_array[i]=new char [COUNT];
        for(int j=0;j<COUNT;j++)
            output_array[i][j]=' ';
    }

    COUNT=0;
    while(!sk.empty())
    {
        for(int i=0;i<sk.top().size();i++)
            output_array[i][COUNT]=sk.top()[i];

        COUNT++;
        sk.pop();
    }

    //output
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<COUNT;j++)
        {
            if(output_array[i][j]==' ')
            {
                for(int k=j;k<COUNT;k++)
                {
                    //if   : doesn't have anything behind ,then goto next line
                    //else : add one half width blank
                    if(output_array[i][k]!=' ')
                    {
                        cout<<' ';
                        break;
                    }
                }
            }
            else
                cout<<output_array[i][j];
        }
        cout<<endl;
    }
}
