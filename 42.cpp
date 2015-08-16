#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int len=height.size();
        int maxHeight=0;
        int sum=0;
        int left=0;
        int right=0;
        int res=0;
        int leftHeight=0;
        int rightHeight=0;
        int leftPos=0;
        int rightPos=0;
        for(int i=0; i<len; i++)
        {
            if(i-1>=0&&i+1<len&&height[i]<=height[i-1]&&height[i]<=height[i+1])
            {
                left=i;
                right=i;
                sum=0;
                leftHeight=height[i];
                rightHeight=height[i];
                while(left-1>=rightPos)
                {
                    if(height[left-1]>=leftHeight)
                    {
                        leftHeight=height[left-1];
                        leftPos=left-1;
                    }
                    --left;
                }
                while(right+1<len)
                {
                    if(height[right+1]>=rightHeight)
                    {
                        rightHeight=height[right+1];
                        rightPos=right+1;
                    }
                    ++right;
                }
                for(int j=leftPos+1;j<rightPos;j++)
                    sum+=height[j];
                    cout<<"leftPOs=="<<leftPos<<endl;
                    cout<<"rightPOs=="<<rightPos<<endl;
                    cout<<"leftHeight=="<<leftHeight<<endl;
                    cout<<"rightHeight=="<<rightHeight<<endl;
                    cout<<sum<<endl;

                if(leftHeight>rightHeight)
                {
                    res+=((rightPos-1-leftPos)*leftHeight-sum);
                }
                else
                {
                    res+=((rightPos-1-leftPos)*rightHeight-sum);
                }
                 cout<<res<<endl;
                i=rightPos;
            }
        }
        return res;

    }
};

int main()
{
    Solution s;
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    /* height.push_back(2);
     height.push_back(0);
     height.push_back(2);*/
    cout<<s.trap(height)<<endl;
    return 0;
}
