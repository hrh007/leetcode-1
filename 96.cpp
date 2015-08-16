#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    int count[n+1];
    memset(count,0,sizeof(count));
    count[0]=1;
    count[1]=1;
    int temp=0;
    for(int i=2;i<=n;++i)
    {
        temp=i-1;
        for(int j=temp;j>=0;--j)
        {
            count[i]+=count[temp-j]*count[j];
        }
    }
    return count[n];
    }
};

int main()
{
    Solution s;
    for(int i=0;i<10;++i)
        cout<<s.numTrees(i)<<endl;
    return 0;
}
