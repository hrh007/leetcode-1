#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    void change(vector<int> &num,int left,int right)
    {
        int temp;
        for(int i=right-1; i>=left; i--)
        {
            for(int j=right; j>i; j--)
            {
                if(num[j]>num[i])
                {
                    temp=num[j];
                    num[j]=num[i];
                    num[i]=temp;
                    for(int i=0; i<num.size(); i++)
                        cout<<"   "<<num[i];
                    cout<<endl;
                    change(num,i+1,j);
                    return ;
                }
            }
        }
    }

    void nextPermutation(vector<int> &num)
    {
        int right=num.size();
        int count=0;
        int temp;
        change(num,0,right-1);
        //  for(int i=0; i<right/2; i++)
        //  {
        //     temp=num[i];
        //      num[i]=num[right-1-i];
        //     num[right-1-i]=temp;
        //   }
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    Solution s;
    s.nextPermutation(test);
    for(int i=0; i<test.size(); i++)
        cout<<"   "<<test[i];
    cout<<endl;
    return 0;
}
