#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;




class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(k<=0||t<0)
        return false;
    int sum=nums.size();
    if(sum<=1)
        return false;
    map<int,int> m;
    int j=0;
    for(int i=0;i<sum;++i)
    {
        if(i-j>k&&m[nums[j]]==j)
            m.erase(nums[j++]);
        map<int,int>::iterator ite=m.lower_bound(nums[i]-t);
        if(ite!=m.end()&&abs(ite->first-nums[i])<=t)
            return true;
        m[nums[i]]=i;
    }
    return false;
    }
};

int main()
{

    return 0;
}
