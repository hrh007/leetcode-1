#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:

    int maxProfit(vector<int>& prices)
    {
       int profit=0;
       int i=0;
       int buy=0;
       int len=prices.size();
       for(i=0;i<len-1;i++)
       {
           if(buy==0&&prices[i]<prices[i+1])
           {
               buy=1;
               profit+=(-prices[i]);
           }
           if(buy==1&&prices[i]>prices[i+1])
           {
               buy=0;
               profit+=prices[i];
           }
       }
       if(buy==1)
        profit+=prices[len-1];
        return profit;
    }
};

class Solution2
{
public:
    int max2Num(int x,int y)
    {
        return  x>y?x:y;
    }
    int max3Num(int x,int y,int z)
    {
        int temp;
        temp=x>y?x:y;
        temp=temp>z?temp:z;
        return temp;
    }
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        int profit=0;
        int i=0;
        int j=0;
        int k=0;
        int matrix[len][len];
        memset(matrix,0,sizeof(matrix));
        for(i=1; i<len; i++)
        {
            for(j=0; i+j<len; j++)
            {
                if(i==1)
                {
                    matrix[j][j+i]=max2Num(matrix[j][j+i],prices[j+i]-prices[j]);
                   // cout<<"1   "<<"j=="<<j<<endl<<"j+i=="<<j+i<<endl<<matrix[j][j+i]<<endl;
                }
                else if(i==2)
                {
                    matrix[j][j+i]=max3Num(prices[j+i]-prices[j],matrix[j][j+1],matrix[j+i-1][j+i]);
                    //cout<<"2   "<<"j=="<<j<<endl<<"j+i=="<<j+i<<endl<<matrix[j][j+i]<<endl;
                }
                else
                {
                    for(k=j+1; k<j+i-1; k++)
                    {
                        matrix[j][j+i]=max3Num(matrix[j][k]+matrix[k+1][j+i],prices[j+i]-prices[j],matrix[j][j+i]);
                       //   cout<<"k=="<<k<<"j=="<<j<<endl<<"j+i=="<<j+i<<endl<<matrix[j][j+i]<<endl;
                    }

                }
                profit=max2Num(profit,matrix[j][j+i]);
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
