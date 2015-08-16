#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int path[m][n];
        memset(path,0,sizeof(path));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(i==0&&j==0)
                    path[i][j]=grid[i][j];
                else if(i==0&&j>0)
                {
                    path[i][j]=path[i][j-1]+grid[i][j];
                }
                else if(j==0&&i>0)
                {
                    path[i][j]=path[i-1][j]+grid[i][j];
                }
                else
                {
                    if(path[i][j-1]<path[i-1][j])
                        path[i][j]=path[i][j-1]+grid[i][j];
                    else
                        path[i][j]=path[i-1][j]+grid[i][j];
                }
            }
        }
        return path[m-1][n-1];
    }
};

int main()
{

    return 0;
}
