#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left=0;
        int right=n-1;
        int mid;
        int count=0;
        vector<int> res;
        while(left<=right)
        {
            mid=(right+left)/2;
            if(A[mid]==target)
            {
                count=1;
                break;
            }
            if(A[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        if(count==0)
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else
        {
            int i=1;
            int j=1;
            while(A[mid]==A[mid-i]&&mid-i>=0)
                i++;
                i--;
                res.push_back(mid-i);
            while(A[mid]==A[mid+j]&&mid+j<n)
                    j++;
                     res.push_back(mid+j-1);
        }
        return res;
    }
};

int main()
{
    int A[]={5,7,7,8,8,10};
    Solution s;
    vector<int> res;
    res=s.searchRange(A,6,-1);
    int len=res.size();
    for(int i=0;i<len;i++)
        cout<<"  "<<res[i];
    cout<<endl;
    return 0;
}
