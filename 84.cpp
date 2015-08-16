#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& height)
    {
        int len=height.size();
        //vector<int> temp(len,0);
        int num[len];
        int res=0;
        for(int k=0; k<len; k++)
        {
            num[k]=height[k];
            if(height[k]>res)
                res=height[k];
        }
        for(int k=1; k<len; k++)
        {
            for(int i=0; i+k<len; i++)
            {
                if(num[i]>height[i+k])
                    num[i]=height[i+k];
                else
                    num[i]=num[i];
                if(num[i]*(k+1)>res)
                    res=num[i]*(k+1);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    Solution s;
    cout<<s.largestRectangleArea(test)<<endl;
    return 0;
}
