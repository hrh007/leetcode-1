#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len=n;
        int count=0;
        int j=0;
        for(int i=0;i<len;i++)
        {
            count=0;
            while(i+1<len&&A[i]==A[i+1])
            {

                count++;
                i++;
                if(count>1)
                {
                    n--;
                }
                else
                    A[j++]=A[i-1];
            }
                    A[j++]=A[i];
         }
        return n;
    }
};

int main()
{
    int A[]={1,1,1,1};
    Solution s;
    int res=s.removeDuplicates(A,4);
    cout<<res<<endl;
    for(int i=0;i<res;i++)
        cout<<"   "<<A[i];
    cout<<endl;
    return 0;
}
