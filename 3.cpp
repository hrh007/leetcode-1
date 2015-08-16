#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len=s.size();
        if(len==0)
            return 0;
        int nums[256];
        memset(nums,-1,sizeof(nums));
        int start=0;
        int res=0;
        for(int i=0; i<len; i++)
        {

            if(nums[s[i]]>=start)
                start=nums[s[i]]+1;
            if(i-start+1>res)
                res=i-start+1;
            nums[s[i]]=i;
        }
        return res;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len=s.size();
        if(len==0)
            return 0;
        string substring;
        string temp;
        int res=0;
        int count=0;
        int ite_substring;
        for(int i=0; i<len; i++)
        {
            ite_substring=substring.find(s[i]);
            if(ite_substring==string::npos)
            {
                substring+=s[i];
                count++;
                if(count>res)
                    res=count;
            }
            else
            {
                substring.erase(0,ite_substring+1);
                substring+=s[i];
                count=substring.size();
            }
        }
        return res;
    }
};

int main()
{
    string s="bpfbhmipx";
    Solution ss;
    cout<<ss.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
