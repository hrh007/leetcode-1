#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:

    bool compare(string s1,string s2)
    {
        int len=s1.size();
        int count=0;
        for(int i=0; i<len; i++)
        {
            if(s1[i]!=s2[i])
                count++;
            if(count==2)
                return false;
        }
        return true;
    }

    void Find(string start,string end, unordered_set<string> &dict,unordered_map<string,unordered_set<string> > &maps,int s)
    {
        int count=0;
        unordered_set<string> temp;
        if(maps.size()==0)
        {
            for(unordered_set<string>::iterator ite=dict.begin(); ite!=dict.end(); ite++)
                if(compare(*ite,end))
                {
                    count++;
                    temp.clear();
                    temp.insert(end);
                    temp.insert(*ite);
                    maps.insert(pair<string,unordered_set<string> >(*ite,temp));
                }

        }
        else
        {
           for(unordered_set<string>::iterator ite=dict.begin();ite!=dict.end();ite++)
           {
               for(unordered_map<string,unordered_set<string> >::iterator ite2=maps.begin();ite2!=maps.end();ite2++)
               {
                   if(compare(*ite,ite2->first)&&find(ite2->second.begin(),ite2->second.end(),*ite)==ite2->second.end())
                   {
                      temp.clear();
                      temp=ite2->second;
                      temp. insert(*ite);
                      maps.insert(pair<string,unordered_set<string> >(*ite,temp));
                      count++;
                   }
               }
           }
        }
        for(unordered_map<string,unordered_set<string> >::iterator ite2=maps.begin();ite2!=maps.end();ite2++)
        {

        }
        Find(start,end,dict,maps,maps.size()-count);
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {
        int len=dict.size();
        int maxLen=len;
        vector<string> temp;
        vector<vector<string> > res;
        unordered_map<string ,vector<string>> maps;
        Find(start,end,dict,maps,0);
        return res;
    }
};

int main()
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    // for(unordered_set<string>::iterator ite=dict.begin();ite!=dict.end();ite++)
    //  {
    //    cout<<"   "<<*ite;
    //  }
    // cout<<endl;
    Solution s;
    vector<vector<string> >res=s.findLadders("hit","cog",dict);

    //  cout<<"____________________________"<<endl;
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<"   "<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}
