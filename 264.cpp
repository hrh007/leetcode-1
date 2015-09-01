#include <iostream>

using namespace std;

class Solution
{
public:

    int minNum(int x,int y)
    {
        return x<y?x:y;
    }

    int nthUglyNumber(int n)
    {
        if(n==0)
            return 0;
        int *count=new int[n];
        count[0]=1;
        int two=0;
        int three=0;
        int five=0;
        int sum=1;
        int min=0;
        while(sum<n)
        {
            min=minNum(minNum(count[two]*2,count[three]*3),count[five]*5);
            count[sum++]=min;
            if(min==count[two]*2)
                ++two;
            if(min==count[three]*3)
                ++three;
            if(min==count[five]*5)
                ++five;
        }
        return count[sum-1];
    }
};

int main()
{
    Solution s;
    for(int i=1; i<=11; ++i)
        cout<<i<<"   "<<s.nthUglyNumber(i)<<endl;
    return 0;
}
