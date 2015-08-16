#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    int len=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<=len/2;i++)
    {
        if(i+1<len&&nums[i]==nums[i+1])
            return true;
        if(len-2-i>=0&&nums[len-1-i]==nums[len-2-i])
            return true;
    }
    return false;
    }
};

int main()
{

    return 0;
}
