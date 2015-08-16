#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int> >res;
    sort(nums.begin(),nums.end());
    int len=nums.size();
    int s;
    for(int i=0;i<len;i++)
    {
        s=res.size();
        for(int j=0;j<s;j++)
        {
            temp=res[j];
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
        temp.clear();
        temp.push_back(nums[i]);
        res.push_back(temp);
    }
    temp.clear();
    res.push_back(temp);
    return res;
    }
};

int main()
{
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    Solution s;
    vector<vector<int> >res=s.subsets(test);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<"   "<<res[i][j];
        cout<<endl;
    }
    return 0;
}
