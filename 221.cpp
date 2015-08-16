#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:

    int min(int x,int y)
    {
        return x<y?x:y;
    }
    int maximalSquare(vector<vector<char> >& matrix)
    {
        int rows=matrix.size();
        if(rows==0)
            return 0;
        int max=0;
        int colums=matrix[0].size();
        int count[rows][colums];
        for(int i=0; i<rows; ++i)
        {

            if(matrix[i][0]=='1')
            {
                count[i][0]=1;
                max=1;
            }
            else
                count[i][0]=0;
        }
        for(int i=0; i<colums; ++i)
        {
            if(matrix[0][i]=='1')
            {
                count[0][i]=1;
                max=1;
            }
            else
                count[0][i]=0;
        }
        for(int i=1; i<rows; ++i)
        {
            for(int j=1; j<colums; ++j)
            {
                if(matrix[i][j]=='1')
                {
                    count[i][j]=min(count[i-1][j-1],min(count[i-1][j],count[i][j-1]))+1;
                    if(count[i][j]>max)
                        max=count[i][j];
                }
                else
                    count[i][j]=0;
            }
        }
        return max*max;
    }
};

int main()
{

    return 0;
}
