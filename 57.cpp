#include <iostream>
#include <vector>

using namespace std;


//  Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
         int len=intervals.size();
         vector<Interval> res;
         for(int i=0;i<len;i++)
         {
             if(intervals[i].end<newInterval.start)
                res.push_back(intervals[i]);
             else
             {
                 for(int j=i+1;j<len;j++)
                 {
                     if(newInterval.end<intervals[j].start)
                     {
                         Interval *temp=new Interval();
                         temp->start=intervals[i].start;
                         temp->end=newInterval.end();
                         res.push_back(temp);
                     }
                     else if(newInterval.end<intervals[j].end)
                     {
                         Interval
                     }
                 }
             }
         }
    }
};

int main()
{

    return 0;
}
