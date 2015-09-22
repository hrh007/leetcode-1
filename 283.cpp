#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int len=nums.size();
        for(int i=0; i<len; ++i)
        {
            if(nums[i]==0)
            {
                int j=i;
                ++j;
                while(j<len&&nums[j]==0)
                    ++j;
                if(j<len)
                {
                    nums[i]=nums[j];
                    nums[j]=0;
                }
            }
        }
    }
};

int main()
{

    return 0;
}
