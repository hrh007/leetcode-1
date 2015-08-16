#include <iostream>
#include <vector>

using namespace std;

/*class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> vec;
        int i;
        int row=rowIndex;
        for( i=0; i<=rowIndex/2; i++)
        {
            if(i==0)
                vec.push_back(1);
            else
            {

                if(vec[i-1]%i==0)
                 {
                   vec.push_back(vec[i-1]/i*row);
                 }
                 else if(row%i==0)
                 {
                   vec.push_back(row/i*vec[i-1]);
                 }
                 else
                 vec.push_back(vec[i-1]*row/i);
                row--;
            }
        }
        if(rowIndex%2==0&&rowIndex!=0)
        {
            for(int k=i-2; k>=0; k--)
                vec.push_back(vec[k]);
        }
        if(rowIndex%2!=0)
        {
            for(int k=i-1; k>=0; k--)
                vec.push_back(vec[k]);
        }
        return vec;
    }
};
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
     vector<int> vec;
        for(int i=0;i<=rowIndex;i++)
        {
            if(i==0)
                vec.push_back(1);
            else
            {
               for(int j=vec.size()-1;j>0;j--)
               {
                   vec[j]+=vec[j-1];
               }
               vec.push_back(1);
            }

        }
        return vec;
    }
};

int main()
{
    Solution s;
    //  for(int j=0;j<34;j++)
    //  {
    vector<int> vec=s.getRow(5);
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<"   ";
    cout<<endl;
    //  }
    return 0;
}
