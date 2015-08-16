#include <iostream>
#include <vector>
#include <cstring>
#include<algorithm>

using namespace std;
/*
class Solution
{
public:

    int majorityElement(vector<int > &num)
    {
        sort(num.begin(),num.end());
        return num[num.size()/2];
    }
};
*/

class Solution
{
public:

    int majorityElement(vector<int > &num)
    {
        int elem=0;
        int count=0;
        for(int i=0;i<num.size();i++)
        {
            if(count==0)
            {
                elem=num[i];
                count=1;
            }
            else
            {
                if(elem==num[i])
                    count++;
                else
                    count--;
            }
        }
        return elem;
    }
};

int main()
{
    Solution s;
    vector<int> rec;
    rec.push_back(-1);
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(2);
    rec.push_back(1);
    cout<<s.majorityElement(rec)<<endl;
    return 0;
}
