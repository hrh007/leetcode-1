#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        if(triangle.size()==0)
            return 0;
        int rows=triangle.size();
        int minSum=triangle[0][0];
        int num[rows];
        int colums;
        int temp;
        int temp2;
        num[0]=triangle[0][0];
        for(int i=1; i<rows; i++)
        {
            colums=triangle[i].size();
            temp=num[0];
            num[0]+=triangle[i][0];
            minSum=num[0];
            for(int j=1; j<colums-1; j++)
            {
                temp2=num[j];
                if(temp<num[j])
                {
                    num[j]=temp+triangle[i][j];
                }
                else
                {
                    num[j]=num[j]+triangle[i][j];
                }
                temp=temp2;
                if(minSum>num[j])
                    minSum=num[j];
            }
            num[colums-1]=temp+triangle[i][colums-1];
            if(num[colums-1]<minSum)
                minSum=num[colums-1];

        }
        return minSum;

    }
};

int main()
{

    return 0;
}
