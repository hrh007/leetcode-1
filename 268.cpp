#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=nums.size();
        int res=(1+sum)*sum/2;
        for(int i=0;i<sum;++i)
            res-=nums[i];
        return res;
    }
};

int main()
{
    vector<int> temp;
    temp.push_back(4);
    temp.push_back(3);
    temp.push_back(2);
    temp.push_back(0);
    Solution s;
    cout<<s.missingNumber(temp)<<endl;
    return 0;
}
