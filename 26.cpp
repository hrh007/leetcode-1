#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)
            return 0;
        int start=0;
        for(int i=1;i<n;i++)
        {
            if(A[start]!=A[i])
            A[++start]=A[i];
        }
        return start+1;
    }
};

int main()
{
    int a[]={};
    Solution s;
    int res=s.removeDuplicates(a,0);
    cout<<res<<endl;
    for(int i=0;i<res;i++)
        cout<<a[i]<<"   ";
    cout<<endl;
    return 0;
}
