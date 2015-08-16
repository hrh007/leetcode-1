#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//  Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &x,const Interval &y)
    {
        return x.start<y.start;
    }
class Solution
{
public:

    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> res;
        if(intervals.size()==0)
            return res;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval>::iterator ite=intervals.begin();
        res.push_back(*ite);
        Interval temp=*ite++;
       for(;ite!=intervals.end();ite++)
       {
           if(temp.end>=ite->start)
           {
               int s=temp.start<ite->start?temp.start:ite->start;
               int e=temp.end>ite->end?temp.end:ite->end;
               Interval *t=new Interval(s,e);
               res.pop_back();
               temp=*t;
               res.push_back(*t);
           }
           else
            {
                res.push_back(*ite);
                temp=*ite;
            }
       }
       return res;
    }
};

int main()
{
    vector<Interval> test;
    Interval t1(2,7);
    test.push_back(t1);
    Interval t2(3,6);
    test.push_back(t2);
    Interval t3(1,5);
    test.push_back(t3);
    Interval t4(15,18);
    test.push_back(t4);
    Solution s;
    vector<Interval> res;
    res=s.merge(test);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].start<<"   "<<res[i].end<<endl;
    }
    return 0;
}
