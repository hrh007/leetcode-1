#include <iostream>
#include <string>

using namespace std;


class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int len1=s.size();
        int len2=p.size();
        if(len1==0&&len2==0)
            return true;
        else if(len1==0)
        {
            int i=0;
            while(i<len2)
            {
                if(p[i]!='*')
                    return false;
                else
                    ++i;
            }
            return true;
        }
        else if(len2==0)
            return false;
        else
        {
            int i=0;
            int j=0;
            int pos_s=-1;
            int pos_p=-1;
            while(i<len1)
            {
                if(j<len2&&(s[i]==p[j]||p[j]=='?'))
                {
                    ++i;
                    ++j;
                }
                else if(j<len2&&p[j]=='*')
                {
                    pos_s=i;
                    pos_p=j;
                    ++j;
                }
                else if(pos_p!=-1)
                {
                    i=++pos_s;
                    j=pos_p+1;
                    // ++pos_s;
                }
                else
                    return false;
            }
            while(j<len2&&(p[j]=='*'))
                ++j;
            if(j==len2)
                return true;
            else
                return false;
        }
    }
};

int main()
{
    string s1("abefcdgiescdfimde");
    string s2("ab*cd?i*de");
    Solution s;
    cout<<s.isMatch(s1,s2);
    return 0;
}
