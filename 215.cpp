#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    int len=nums.size();
    sort(nums.begin(),nums.end());
    return nums[len-k];
    }
};

int main()
{

    return 0;
}
