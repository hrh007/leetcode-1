#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution
{
public:

    bool Search(vector<int> &num,int left,int right,int target)
    {
        int mid;
        while(left<=right)
        {
            mid=(right+left)/2;
            if(num[mid]==target)
                return true;
            else if(num[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
        vector<vector<int> >res;
        vector<int>temp;
        sort(num.begin(),num.end());
        int len=num.size();
        int sum=0;
        //  int x=0;
        for(int i=0; i<len; i++)
        {

            if(num[i]>=target)
                break;
            else
            {
                sum=0;
                for(int count=i; count<len; count++)
                {
                    sum+=num[i];
                    temp.push_back(num[i]);
                    for(int j=count+1; j<len; j++)
                    {

                        sum+=num[j];
                        if(sum>=target)
                            break;
                        else
                        {
                            temp.push_back(num[j]);
                            if(Search(num,j+1,len-1,target-sum))
                            {
                                temp.push_back(target-sum);
                                res.push_back(temp);
                                temp.pop_back();
                            }
                            temp.pop_back();
                            sum-=num[j];
                        }
                     //   while(j+1<len&&num[j+1]==num[j])
                        //    j++;
                    }
                  //   while(count+1<len&&num[count+1]==num[count])
                         //   count++;
                }
                temp.clear();
            }
            //while(i+1<len&&num[i+1]==num[i])
                           //    i++;
        }
        return res;
    }
};

int main()
{
    vector<int> temp;
    temp.push_back(4);
    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(3);
    Solution s;
    vector<vector<int> >res=s.combinationSum2(temp,8);
    for(int i=0; i<res.size(); i++)
    {

        for(int j=0; j<res[i].size(); j++)
        {
            cout<<"   "<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}
