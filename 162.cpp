#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int Find(vector<int> &nums,int left,int right)
    {
        if(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
                    return mid;
            int l=Find(nums,left,mid-1);
            if(l!=-1)
                return l;
            int r=Find(nums,mid+1,right);
            if(r!=-1)
                return r;
            return -1;
        }
        else
        {
            return -1;
        }
    }

    int findPeakElement(vector<int>& nums)
    {
        int left=0;
        int right=nums.size()-1;
        if(right==0)
            return 0;
        else if(nums[1]<nums[0])
            return 0;
        else if(right-1>=0&&nums[right-1]<nums[right])
            return right;
        else
            return Find(nums,1,right-1);

    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    Solution s;
    cout<<s.findPeakElement(test)<<endl;
    return 0;
}
