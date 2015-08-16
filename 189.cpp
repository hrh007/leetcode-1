#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(k>n)
            k=k%n;
        if(k==0)
            return ;
        int temp[k];
        for(int i=1;i<=k;i++)
            temp[i-1]=nums[n-k+i-1];
        for(int i=n-1;i>=0;i--)
        {
            if(i>k-1)
            nums[i]=nums[i-k];
            else
                nums[i]=temp[(k--)-1];
        }
        for(int i=0;i<n;i++)
            cout<<nums[i]<<endl;
    }
};

int main()
{
    int nums[]={1,2};
    Solution s;
    s.rotate(nums,2,3);
    return 0;
}
