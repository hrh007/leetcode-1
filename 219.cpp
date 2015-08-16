#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    multimap<int,int> mmap;
    int len=nums.size();
    if(len<2)
        return false;
    map<int,int>::iterator ite;
    for(int i=0;i<len;i++)
    {
        ite=mmap.find(nums[i]);
        if(ite==mmap.end())
        {
            mmap.insert(pair<int,int>(nums[i],i));
        }
        else
        {
            if(i-ite->second<=k)
                return true;
            else
                ite->second=i;
        }
    }
    return false;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    Solution s;
    cout<<s.containsNearbyDuplicate(nums,1)<<endl;
    return 0;
}
