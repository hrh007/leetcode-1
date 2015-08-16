#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int Find(vector<int> &nums,int left,int right)
    {

        if(left==right)
            return nums[left];

        else
        {
            int min1,min2,min3,min4,mid;
            min1=nums[left];
            mid=(left+right)/2;
            min2=Find(nums,mid+1,right);
            min3=Find(nums,left,mid);
            if(min1<=min2&&min1<=min3)
                return min1;
            if(min3<=min2&&min3<=min1)
                return min3;
            if(min2<=min3&&min2<=min1)
                return min2;
        }
    }

    int findMin(vector<int>& nums)
    {
        return Find(nums,0,nums.size()-1);
    }
};


int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);
    Solution s;
    cout<<s.findMin(test)<<endl;
    return 0;
}
