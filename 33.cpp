#include <iostream>

using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int count=-1;
        int left;
        int right;
        int mid;
        for(int i=0; i<n; i++)
        {
            if(A[i+1]<A[i]&&i+1<n)
            {
                count=i;
                break;
            }
            if(A[n-1-i]<A[n-2-i]&&n-2-i>=0)
            {
                count=n-2-i;
                break;
            }
        }
        if(count==-1)
        {
            left=0;
            right=n-1;
        }
        else
        {
           if(A[count]==target)
                return count;
            if(A[0]==target)
                return 0;
            if(target>A[0])
            {
                left=1;
                right=count-1;
            }
            else
            {
                left=count+1;
                right=n-1;
            }
        }
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(target==A[mid])
                return mid;
            else if(target>A[mid])
                left=mid+1;
            else
                right=mid-1;
        }
        return -1;
    }
};

int main()
{
    int A[]={3,4 ,5, 6, 0,1,2};
    Solution s ;
    for(int i=0;i<7;i++)
    cout<<s.search(A,7,i)<<endl;
    return 0;
}
