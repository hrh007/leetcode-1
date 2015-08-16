#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int len=nums.size();
    sort(nums.begin(),nums.end());
    int res=1;
    for(int i=0;i<len;i++)
    {
        if(nums[i]>res)
            return res;
        else if(nums[i]==res)
            res++;
        else
            continue;
    }
    return res;

    }
};

int main()
{


    return 0;
}
