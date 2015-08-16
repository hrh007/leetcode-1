#include <iostream>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        int temp1[32];
        int temp2[32];
        int k=0;
        while(n!=0)
        {
            temp1[k++]=n%2;
            n=n/2;
        }
        for(int i=0;i<32;i++)
            {
                if(i<k)
                result=result*2+temp1[i];
                else
                result=result*2+0;
            }
            return result;
    }
};

class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m1=0x55555555;
        uint32_t m2=0x33333333;
        uint32_t m4=0x0f0f0f0f;
        uint32_t m8=0x00ff00ff;
        uint32_t m16=0x0000ffff;
        n=(n>>1&m1)|((n&m1)<<1);
        n=(n>>2&m2)|((n&m2)<<2);
        n=(n>>4&m4)|((n&m4)<<4);
        n=(n>>8&m8)|((n&m8)<<8);
        n=(n>>16&m16)|((n&m16)<<16);
        return n;
    }
};

int main()
{
    Solution2 s;
    cout<<s.reverseBits(43261596)<<endl;
    return 0;
}
