#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
      if(str.size()==0)
        return 0;
     int res;
     stringstream ss;
     ss<<str;
     ss>>res;
     return res;
    }
};

int main()
{

    return 0;
}
