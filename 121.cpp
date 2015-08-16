#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int maxprofit=0;
        int len=prices.size();
        if(len==0)
            return 0;
        int low=prices[0];
        for(int i=1; i<len; i++)
        {
           if(prices[i]<low)
           low=prices[i];
           else if(prices[i]-low>maxprofit)
            maxprofit=prices[i]-low;
        }
        return maxprofit;
    }
};

int main()
{
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(7);
    temp.push_back(3);
    temp.push_back(8);
    Solution s;
    cout<<s.maxProfit(temp)<<endl;
    return 0;
}
