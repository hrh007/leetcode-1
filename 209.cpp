#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int res=INT_MAX;
        int count=0;
        int len=nums.size();
        if(len==0)
            return 0;
        int i=1;
        int sum=nums[0];
        int start=0;
        while(start!=len-1)
        {
            //start++;
            // sum+=nums[i++];
            while(i<len)
            {
                if(sum>=s)
                    break;
                sum+=nums[i++];
            }
            if(i-start<res&&sum>=s)
            {
                res=i-start;
                count=1;
            }
            sum-=nums[start++];
            //  i++;
        }
        if(count==0)
            return 0;
        else
            return res;
    }
};

int main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);
    //   test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    Solution s;
    cout<<s.minSubArrayLen(6,test)<<endl;
    return 0;
}
