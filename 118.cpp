#include <iostream>
#include <vector>

#define MAX 10000;

using namespace std;

class Solution
{

public:
    vector<vector<int> > generate(int numRows)
    {

        vector<vector<int> > result;
        vector<int> temp1;
        vector<int> temp2;
        if(numRows>=1)
        {
            temp1.push_back(1);
            result.push_back(temp1);
        }
        if(numRows>=2)
        {
            temp2.push_back(1);
            temp2.push_back(1);
            result.push_back(temp2);
        }
        for(int i=3;i<=numRows;i++)
        {
            if(i%2==0)
            {
                temp2.clear();
                for(int j=0;j<i;j++)
                {
                    if(j==0||j==i-1)
                        temp2.push_back(1);
                    else
                        temp2.push_back(temp1[j-1]+temp1[j]);
                }
                result.push_back(temp2);
            }
            else
            {
                temp1.clear();
                for(int j=0;j<i;j++)
                {
                    if(j==0||j==i-1)
                        temp1.push_back(1);
                    else
                        temp1.push_back(temp2[j-1]+temp2[j]);
                }
                result.push_back(temp1);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > rec;
    rec=s.generate(5);
    cout<<'['<<endl;
    for(int i=0; i<rec.size(); i++)
    {
        for(int j=0; j<rec[i].size(); j++)
            cout<<rec[i][j]<<"  ";
        cout<<endl;
    }
    cout<<']'<<endl;
    return 0;
}
