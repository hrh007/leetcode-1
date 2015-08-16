#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target<=A[0])
            return 0;
        int left=0;
        int right=n-1;
        int mid=0;
        while(left<right)
        {
            mid=(left+right)/2;
            if(A[mid]==target)
                return mid;
            else if(A[mid]<target)
                 left=mid+1;
            else
                right=mid-1;
        }
        if(target>A[left])
            return left+1;
        else
            return left;
    }
};

int main()
{
    int a[]={1,3,5,6};
    Solution s;
    cout<<s.searchInsert(a,4,0)<<endl;
    return 0;
}
