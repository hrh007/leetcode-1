#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int,int> >res;
        int all=buildings.size();
        if(all==0)
            return res;
        map<int,int> m;
        int left=buildings[0][0];
        int height=buildings[0][1];
        int right=buildings[0][2];
        m[height]=right;
        res.push_back(make_pair(left,height));
        for(int i=1; i<all; ++i)
        {
            if(buildings[i][0]>right)
            {
                res.push_back(make_pair(right,height));
                left=buildings[i][0];
                height=buildings[i][1];
                right=buildings[i][2];
                m[height]=right;
                res.push_back(make_pair(left,height));
            }
            else
            {
                if(height<buildings[i][1])
                {
                    if(buildings[i][2]<=right)
                    {

                    }
                    else
                    {

                    }
                }
                else
                {

                }

            }
        }
    }
};

int main()
{

    return 0;
}
