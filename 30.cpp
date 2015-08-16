#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution
{
public:

    bool judge(string s,map<string,int> m,int len_t)
    {
        int len=s.size();
        string temp;
        int count=0;
        for(int i=0; i+len_t<=len;)
        {
            temp=s.substr(i,len_t);
            if(m.find(temp)==m.end())
                return false;
            else
            {
                if(m[temp]>1)
                    --m[temp];
                else
                    m.erase(temp);

            }
            i+=len_t;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        int sum_words=words.size();
        if(sum_words==0)
            return res;
        int len_s=s.size();
        int len_word=words[0].size();
        if(len_s<len_word)
            return res;
        string temp;
        map<string,int> m1;
        set<string> result;
        for(int i=0; i<sum_words; i++)
        {
            if(m1.find(words[i])==m1.end())
                m1.insert(pair<string,int>(words[i],1));
            else
                ++m1[words[i]];
        }
        queue<string> substrings;
        int i=0;
        for(i=0; i+sum_words*len_word<=len_s; i++)
        {
            temp=s.substr(i,sum_words*len_word);
            if(result.find(temp)!=result.end())
                res.push_back(i);
            else
            {
                if(judge(temp,m1,len_word))
                {
                    res.push_back(i);
                    result.insert(temp);
                    //break;
                }
            }
        }
      //  cout<<temp<<endl;
        return res;
    }
};

int main()
{
    string ss="barfoothefoobarman";
    string t1="foo";
    string t2="bar";
    vector<string> temp;
    temp.push_back(t1);
    temp.push_back(t2);
    Solution s;
    vector<int> res=s.findSubstring(ss,temp);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
