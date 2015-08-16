#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    int count[n+1];
    count[0]=0;
    count[1]=1;
    count[2]=2;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    for(int i=3;i<=n;++i)
        count[i]=count[i-1]+count[i-2];
    return count[n];
    }
};

int main()
{

    Solution s;
    cout<<s.climbStairs(44)<<endl;
    return 0;
}
