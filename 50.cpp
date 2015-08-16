#include  <iostream>

using namespace std;

class Solution
{
public:

    double cal(double x,int n)
    {
        if(n==1)
            return x;
        else if(n==0)
            return 1;
        else
        {
            int mid=n/2;
            double res=cal(x,mid);
            if(n%2==0)
            {
                return res*res;
            }
            else
            {
                return res*res*x;
            }
        }
    }
    double myPow(double x, int n)
    {
        if(n==0)
            return 1;
        else if(n>0)
        {
            return cal(x,n);
        }
        else
        {
            n=-n;
            return 1.0/cal(x,n);
        }
    }
};

int main()
{
    double x=8.88023;
    Solution s;
    cout<<s.myPow(x,3)<<endl;
    return 0;
}
