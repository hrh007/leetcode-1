#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int len=s.size();
        stack<int> temp;
        int max=0;
        int count=0;
        for(int i=0; i<len; ++i)
        {
            if(s[i]=='(')
                temp.push(i);
            else
            {
                if(!temp.empty())
                {
                    count=temp.top();
                    if(s[count]==')')
                        temp.push(i);
                    else
                    {
                        temp.pop();
                        if(temp.empty())
                            max=i+1;
                        else
                        {
                            count=temp.top();
                            if(i-count>max)
                                max=i-count;
                        }
                    }

                }
                else
                    temp.push(i);
            }
        }
        return max;
    }
};

int main()
{
    string temp(")()()");
    Solution s;
    cout<<s.longestValidParentheses(temp)<<endl;
    return 0;
}
