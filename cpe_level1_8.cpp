//(CPE10402, UVA10008)
#include<iostream>
#include<map>
using namespace std;

int main()
{
    int input_line=0;
    cin>>input_line;

    string reg;
    getline(cin,reg);
    map <char,int> mp_sort_with_ascii;
    map <char,int>::iterator mp_sort_with_ascii_iter;
    multimap <int,char> mp_sort_with_vote;
    multimap <int,char>::iterator mp_sort_with_vote_iter;
    while(input_line--)
    {
        string input;
        getline(cin,input);

        for(int i=0;i<input.size();i++)
        {
            if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
            {
                if(input[i]>='a'&&input[i]<='z')
                    mp_sort_with_ascii[input[i]-'a'+'A']++;
                else
                    mp_sort_with_ascii[input[i]]++;
            }
        }
    }
    for(mp_sort_with_ascii_iter=mp_sort_with_ascii.begin();mp_sort_with_ascii_iter!=mp_sort_with_ascii.end();mp_sort_with_ascii_iter++)
        mp_sort_with_vote.insert(make_pair((-1)*mp_sort_with_ascii_iter->second,mp_sort_with_ascii_iter->first));

    for(mp_sort_with_vote_iter=mp_sort_with_vote.begin();mp_sort_with_vote_iter!=mp_sort_with_vote.end();mp_sort_with_vote_iter++)
        cout<<mp_sort_with_vote_iter->second<<" "<<(-1)*mp_sort_with_vote_iter->first<<endl;
}
