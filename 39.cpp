#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:

    void combination(vector<int> &candidates,int target,vector<vector<int> > &res,vector<int> temp,int start,int stop)
    {
        for(int i=start; i<stop; i++)
        {
            if(candidates[i]==target)
            {
                temp.push_back(candidates[i]);
                res.push_back(temp);
                while(i+1<stop&&candidates[i+1]==candidates[i])
                    i++;
                temp.clear();
            }
            else if(candidates[i]<target)
            {
                temp.push_back(candidates[i]);
                combination(candidates,target-candidates[i],res,temp,i,stop);
                temp.pop_back();
            }
            else
                break;

        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        int len=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int> >res;
        combination(candidates,target,res,temp,0,len);
        return res;
    }
};

int main()
{
    vector <int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(6);
    test.push_back(7);
    vector<vector<int> >res;
    Solution s;
    res=s.combinationSum(test,16);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<"  "<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}
