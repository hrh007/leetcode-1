#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        string temp="";
        int len=num.size();
        for(int i=1; i<=len; ++i)
        {
            string curString=num.substr(0,i);
            if(curString.size()>1&&curString[0]=='0')
                continue;
            string nextString=num.substr(i,len-i);
            long long curNum=stringToLonglong(curString);
            temp="";
            cal(nextString,target,curNum,curNum,curString,res);
        }
        return res;
    }

private:

    long long stringToLonglong(string s)
    {
        stringstream ss;
        ss<<s;
        long long  res;
        ss>>res;
        return res;
    }


    void cal(string num,int target,long long last,long long cur,string temp,vector<string> &res)
    {
        int len=num.size();
        if(len==0&&target==cur)
        {
            res.push_back(temp);
            return ;
        }
        for(int i=1; i<=len; ++i)
        {
            string curString=num.substr(0,i);
            string nextString=num.substr(i,len-i);
            if(curString.size()>1&&curString[0]=='0')
                return ;
            long long curNum=stringToLonglong(curString);
            cal(nextString,target,curNum,cur+curNum,temp+"+"+curString,res);
            cal(nextString,target,-curNum,cur-curNum,temp+"-"+curString,res);
            cal(nextString,target,last*curNum,cur-last+last*curNum,temp+"*"+curString,res);
        }
    }
};

int main()
{
    Solution s;
    vector<string> res=s.addOperators("2147483647",2147483647);
    for(int i=0; i<res.size(); ++i)
        cout<<res[i]<<endl;
    return 0;
}
