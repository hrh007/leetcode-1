#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    int len=s.size();
    int sum=wordDict.size();
    if(len==0&&sum==0)
        return true;
    else if(len==0||sum==0)
        return false;
    int count[len+1];
    memset(count,0,sizeof(count));
    count[0]=1;
    string temp="";
    for(int i=1;i<=len;++i)
    {
        for(int j=i-1;j>=0;--j)
        {
            temp=s.substr(j,i-j);
            if(count[j]&&wordDict.find(temp)!=wordDict.end())
            {
                count[i]=1;
                break;
            }
        }
    }
    return count[len];
    }
};

int main()
{

    return 0;
}
