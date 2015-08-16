#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
      int count;
      for (count=0; n; count++)
        n = n&(n-1);
    return count;
}  //put count of each 32 bits into those 32 bits
};

class Solution2
{
public:
    int hammingWeight(uint32_t x)
    {
      uint32_t m1=0x55555555;
      uint32_t m2=0x33333333;
      uint32_t m4=0x0f0f0f0f;
      uint32_t m8=0x00ff00ff;
      uint32_t m16=0x0000ffff;
      x=(x&m1)+(x>>1&m1);
      x=(x&m2)+(x>>2&m2);
      x=(x&m4)+(x>>4&m4);
      x=(x&m8)+(x>>8&m8);
      x=(x&m16)+(x>>16&m16);
      return x;
}  //put count of each 32 bits into those 32 bits
};

int main()
{
    Solution2 s;
    cout<<s.hammingWeight(100)<<endl;
    return 0;
}


//This is a naive implementation, shown for comparison,
//and to help in understanding the better functions.
//It uses 24 arithmetic operations (shift, add, and).
