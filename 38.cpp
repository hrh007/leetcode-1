#include <iostream>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string s1="1";
        char temp[10000];
        int count;
        int k;
        if(n==1)
        {
            return "1";
        }
        else
        {
            for(int j=2; j<=n; j++)
            {
                k=0;
                for(int i=0; i<s1.length(); i+=count)
                {
                    count=1;
                    while(s1[i]==s1[i+count]&&i+count<s1.length())
                    {
                        count++;
                    }
                    temp[k++]=count+48;
                    temp[k++]=s1[i];
                }
                temp[k]='\0';
                cout<<temp<<endl;
               s1=temp;
            }
             return temp;
        }
    }
};

int  main()
{

    Solution s;
    cout<<s.countAndSay(25)<<endl;
    return 0;
}
