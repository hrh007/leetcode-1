#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        string::size_type len=s.size();
        if(len<=10)
            return res;
        string::size_type first=0;
        string::size_type last=0;
        string temp;
        vector<string>::iterator ite;
        for(string::size_type i=0; i+10<len; i++)
        {
            temp=s.substr(i,10);
            first=s.find(temp);
            if(first!=string::npos)
            {
                last=s.find(temp,first+1);
                if(last!=string::npos)
                {
                    ite=find(res.begin(),res.end(),temp);
                    if(ite==res.end())
                        res.push_back(temp);
                }
            }

        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res=s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
