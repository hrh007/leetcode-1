#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> res;
        int rows=matrix.size();
        if(rows==0)
            return res;;
        int colums=matrix[0].size();
        int top=0;
        int left=0;
        int bottom=rows;
        int right=colums;
        int count=0;
        int sum=rows*colums;
        while(true)
        {
            for(int i=left; i<right; i++)
                {
                    res.push_back(matrix[top][i]);
                    count++;
                }
                if(count==sum)
                    break;
            top++;
            for(int i=top; i<bottom; i++)
                {
                    res.push_back(matrix[i][right-1]);
                    count++;
                }
                if(count==sum)
                    break;
            right--;
            for(int i=right-1; i>=left; i--)
                {
                    res.push_back(matrix[bottom-1][i]);
                    count++;
                }
                if(count==sum)
                    break;
            bottom--;
            for(int i=bottom-1;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);
                    count++;
                }
                if(count==sum)
                    break;
            left++;

        }
        return res;
    }
};

int main()
{
    vector<vector<int> >matrix;
   // vector<int> temp;
   //  matrix.push_back(temp);
  /*  temp.push_back(0);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(7);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(8);
    temp.push_back(9);
    temp.push_back(10);
    temp.push_back(11);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(12);
    temp.push_back(13);
    temp.push_back(14);
    temp.push_back(15);
    matrix.push_back(temp);*/
    Solution s;
    vector<int> res;
    res=s.spiralOrder(matrix);
    for(int i=0;i<res.size();i++)
        cout<<"  "<<res[i];
    cout<<endl;
    return 0;
}
