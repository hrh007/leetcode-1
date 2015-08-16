#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        int sum=0;
        vector<int> num;
        vector<char> sign;
        int len=input.size();
        int x=0;
        int y=0;
        vector<int> res;
        while(x<len)
        {
            if(input[x]>='0'&&input[x]<='9')
            {
                y=0;
                while(x<len&&input[x]>='0'&&input[x]<='9')
                {
                    y=y*10+input[x]-48;
                    ++x;
                }
                num.push_back(y);
                ++sum;
            }
            else if(input[x]==' ')
                ++x;
            else
            {
                sign.push_back(input[x]);
                ++x;
            }
        }
        vector<vector<multiset<int> > > temp;
        multiset<int> temp_set;
        vector<multiset<int> >temp_vec;
        for(int i=0; i<sum; ++i)
            temp_vec.push_back(temp_set);
        for(int i=0; i<sum; ++i)
            temp.push_back(temp_vec);
        for(int i=0; i<sum; ++i)
            temp[i][i].insert(num[i]);
        for(int i=1; i<sum; ++i)
        {
            if(sign[i-1]=='+')
                temp[i-1][i].insert(num[i-1]+num[i]);
            else if(sign[i-1]=='-')
                temp[i-1][i].insert(num[i-1]-num[i]);
            else
                temp[i-1][i].insert(num[i-1]*num[i]);
        }
        for(int i=2; i<sum; ++i)
        {
            for(int j=0; j+i<sum; ++j)
            {
                multiset<int>::iterator ite=temp[j][j].begin();
                for(multiset<int>::iterator ite2=temp[j+1][i+j].begin(); ite2!=temp[j+1][i+j].end(); ++ite2)
                {
                    if(sign[j]=='+')
                        temp[j][i+j].insert(*ite+(*ite2));
                    else if(sign[j]=='-')
                        temp[j][i+j].insert(*ite-(*ite2));
                    else
                        temp[j][i+j].insert(*ite*(*ite2));
                    }
                ite=temp[i+j][i+j].begin();
                for(multiset<int>::iterator ite2=temp[j][i+j-1].begin(); ite2!=temp[j][i+j-1].end(); ++ite2)
                {
                    if(sign[i+j-1]=='+')
                        temp[j][i+j].insert(*ite2+(*ite));
                    else if(sign[j+i-1]=='-')
                        temp[j][i+j].insert(*ite2-(*ite));
                    else
                        temp[j][i+j].insert(*ite2*(*ite));
                    }
                for(int k=j+1; k<i+j-1; ++k)
                {
                    for(multiset<int>::iterator ite2=temp[j][k].begin(); ite2!=temp[j][k].end(); ++ite2)
                    {
                        for(multiset<int>::iterator ite3=temp[k+1][j+i].begin(); ite3!=temp[k+1][j+i].end(); ++ite3)
                        {
                            if(sign[k]=='+')
                                temp[j][i+j].insert(*ite2+(*ite3));
                            else if(sign[k]=='-')
                                temp[j][i+j].insert(*ite2-(*ite3));
                            else
                                temp[j][i+j].insert(*ite2*(*ite3));
                            }
                    }
                }
            }
        }
        for(multiset<int>::iterator ite2=temp[0][sum-1].begin();ite2!=temp[0][sum-1].end();++ite2)
            res.push_back(*ite2);
        return res;
    }
};

int main()
{
    Solution s;
    string temp("2-1-1-1-1");
    vector<int> res=s.diffWaysToCompute(temp);
    cout<<endl;
    for(int i=0;i<res.size();++i)
        cout<<res[i]<<endl;
    return 0;
}
