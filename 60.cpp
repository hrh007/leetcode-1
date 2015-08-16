#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    priority_queue<string,vector<string>,greater<string> > res;
    priority_queue<string,vector<string>,greater<string> > temp;
    string s="1";
    res.push(s);
    int len=0;
    string stemp;
    for(int i=2;i<=n;i++)
    {
        temp=res;
        while(!res.empty())
        {
            res.pop();
        }
        while(!temp.empty())
        {
            s=temp.top();
          //  cout<<s<<endl;
            temp.pop();
            len=i-1;
            for(int j=len;j>=0;--j)
            {
                stemp=s;
                stemp.insert(j,1,static_cast<char>(i+48));
               // cout<<"     "<<stemp<<endl;
                res.push(stemp);
            }
        }
    }
    int count=0;
    while(!res.empty())
    {
        s=res.top();
        if(++count==k)
        return s;
      // cout<<s<<endl;
        res.pop();
    }
   // return "123";
    }
};

int main()
{
    Solution s;
    string res=s.getPermutation(3,4);
    cout<<res<<endl;
    return 0;
}
