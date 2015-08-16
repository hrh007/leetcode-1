#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution
{
public:

    int maxProduct(vector<int>& nums)
    {
        int count1=INT_MIN;
        int count2=INT_MAX;
        int count3=1;
        int count4=-1;
        int sum=1;
        int res=INT_MIN;
        int len=nums.size();
        for(int i=0; i<len; i++)
        {
            if(nums[i]>res)
                res=nums[i];
            sum*=nums[i];
            if(sum>res)
                res=sum;
            if(sum>0)
            {
                if(sum>count3)
                    count3=sum;
                if(sum<count2)
                    count2=sum;
            }
            else if(sum<0)
            {
                if(sum<count4)
                    count4=sum;
                if(sum>count1)
                    count1=sum;
            }
            else
            {
                if(count2!=INT_MAX&&count3!=count2&&count3/count2>res)
                    res=count3/count2;
                if(count1!=INT_MIN&&count4!=count1&&count4/count1>res)
                    res=count4/count1;
                sum=1;
                count1=INT_MIN;
                count2=INT_MAX;
                count3=1;
                count4=-1;
            }
        }
        if(count2!=INT_MAX&&count3!=count2&&count3/count2>res)
            res=count3/count2;
        if(count1!=INT_MIN&&count4!=count1&&count4/count1>res)
            res=count4/count1;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> test;
    test.push_back(-1);
    test.push_back(-2);
    test.push_back(-3);
    //  test.push_back(-2);
    test.push_back(0);
    cout<<s. maxProduct(test)<<endl;
    return 0;
}
