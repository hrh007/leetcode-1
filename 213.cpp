#include <iostream>
#include <vector>

using namespace std;

class Temp{
public :
    int value;
    int number;
};

class Solution {
public:
    int cal(vector<int> &nums,int start,int stop)
    {
        Temp count[stop-start+1];
        count[0].value=nums[start];
        count[0].number=start;
        if(nums[start+1]>nums[start])
        {
            count[1].value=nums[start+1];
            count[1].number=start+1;
        }
        else
        {
            count[1].value=nums[start];
            count[1].number=start;
        }

        for(int i=start+2;i<=stop;++i)
        {
            if(count[i-start-1].number!=i-1)
            {
                count[i-start].value=count[i-start-1].value+nums[i];
                count[i-start].number=i;
            }
            else
            {
                if(nums[i]+count[i-start-2].value>count[i-start-1].value)
                {
                    count[i-start].value=nums[i]+count[i-start-2].value;
                    count[i-start].number=i;
                }
                else
                {
                    count[i-start].value=count[i-start-1].value;
                    count[i-start].number=i-start-1;
                }
            }
        }
        return count[stop-start].value;

    }
    int rob(vector<int>& nums) {
        int sum=nums.size();
        if(sum==0)
            return 0;
        if(sum==1)
            return nums[0];
        if(sum==2)
            return nums[0]>nums[1]?nums[0]:nums[1];
        int x=cal(nums,0,sum-2);
        int y=cal(nums,1,sum-1);
        return x>y?x:y;
    }
};

int main()
{
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    Solution s;
    cout<<s.rob(temp)<<endl;
    return 0;
}
