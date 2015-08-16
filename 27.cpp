#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
       int start=0;
       for(int i=0;i<n;i++)
       {
           if(A[i]!=elem)
           {
               A[start++]=A[i];
           }
       }
       return start;
    }
};


class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
       int res=0;
       for(int i=0;i<n;i++)
       {
          if(A[i]==elem)
            res++;
          else
            A[i-res]=A[i];
       }
       return n-res;
    }
};

class Solution3 {
public:
    int removeElement(int A[], int n, int elem) {
       for(int i=0;i<n;i++)
       {
           if(A[i]==elem)
           {
              while(A[n-1]==elem&&n-1!=i)
              {
                  n--;
              }
              A[i]=A[n-1];
              n--;
           }
       }
       return n;
    }
};

int main()
{
    Solution s;
    int a[]={1};
    int res =s.removeElement(a,1,1);
    cout<<res<<endl;
    for(int i=0;i<res;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}
