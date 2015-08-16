#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

       // if(m==1||n==1)
        //    return 1;
         int num[m];
         for(int i=0;i<m;i++)
            num[i]=1;
         for(int i=0;i<n-1;i++)
         {
             num[0]=1;
             for(int j=1;j<m;j++)
                num[j]=num[j-1]+num[j];
         }
         return num[m-1];
    }
};

int main()
{

    Solution s;
    cout<<s.uniquePaths(3,1)<<endl;
    return 0;
}
