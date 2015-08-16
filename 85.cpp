#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int rows=matrix.size();
        if(rows==0)
            return 0;
        int res=0;
        int k=0;
        int l=0;
        int count=0;
        int sum=0;
        int left=0;
        int up=0;
        int colums=matrix[0].size();
        int num1[rows][colums];
        int num2[rows][colums];
        for(int i=0; i<colums; i++)
        {
            if(matrix[0][i]=='1')
                num1[0][i]=1;
            else
                num1[0][i]=0;
            if(num1[0][i]>res)
                res=num1[0][i];
        }
        for(int i=0; i<rows; i++)
        {
            if(matrix[i][0]=='1')
                num2[i][0]=1;
            else
                num2[i][0]=0;
            if(num2[i][0]>res)
                res=num2[i][0];
        }
        for(int i=1; i<rows; i++)
        {
            for(int j=0; j<colums; j++)
            {
                if(matrix[i][j]=='1')
                    num1[i][j]=num1[i-1][j]+1;
                if(matrix[i][j]=='0')
                    num1[i][j]=0;
            }
        }
        for(int i=0; i<rows; i++)
        {
            if(num1[i][0]*num2[i][0]>res)
                res=num1[i][0]*num2[i][0];
        }
        for(int i=1; i<colums; i++)
        {
            for(int j=0; j<rows; j++)
            {
                if(matrix[j][i]=='1')
                    num2[j][i]=num2[j][i-1]+1;
                if(matrix[j][i]=='0')
                    num2[j][i]=0;
                if(num1[j][i]*num2[j][i]>res)
                {
                      count=0;
                      sum=0;
                      left=i+1-num2[j][i];
                      up=j+1-num1[j][i];
                    for(k=j; k>=up; k--)
                    {

                        for(l=i; l>=left; l--)
                        {
                            if(matrix[k][l]=='0')
                            {
                                count++;
                                break;
                            }
                            else
                                sum++;
                        }
                        if(l>=left)
                        {
                            sum=sum-(l-left+1)*(j-k);
                            left=l+1;
                        }
                        if(sum>res)
                            res=sum;
                    }

                }
            }
        }
        return res;
    }
};

int main()
{
    vector<char> temp;
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('0');
    temp.push_back('1');
    vector<vector<char> >test;
    test.push_back(temp);
    test.push_back(temp);
    temp.clear();
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('1');
    test.push_back(temp);
    // test.push_back(temp);
    for(int i=0; i<test.size(); i++)
    {
        for(int j=0; j<test[i].size(); j++)
            cout<<"   "<<test[i][j];
        cout<<endl;
    }
    cout<<endl;
    Solution s;
    cout<<s.maximalRectangle(test)<<endl;
    return 0;
}
