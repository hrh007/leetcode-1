#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        vector<set<string> > vec1;
        if(n==0)
            return res;
        if(n==1)
        {
            res.push_back("()");
            return res;
        }
        if(n==2)
        {
            res.push_back("()()");
            res.push_back("(())");
            return res;
        }
        set<string> set1;
        set1.insert("()");
        vec1.push_back(set1);
        set1.clear();
        set1.insert("()()");
        set1.insert("(())");
        vec1.push_back(set1);
        set1.clear();
        set<string> set2;
        set<string> temp;
        string s1;
        string s2;
        for(int i=3; i<=n; ++i)
        {
            temp.clear();
            for(int j=0;j<i-1;++j)
            {
                set1=vec1[j];
                set2=vec1[i-2-j];
                for(set<string>::iterator ite1=set1.begin();ite1!=set1.end();++ite1)
                {
                    for(set<string>::iterator ite2=set2.begin();ite2!=set2.end();++ite2)
                    {
                        temp.insert(*ite1+*ite2);
                    }
                }
            }
            for(set<string>::iterator ite=vec1[i-2].begin();ite!=vec1[i-2].end();++ite)
            {
                s1=*ite;
                s1.append(1,')');
                s1.insert(0,1,'(');
                temp.insert(s1);
            }
            vec1.push_back(temp);
        }
        for(set<string>::iterator ite=vec1[n-1].begin();ite!=vec1[n-1].end();++ite)
            res.push_back(*ite);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res=s.generateParenthesis(4);
    for(int i=0;i<res.size();++i)
        cout<<res[i]<<endl;
    return 0;
}
