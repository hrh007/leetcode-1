#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> >res;
        vector<int> temp;
        for(int j=0; j<n; j++)
            temp.push_back(0);
        for(int i=0; i<n; i++)
            res.push_back(temp);
        int count=0;
        int top=0;
        int left=0;
        int bottom=n;
        int right=n;
        int sum=n*n;
        while(true)
        {
            for(int i=left; i<right; i++)
                res[top][i]=++count;
            if(count>=sum)
                break;
            top++;
            for(int i=top; i<bottom; i++)
                res[i][right-1]=++count;
            if(count>=sum)
                break;
            right--;
            for(int i=right-1; i>=left; i--)
                res[bottom-1][i]=++count;
            if(count>=sum)
                break;
            bottom--;
            for(int i=bottom-1; i>=top; i--)
                res[i][left]=++count;
            if(count>=sum)
                break;
            left++;
        }
        return res;
    }
};

int main()
{
    int n=4;
    Solution s;
    vector<vector<int> >res=s.generateMatrix(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<"  "<<res[i][j];
        cout<<endl;
    }
    return 0;
}
