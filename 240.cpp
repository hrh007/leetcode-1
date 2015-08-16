#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows=matrix.size();
    if(rows==0)
            return false;
    int colums=matrix[0].size();
    int x=colums-1;
    int y=0;
    while(y<rows&&x>=0)
    {
        if(matrix[y][x]==target)
            return true;
        else if(matrix[y][x]>target)
            --x;
        else
            ++y;
    }
    return false;
    }
};

int main()
{

    return 0;
}
