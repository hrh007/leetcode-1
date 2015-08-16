#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    int len=nums.size();
    int minNum=nums[0];
    int left=1;
    int right=len-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]>minNum)
            left=mid+1;
        else if(nums[mid]<=minNum)
        {
            right=mid-1;
            minNum=nums[mid];
        }
    }
    return minNum;
    }
};

int main()
{
    vector<int> test;
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(0);
    Solution s;
    cout<<s.findMin(test)<<endl;
    return 0;
}
