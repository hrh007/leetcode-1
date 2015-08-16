#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int sum=nums.size();
        vector<int> res;
        if(sum==0)
            return res;
        deque<int> temp;
        temp.push_back(0);
        for(int i=1; i<k; ++i)
        {
            if(nums[i]>nums[temp.front()])
            {
                temp.clear();
                temp.push_back(i);
            }
            else if(nums[i]>nums[temp.back()])
            {
                while(nums[i]>nums[temp.back()])
                    temp.pop_back();
                temp.push_back(i);
            }
            else
                temp.push_back(i);
        }
        res.push_back(nums[temp.front()]);
        for(int i=k;i<sum;++i)
        {
            if(i-temp.front()<k)
            {
                if(nums[i]>nums[temp.front()])
                {
                    temp.clear();
                    temp.push_back(i);
                }
                else if(nums[i]>nums[temp.back()])
                {
                    while(nums[i]>nums[temp.back()])
                        temp.pop_back();
                    temp.push_back(i);
                }
                else
                    temp.push_back(i);
            }
            else
            {
                temp.pop_front();
                while(!temp.empty()&&nums[i]>nums[temp.back()])
                    temp.pop_back();
                temp.push_back(i);
            }
             res.push_back(nums[temp.front()]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(-1);
    temp.push_back(-3);
    temp.push_back(5);
    temp.push_back(3);
    temp.push_back(6);
    temp.push_back(7);
    vector<int> res=s.maxSlidingWindow(temp,3);
    cout<<endl;
    for(int i=0;i<res.size();++i)
        cout<<res[i]<<endl;
    return 0;
}
