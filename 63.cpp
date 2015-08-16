#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int rows=obstacleGrid.size();
        int cloums=obstacleGrid[0].size();
        int i=0;
        int j=0;
        int num[rows];
        for(i=0;i<rows;i++)
        {
            if(obstacleGrid[rows-1-i][cloums-1]==0)
                num[i]=1;
            else
            {
                while(i<rows)
                    num[i++]=0;
            }
        }
        for(i=0;i<cloums-1;i++)
        {
            if(obstacleGrid[rows-1][cloums-2-i]==1)
            num[0]=0;
            for(j=1;j<rows;j++)
            {
                if(obstacleGrid[rows-1-j][cloums-2-i]==0)
                    num[j]=num[j-1]+num[j];
                else
                    num[j]=0;
            }
        }
        return num[rows-1];
    }
};

int main()
{

    return 0;
}
