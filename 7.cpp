#include <iostream>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    long long res=0;
    queue<int> temp;
    long long count=1;
    while(x)
    {
        temp.push(x%10);
        x=x/10;
        count*=10;
    }
    count/=10;
    while(!temp.empty())
    {
        res+=temp.front()*count;
        temp.pop();
        count/=10;
    }
    if(x<0)
       res=-res;
    if(res>INT_MAX||res<INT_MIN)
        return 0;
    return res;
    }
};

int main()
{
    int x=0;
    Solution s;
    cout<<s.reverse(x)<<endl;
    return 0;
}
