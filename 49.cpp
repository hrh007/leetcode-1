#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    vector<string> anagrams(vector<string>& strs)
    {
        vector<string> res;
        int len=strs.size();
        map<string,int> temp;
        map<string,int>::iterator ite;
        string temp_str;
        for(int i=0;i<len;i++)
        {
            temp_str=strs[i];
            sort(temp_str.begin(),temp_str.end());
            ite=temp.find(temp_str);
            if(ite==temp.end())
                temp.insert(pair<string,int>(temp_str,i));
            else
                {
                    if(ite->second>=0)
                        {
                             res.push_back(strs[ite->second]);
                             res.push_back(strs[i]);
                            ite->second=-1;
                        }
                    else
                    res.push_back(strs[i]);
                }
        }

        return res;
    }
};
int main()
{
    vector<string> temp;
    temp.push_back("tea");
    temp.push_back("and");
    temp.push_back("ate");
    temp.push_back("eat");
    temp.push_back("den");
    Solution s;
    vector<string> res=s.anagrams(temp);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
