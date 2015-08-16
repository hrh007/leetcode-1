#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void sum(string s,map<char,int> &m)
    {
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(m.find(s[i])==m.end())
                m.insert(pair<char,int>(s[i],1));
            else
                ++m[s[i]];
        }
    }

    string minWindow(string s, string t)
    {
          string res;
        int len_s=s.size();
        int len_t=t.size();
        if(len_s<len_t)
            return res;
        map<char,int> m;
        map<char,int>::iterator ite;
       for(int i=0;i<len_t;i++)
       {
           ite=m.find(t[i]);
           if(ite==m.end())
            m.insert(pair<char,int>(t[i],1));
           else
           ++m[t[i]];
       }
       int count=0;
       int start=0;
       map<char,int> m2;
       int i=0;
       for(i=0;i<len_s;i++)
       {
           if(t.find(s[i])==string::npos)
            continue;
           else
           {
               ite=m2.find(s[i]);
               if(ite==m2.end())
               {
                   m2.insert(pair<char,int>(s[i],1));
                   ++count;
               }
               else
               {
                   if(m2[s[i]]<m[s[i]])
                    ++count;
               }
               if(count==len_t)
                break;
           }
       }
    string temp=s.substr(start,i+1);
    int left=start;
    int right=i;
    char x;
    int len=len_s+1;
    m2.clear();
    sum(temp,m2);
    int dis=0;
   // cout<<"   123"<<temp<<endl;
    while(right<len_s)
    {
        if(t.find(temp[left])==string::npos)
            {
                ++left;
                ++dis;
            }
        else
        {
            cout<<temp<<endl;
            if(m2[temp[left]]>m[temp[left]])
            {
                --m2[temp[left]];
                ++left;
                ++dis;
            }
            else
            {
              x=temp[left];
            //  cout<<x<<endl;
              temp=temp.substr(left,right-dis-left+1);
              if(right-dis-left+1<len)
              {
                  res=temp;
                  len=right-dis-left+1;
              }
              ++dis;
              temp=temp.substr(1,right-left-dis);
             cout<<temp<<endl;
            //  ++left;
              while(++right<len_s)
              {
                  temp+=s[right];
                  if(s[right]==x)
                    {
                        m2.clear();
                        sum(temp,m2);
                        left=0;
                        break;
                    }
              }
              cout<<right<<endl;
            }

        }
    }
    return res;
    }
};

int main()
{
    string ss="ADOBECODEBANC";
    string tt="ABC";
    Solution s;
    cout<<s.minWindow(ss,tt)<<endl;
    return 0;
}
