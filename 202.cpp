#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    int sum(int n)
    {
        int res=0;
        while(n!=0)
        {
            res+=(n%10)*(n%10);
            n=n/10;
        }
        return res;
    }

    bool isHappy(int n) {
          set<int> temp;
          //temp.insert(n);
          while(sum(n)!=1)
          {
              n=sum(n);
              if(temp.find(n)!=temp.end())
                return false;
              else
                temp.insert(n);
          }
          return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isHappy(11)<<endl;
    return 0;
}
