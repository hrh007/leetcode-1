#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int sum_zero=0;
        int sum_two=0;
        int temp;
        for(int i=0;i<len-sum_two;i++)
        {
            if(nums[i]==0)
            {
                if((i!=sum_zero))
                {
                    temp=nums[sum_zero];
                    nums[sum_zero++]=0;
                    nums[i]=temp;
                }
                else
                    sum_zero++;
            }
            if(nums[i]==2)
            {
                while(nums[len-1-sum_two]==2)
                    sum_two++;
                if(len-1-sum_two<=i)
                    break;
                if(nums[len-1-sum_two]==1)
                {
                    nums[len-1-sum_two++]=2;
                    nums[i]=1;
                }
                else
                {
                    nums[len-1-sum_two++]=2;
                    temp=nums[sum_zero];
                    nums[sum_zero]=0;
                    if(i!=sum_zero)
                    nums[i]=temp;
                    sum_zero++;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> test;
    vector<int> res;
    test.push_back(2);
    test.push_back(0);
    test.push_back(0);
    test.push_back(2);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(0);
    s.sortColors(test);
    for(int i=0;i<test.size();i++)
    {
        cout<<"  "<<test[i];
    }
    return 0;
}
