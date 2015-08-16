#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<int> temp;
        vector<vector<int> >res;
        int len=num.size();
        int s=0;
        int e=0;
        for(int i=0;i<len-2;i++)
        {
            s=i+1;
            e=len-1;
            while(s<e)
            {
                if(num[s]+num[e]+num[i]==0)
                {
                    temp.push_back(num[i]);
                    temp.push_back(num[s]);
                    temp.push_back(num[e]);
                    res.push_back(temp);
                    temp.clear();
                    while(s+1<=len-2&&num[s]==num[s+1])
                        s++;
                    while(e-1>=i+2&&num[e]==num[e-1])
                        e--;
                    s++;
                    e--;
                }
                else if(num[s]+num[e]+num[i]>0)
                    e--;
                else
                    s++;
            }
            while(num[i]==num[i+1])
                i++;
        }
        return res;
    }
};

int main()
{
    vector<int> test;
    vector<vector<int> >res;
    test.push_back(-2);
    test.push_back(0);
    test.push_back(1);
    test.push_back(1);
    test.push_back(2);
    Solution s;
    res=s.threeSum(test);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
            cout<<"  "<<res[i][j];
        cout<<endl;
    }
    return 0;
}
