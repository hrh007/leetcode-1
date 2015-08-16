#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int min(int x,int y)
    {
        return x<y?x:y;
    }
    int minDistance(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
    if(len1==0)
        return len2;
    if(len2==0)
        return len1;
    int len[len1+1][len2+1];
    memset(len,0,sizeof(len));
    int x=0;
    for(int i=1;i<=len1;++i)
        len[i][0]=i;
    for(int i=1;i<=len2;++i)
        len[0][i]=i;
    for(int i=1;i<=len1;++i)
    {
        for(int j=1;j<=len2;++j)
        {

            if(word1[i-1]==word2[j-1])
            x=0;
            else
            x=1;
            len[i][j]=min(len[i-1][j-1]+x,min(len[i-1][j]+1,len[i][j-1]+1));
        }
    }
    return len[len1][len2];
    }
};

int main()
{

    return 0;
}
