#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dic;
        int size = path.size();
        int p = 0;
        while(p < size) {
            while(p < size && path[p] == '/') p++;
            int start = p;
            while(p < size && path[p] != '/') {
                p++;
            }
            if(p == start) break;
            string tmp = path.substr(start , p-start);
            if(tmp == ".") continue;
            if(tmp == "..") {
                if(dic.size() > 0) dic.pop();
                continue;
            }
            dic.push(tmp);
        }
        string ans = "";
        stack<string> rev;
        while(dic.size() > 0) {
            rev.push(dic.top());
            dic.pop();
        }
        while(rev.size() > 0) {
            ans += ("/" + rev.top());
            rev.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
    int len=path.size();
    string res="";
    stack<char> stack1;
    int i=0;
    while(i<len)
    {
        if(path[i]=='/')
        {
            if(i+2<len&&path[i+1]=='.'&&path[i+2]=='.')
            {
                if(!stack1.empty())
                {
                    while(stack1.top()!='/')
                    stack1.pop();
                stack1.pop();
                }
                i+=3;
            }
            else if(i+1<len&&path[i+1]=='/')
            {
                stack1.push(path[i]);
                i+=2;
                while(i<len&&path[i]=='/')
                    ++i;
                while(i<len&&path[i]!='/')
                    stack1.push(path[i++]);
            }
            else if(i+1<len&&path[i+1]=='.')
            {
                i+=2;
            }
            else
            {
                stack1.push(path[i++]);
                while(i<len&&path[i]!='/')
                    stack1.push(path[i++]);
            }
        }
        else
            ++i;
    }
    if(stack1.empty())
        return "/";
    stack1.pop();
    if(stack1.empty())
        return "/";
    while(!stack1.empty())
    {
        res.append(1,stack1.top());
        stack1.pop();
    }
    reverse(res.begin(),res.end());
    return res;
    }
};

int main()
{
    string temp("/...");
    Solution2 s;
    cout<<s.simplifyPath(temp)<<endl;
    return 0;
}
