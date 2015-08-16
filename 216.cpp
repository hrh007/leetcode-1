#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void Find(int k,int target,int num,vector<vector<int> > &res,vector<int> &temp)
    {
      if(num>target)
        return ;
      for(int i=num;i<10&&i<=target/k;i++)
      {
          temp.push_back(i);
          if(k==1)
          {
              if(i==target)
              {
                  res.push_back(temp);
              }
          }
          else
          {
              if(i<target)
              {
                  Find(k-1,target-i,i+1,res,temp);
              }
          }
          temp.pop_back();
      }
    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int>temp;
        Find(k,n,1,res,temp);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res=s.combinationSum3(1,10);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<"  "<<res[i][j];
        cout<<endl;
    }
    return 0;
}
