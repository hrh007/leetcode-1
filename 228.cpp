#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution
{
public:

    string intToString(int x)
    {
        stringstream ss;
        ss<<x;
        return ss.str();
        //return res;
    }

    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> res;
        int sum=nums.size();
        if(sum==0)
            return res;
        int i=0;
        int j=0;
        string temp="";
        while(i<sum)
        {
            temp="";
            temp+=intToString(nums[i]);
            j=i+1;
              while(j<sum)
            {
                if(nums[j]-nums[i]==j-i)
                    ++j;
                else
                    break;
            }
            if(j!=i+1)
            {
                temp+="->";
                temp+=intToString(nums[j-1]);
            }
            res.push_back(temp);
            i=j;
        }
        return res;
    }
};

int main()
{
    //int a[]={0,1,2,4,5,7};
    vector<int > a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
  //  a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    Solution s;
   // vector<string> res=s.summaryRanges(a);
   // for(int i=0;i<res.size();i++)
  //  {
   //    cout<<res[i]<<endl;
  //  }
  int aa = 30;
   char c[8];
  itoa(aa,c,16);
 cout<<c<<endl; // 1e
    return 0;
}
