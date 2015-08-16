#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int max=nums[0];
        for(int i=0;i<len;i++)
        {
            if(i>max)
                return false;
            else if(nums[i]+i>=len-1)
                return true;
            else
                {
                    if(nums[i]+i>max)
                    max=nums[i]+i;
                }
        }
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int num[len];
        memset(num,0,sizeof(num));
        for(int i=len-2;i>=0;i--)
        {
            if(nums[i]+i>=len-1)
                num[i]=1;
            else
            {
                for(int j=i+1;j<=i+nums[i];j++)
                {
                    if(num[j]==1)
                    {
                        num[i]=1;
                        break;
                    }
                }
            }
        }
        if(num[0]==1)
            return true;
        else
            return false;
    }
};

int main()
{

   vector<int> test;
   test.push_back(3);
   test.push_back(3);
   test.push_back(1);
   test.push_back(0);
   test.push_back(1);
   test.push_back(4);
   Solution s;
   cout<<s.canJump(test)<<endl;
    return 0;
}
