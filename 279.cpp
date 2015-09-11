#include <iostream>
#include <cstring>
#include <map>
#include <climits>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int least[n+1];
        memset(least,0,sizeof(least));
        for(int i=1;i<=n;++i)
        {
                least[i]=i;
                for(int j=1;j*j<=i;++j)
                {
                    if(j*j==n)
                        least[i]=1;
                    else
                        least[i]=least[i-j*j]+1<least[i]?least[i-j*j]+1:least[i];
                }
        }
        return least[n];
    }
};


int main()
{
    Solution s;
    for(int i=1;i<14;++i)
    cout<<"    "<<s.numSquares(i)<<endl;
}
