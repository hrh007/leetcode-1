#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:

    int maxSubArray(vector<int>& nums)
    {
        int max=INT_MIN;
        int len=nums.size();
        int sum=INT_MIN;
        for(int i=0;i<len;i++)
        {
            if(sum<0)
                sum=nums[i];
            else
                sum+=nums[i];
            if(sum>max)
                max=sum;
        }
        return max;
    }
};

class Solution1
{
public:

    int maxSubArray(vector<int>& nums)
    {
        int len=nums.size();
        if(len==0)
            return 0;
        int res=nums[0];
        int sum=nums[0];
        int minsum=0;
        for(int i=1; i<len; i++)
        {

            if(sum<minsum)
              minsum=sum;
            sum+=nums[i];
            if(sum-minsum>res)
                res=sum-minsum;
        }
        return res;
    }
};

class Solution2
{
public:

    int maxMid(vector<int> &nums,int left,int mid,int right)
    {
        int temp=mid;
        int leftsum=nums[temp];
        int leftres=leftsum;
        temp--;
        while(temp>=left)
        {
            leftsum+=nums[temp--];
            if(leftsum>leftres)
                leftres=leftsum;
        }
        temp=mid;
        int rightsum=nums[temp];
        int rightres=rightsum;
        temp++;
        while(temp<=right)
        {
            rightsum+=nums[temp++];
            if(rightsum>rightres)
                rightres=rightsum;
        }
        return leftres+rightres-nums[mid];
    }
    int maxArr(vector<int> &nums,int left,int right)
    {
        if(left==right)
            return nums[left];
        int mid=(left+right)/2;
        int leftSum=maxArr(nums,left,mid);
        int rightSum=maxArr(nums,mid+1,right);
        int midSum=maxMid(nums,left,mid,right);
        int res=leftSum;
        if(rightSum>res)
            res=rightSum;
        if(midSum>res)
            res=midSum;
        return res;
    }
    int maxSubArray(vector<int>& nums)
    {
        return maxArr(nums,0,nums.size()-1);
    }
};

int main()
{
    vector<int> test;
    test.push_back(-2);
    test.push_back(1);
    //test.push_back(-3);
   // test.push_back(4);
  //  test.push_back(-1);
  //  test.push_back(2);
  //  test.push_back(1);
  //  test.push_back(5);
  //  test.push_back(4);
    Solution s;
    cout<<s.maxSubArray(test)<<endl;
    return 0;
}
