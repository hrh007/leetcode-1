#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1=s1.size();
        int len2=s2.size();
        int len3=s3.size();
        if(len1==0)
            return s2==s3;
        if(len2==0)
            return s1==s3;
        if(len1+len2!=len3)
            return false;
        int count[len1+1][len2+1];
        memset(count,0,sizeof(count));
        count[0][0]=1;

       for(int i=1; i<=len1; ++i)
        {
            if(s1[i-1]==s3[i-1])
                count[i][0]=count[i-1][0];
            else
                break;
        }
        for(int j=1; j<=len2; ++j)
        {
            if(s2[j-1]==s3[j-1])
                count[0][j]=count[0][j-1];
            else
                break;
        }
        for(int i=1; i<=len1; ++i)
        {
            for(int j=1; j<=len2; ++j)
            {
                if(s1[i-1]==s3[i+j-1]&&count[i-1][j]==1)
                    count[i][j]=1;
                if(s2[j-1]==s3[i+j-1]&&count[i][j-1]==1)
                    count[i][j]=1;
            }
        }
        return count[len1][len2];
    }
};
int main()
{
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    Solution s;
    cout<<s.isInterleave(s1,s2,s3)<<endl;
    return 0;
}
