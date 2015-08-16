#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res;
        int sum=nums.size();
        int x=1;
        int sum_zero=0;
        int index=-1;
        for(int i=0; i<sum; ++i)
        {
            if(nums[i]==0)
            {
                ++sum_zero;
                index=i;
            }
        }
        if(sum_zero>1)
        {
            for(int i=0; i<sum; ++i)
                res.push_back(0);
            return res;
        }
        else if(sum_zero==1)
        {
            for(int i=0; i<sum; ++i)
            {
                if(i==index)
                    continue;
                else
                    x*=nums[i];
            }
            for(int i=0; i<sum; ++i)
            {
                if(i==index)
                    res.push_back(x);
                else
                    res.push_back(0);
            }
        }
        else
        {
            for(int i=0; i<sum; ++i)
                x*=nums[i];
            for(int i=0; i<sum; ++i)
                res.push_back(x/nums[i]);
            return res;
        }
    }
};

int main()
{

    return 0;
}
