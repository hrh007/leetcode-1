#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num==0)
            return false;
        while(num!=1)
        {
            if(num%2==0)
                num=num/2;
            else if(num%3==0)
                num=num/3;
            else if(num%5==0)
                num=num/5;
            else
                break;
        }
        return num==1;
    }
};

int main()
{

   Solution s;
   cout<<s.isUgly(1)<<endl;
    return 0;
}
