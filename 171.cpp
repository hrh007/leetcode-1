#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        long long result=0;
        for(int i=0;i<s.length();i++)
        {
                result=result*26+s[i]-64;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.titleToNumber("AB")<<endl;
    return 0;
}
