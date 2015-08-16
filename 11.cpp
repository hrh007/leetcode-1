#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max=0;
        int i=0;
        int j=height.size()-1;
        int h=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                if(height[i]*(j-i)>max)
                    max=height[i]*(j-i);
                i++;
            }
            else
            {
                if(height[j]*(j-i)>max)
                    max=height[j]*(j-i);
                j--;

            }
        }
        return max;
    }
};

class Solution1
{
public:
    int maxArea(vector<int> &height)
    {
        int minHeight[height.size()][height.size()];
       memset(minHeight,0,sizeof(minHeight));
        int max=0;
        for(int i=0; i<height.size()-1; i++)
        {
            if(height[i+1]<=height[i])
                minHeight[i][i+1]=height[i+1];
            else
                minHeight[i][i+1]=height[i];
            if(minHeight[i][i+1]>=max)
                max=minHeight[i][i+1];
        }
        for(int i=2; i<height.size()-1; i++)
        {
            for(int j=0; j<height.size()-i; j++)
            {
                if(height[j+i]<=minHeight[j][j+i-1])
                    minHeight[j][j+i]=height[j+i];
                else
                    minHeight[j][i+j]=minHeight[j][j+i-1];
                if(minHeight[j][i]*i>=max)
                    max=minHeight[j][i]*i;
            }
        }
        return max;
    }
};


int main()
{
    Solution s;
    vector<int> height;
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(4);
    height.push_back(1);
    height.push_back(2);
    cout<<s.maxArea(height)<<endl;
    return 0;
}
