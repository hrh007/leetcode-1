#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

/**

 Definition for a point.
*/
struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
    int maxPoints(vector<Point>& points)
    {
        vector<Point>::size_type sum=points.size();
        if(sum==0)
            return 0;
        map<double,int> m1;
        int res=1;
        int sum_x=0;
        int sum_y=0;
        double k=0;
        map<double,int>::iterator ite;

        for(vector<Point>::size_type i=0; i<sum; i++)
        {
            if(point[i].x==0)
            {

            }
            if(point[i].y==0)
            {

            }
            else
            {
                k=(double)(points[i].y)/(double)(points[i].x);
                ite=m1.find(k);
                if(ite!=m1.end())
                {
                    if(++ite->second>res)
                        res=ite->second;
                }
                else
                    m1.insert(pair<double,int>(k,1));
            }
        }
        return res;
    }
};

int main()
{

    Solution s;
    /// s.test(-2,3);
    return 0;
}
