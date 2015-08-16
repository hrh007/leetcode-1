#incldue <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row=matrix.size();
        int count=row/2;
        int j=0;
        int i=0;
        int temp;
        for(;i<count;i++)
        {
            j=i;
            for(;j<row-1-i;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[row-1-j][i];
                matrix[row-1-j][i]=matrix[row-1-i][row-1-j];
                matrix[row-1-i][row-1-j]=matrix[j][row-1-i];
                matrix[j][row-1-i]=temp;
            }
        }
    }
};

int main()
{

    return 0;
}
