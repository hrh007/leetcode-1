#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
      int max=m+n-1;
      int i=m-1;
      int j=n-1;
      while(i>=0&&j>=0)
      {
          if(A[i]>B[j])
          {
              A[max--]=A[i--];
          }
          if(A[i]<=B[j])
          {
              A[max--]=B[j--];
          }
      }
      while(i>=0)
        A[max--]=A[i--];
      while(j>=0)
        A[max--]=B[j--];
    }
};

class Solution2
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int i=0;
        int j=0;
        int k=0;
        int temp[m+n];
        while(i<m&&j<n)
        {
            if(A[i]>B[j])
            {
                temp[k++]=B[j];
                j++;
            }
            else
            {
                temp[k++]=A[i];
                i++;
            }
        }
        while(i<m)
            temp[k++]=A[i++];
        while(j<n)
            temp[k++]=B[j++];
        for(i=0;i<m+n;i++)
           A[i]=temp[i];
    }
};

int main()
{
    int a[2]= {2};
    int b[]= {1};
    Solution s;
    s.merge(a,1,b,1);
    for(int i=0; i<2; i++)
        cout<<"  "<<a[i];
    cout<<endl;
    return 0;
}
