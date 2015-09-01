#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    vector<int> res;
    int sum=nums.size();
    if(sum==0)
        return res;
    if(sum<=2)
        return nums;
    int temp=nums[0];
    for(int i=1;i<sum;++i)
        temp^=nums[i];
    int count=0;
    while(1)
    {
        if(temp&1==1)
            break;
        else
        {
            temp>>=1;
            ++count;
        }
    }
    int res1=0;
    int res2=0;
    for(int i=0;i<sum;++i)
    {
        if((nums[i]>>count)&1==1)
            res1^=nums[i];
        else
            res2^=nums[i];
    }
    cout<<res1<<"   "<<res2<<endl;
    res.push_back(res1);
    res.push_back(res2);
    return res;
    }
};

int main()
{
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(2);
    temp.push_back(5);
    Solution s;
    s.singleNumber(temp);
    //temp.push_back();
    return 0;
}
