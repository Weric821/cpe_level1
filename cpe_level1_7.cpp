//(CPE21924, UVA10420)
#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int main()
{
    int input_case=0;
    string reg;
    map <string,int> mp;
    map <string,int>::iterator iter;

    cin>>input_case;
    getline(cin,reg);

    while(input_case--)
    {
        string input;
        stringstream ss;
        getline(cin,input);
        ss<<input;
        ss>>input;
        ss.clear();
        mp[input]++;
    }

    for(iter=mp.begin();iter!=mp.end();iter++)
        cout<<iter->first<<" "<<iter->second<<endl;
}
