#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> temp=stringTovec(str);
        int len=pattern.size();
        int sum=temp.size();
        map<char,string> m;
        map<string,char> m2;
        int j=0;
        for(int i=0;i<len;++i)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(j<sum&&m[pattern[i]]==temp[j])
                {
                    ++j;
                    continue;
                }
                else
                    return false;
            }
            else if(j<sum)
            {
                m[pattern[i]]=temp[j];
                ++j;
            }
            else
                return false;
        }
        j=0;
        for(int i=0;i<sum;++i)
        {
            if(m2.find(temp[i])!=m2.end())
            {
               if(m2[temp[i]]==pattern[j])
               {
                   ++j;
                   continue;
               }
               else
                return false;
            }
            else if(j<len)
            {
                m2[temp[i]]=pattern[j];
                ++j;
            }
            else
                return false;
        }
        return true;
    }
private:
    vector<string> stringTovec(string s)
    {
        vector<string> res;
        int len=s.size();
        string temp="";
        for(int i=0;i<len;++i)
        {
            if(s[i]==' ')
            {
                res.push_back(temp);
                temp="";
            }
            else
                temp+=s[i];
        }
        res.push_back(temp);
        return res;
    }
};

int main()
{

    return 0;
}
