#include <iostream>
#include <vector>
#include <map>
#include <cstring>


using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
     int len=s.size();
     if(len==0)
            return true;
     map<char,char> temp1;
     map<char,char> temp2;
      map<char,char>::iterator ite1;
      map<char,char>::iterator ite2;
      for(int i=0;i<len;i++)
      {
          ite1=temp1.find(s[i]);
          ite2=temp2.find(t[i]);
          if(ite1==temp1.end()&&ite2==temp2.end())
          {
              temp1.insert(pair<char,char>(s[i],t[i]));
              temp2.insert(pair<char,char>(t[i],s[i]));
          }
          else if(ite1!=temp1.end()&&ite2!=temp2.end())
          {
              if(ite1->second!=t[i]||ite2->second!=s[i])
                return false;
          }
          else
            return false;
      }
      return true;
    }
};

int main()
{
    Solution s;
    string ss="bbaacc";
    string tt="aabbcb";
    cout<<s.isIsomorphic(ss,tt)<<endl;
    return 0;
}
