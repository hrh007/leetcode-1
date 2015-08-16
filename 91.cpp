#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution2
{
public:

    int numDecodings(string s)
    {
        if(s.size()<=1)
            return 1;
        int len=s.size();
        string temp=s.substr(0,2);
        if(temp[0]=='2'&&temp[1]<='6'||temp[0]=='1')
            return numDecodings(s.substr(2,len-2))+numDecodings(s.substr(1,len-1));
        else
            return numDecodings(s.substr(1,len-1));
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s == "") return 0;
        if (s[0] == '0') return 0;
        int size = s.size();
        if(size == 1) return 1;

        vector<int> f(size , 0);

        f[0] = 1;
        f[1] = 2;
       // cout << s[1] << " " << s[0] <<endl;
        //cout << "s[1] = " << s[1] <<endl;
        if(s[1] == '0' && (s[0] == '1' || s[0] == '2')) f[1] = 1;
        if(s[1] == '0' && !(s[0] == '1' || s[0] == '2')) return 0;
        if(s[0] == '2' && (s[1] > '6')) f[1] = 1;
        if(s[0] > '2') f[1] = 1;
        //cout << f[1] <<endl;
        //cout << "coming" <<endl;
        for(int i = 2 ; i < size ; i++){
            f[i] = f[i - 1];
            if(s[i] == '0' && (s[i-1] == '1' || s[i - 1] == '2')) {f[i] = f[i-2];continue;}
            if(s[i] == '0' && !(s[i-1] == '1' || s[i - 1] == '2')) return 0;

            if(s[i-1] == '1') f[i] += f[i-2];
            if(s[i-1] == '2' && (s[i] >= '1' && s[i] <= '6')) f[i] += f[i-2];
        }
        return f[size - 1];
    }
};

int main()
{
    Solution s;
    cout<<s.numDecodings("01")<<endl;
    Solution2 s2;
    cout<<s2.numDecodings("0")<<endl;
    return 0;
}
