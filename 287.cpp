#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow =0;
        int fast =0;
        while(1)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow == fast)
                break;
        }
        fast = 0;
        while(1)
        {
            slow=nums[slow];
            fast=nums[fast];
            if(slow==fast)return slow;
        }

    }
};

class Solution2
{
public:
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int left=0;
        int right=len-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==mid+1)
            {
                left=mid+1;
            }
            else
            {
                if(mid+1<len&&nums[mid+1]==nums[mid])
                    return nums[mid];
                else if(mid-1>=0&&nums[mid-1]==nums[mid])
                    return nums[mid];
                else
                    right=mid-1;
            }
        }
    }
};

int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(5);
    num.push_back(9);
    num.push_back(6);
    num.push_back(9);
    num.push_back(3);
    num.push_back(8);
    num.push_back(9);
    num.push_back(7);
    num.push_back(1);
    Solution s;
    cout<<s.findDuplicate(num)<<endl;
    return 0;
}
