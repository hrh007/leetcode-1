#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int sum=nums.size();
     if(sum<=1)
        return nums;
     vector<int> res;
     int temp1=0;
     int count1=0;
     int temp2=0;
     int count2=0;
     for(int i=0;i<sum;++i)
     {
         if(count1==0||nums[i]==temp1)
             {
                 ++count1;
                 temp1=nums[i];
             }
         else if(count2==0||nums[i]==temp2)
            {
                ++count2;
                temp2=nums[i];
            }
         else
         {
             --count1;
             --count2;
         }
     }
     int sum1=0;
     int sum2=0;
     for(int i=0;i<sum;++i)
     {
         if(nums[i]==temp1)
            ++sum1;
         else if(nums[i]==temp2)
            ++sum2;
         else
            continue;
     }
     if(sum1>sum/3)
        res.push_back(temp1);
     if(sum2>sum/3)
        res.push_back(temp2);
     return res;
    }
};

int main()
{

    return 0;
}
