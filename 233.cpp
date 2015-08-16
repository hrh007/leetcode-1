#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:

    int stringToInt(string s)
    {
        stringstream ss;
        ss<<s;
        int res;
        ss>>res;
        return res;
    }

    string intToString(int n)
    {
        stringstream ss;
        ss<<n;
        string res;
        ss>>res;
        return res;
    }

    int cal(string s,int start)
    {
        while(s[start]=='0')
            ++start;
        if(start>=s.size())
            return 0;
        string str=s.substr(start,s.size()-start);
         if(stringToInt(str)<=0)
            return 0;
        int len=str.size();
        if(len==1)
        {
            if(str[0]=='0')
                return 0;
            else
                return 1;
        }
        else
        {
            double temp1=0;
            if(str[0]=='1')
            {
                temp1=stringToInt(str.substr(1,len-1))+1;
            }
            else
            {
                temp1=pow(10,len-1);
            }
            int temp2=stringToInt(str.substr(0,1))*pow(10,len-2)*(len-1);
            return temp1+temp2+cal(s,start+1);
        }
    }

    int countDigitOne(int n) {
    return cal(intToString(n),0);
    }
};

int main()
{
    Solution s;
    cout<<s.countDigitOne(101)<<endl;
    return 0;
}
