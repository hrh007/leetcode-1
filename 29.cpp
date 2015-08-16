#include <iostream>

using namespace std;


class Solution
{
public:

    int cal(long long dividend,long long divisor)
    {
        if(dividend<divisor)
            return 0;
        else if(dividend<(divisor<<1))
            return 1;
        else
        {
            long long temp=divisor;
            temp<<=1;
            int res=1;
            while(temp<dividend)
            {
                res<<=1;
                temp<<=1;
            }
            temp>>=1;
            return res+cal(dividend-temp,divisor);
        }
    }

    int divide(int dividend, int divisor)
    {
        long long x =static_cast<long long> (dividend);
        long long y=static_cast<long long> (divisor);
        if(x==0)
            return 0;
        else if(x>0&&y>0)
            return cal(x,y);
        else if(x>0&&y<0)
            return -cal(x,-y);
        else if(x<0&&y>0)
            return -cal(-x,y);
        else
        {
            return cal(-x,-y);
        }
    }
};

int main()
{

    Solution s;
    cout<<s.divide(-1010369383, -2147483648)<<endl;
    return 0;
}
