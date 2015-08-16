#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<pair<int,int> >temp;
        int i=0;
        int j=0;
        int res=0;
        while(i<len)
        {
            if(i+1<len&&prices[i+1]>prices[i])
            {
                j=i+1;
                while(j+1<len&&prices[j+1]>prices[j])
                    j++;
                temp.push_back(pair<int,int>(prices[i],prices[j]));
                i=j+1;
            }
            else
                i++;
        }
        /*vector<pair<int,int> >::iterator ite=temp.begin();
        while(ite!=temp.end())
        {
            cout<<ite->first<<"   "<<ite->second<<endl;
            ite++;
        }*/
        len=temp.size();
        int num[len][len];
        for(int i=0;i<len;i++)
            {
                num[i][i]=temp[i].second-temp[i].first;
                if(num[i][i]>res)
                    res=num[i][i];
            }
        for(int i=1;i<len;i++)
        {
            for(int j=0;j+i<len;j++)
            {
                num[j][j+i]=num[j][j+i-1];
               for(int k=j;k<j+i;k++)
               {
                  // cout<<num[j][k]<<"    "<<num[k+1][i+j]<<endl;
                   if(res<num[j][k]+num[k+1][i+j])
                    {
                        res=num[j][k]+num[k+1][i+j];
                      //  cout<<res<<endl;
                    }
                   if(temp[j+i].second-temp[k].first>num[j][j+i])
                    num[j][j+i]=temp[j+i].second-temp[k].first;
               }
               if(num[j][j+i]>res)
                res=num[j][j+i];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(9);
    prices.push_back(2);
    prices.push_back(4);
    prices.push_back(6);
    prices.push_back(1);
    prices.push_back(8);
    prices.push_back(1);
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
