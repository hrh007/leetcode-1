#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> >res;
        vector<int> temp;
        int len=nums.size();
        int s;
        int j=0;
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<len; i++)
        {
            s=res.size();
            for(; j<s; j++)
            {
                temp=res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
            temp.clear();
            if(count==0)
            {
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
            if(i+1<len&&nums[i+1]==nums[i])
            {
                j=s;
                count=1;
            }
            else
            {
                j=0;
                count=0;
            }
        }
        temp.clear();
        res.push_back(temp);
        return res;
    }
};

int main()
{
    vector<int> test;
   // test.push_back(0);
  //  test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
  //  test.push_back(3);
    Solution s;
    vector<vector<int> >res=s.subsetsWithDup(test);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout<<"   "<<res[i][j];
        cout<<endl;
    }
    return 0;
}
