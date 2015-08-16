#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if(n<=2)
            return 0;
        int isPrimer[n];
        memset(isPrimer,0,sizeof(isPrimer));
        for(int i=2; i*i<=n; i++)
        {
            if(isPrimer[i]!=0)
                continue;
            else
            {
                for(int j=i*i; j<=n; j+=i)
                    isPrimer[j]=1;
            }
        }
        int count=0;
        for(int i=2; i<n; i++)
            if(isPrimer[i]==0)
                count++;
        return count;
    }
};

int main()
{
   Solution s;
   cout<<s.countPrimes(6)<<endl;
    return 0;
}
