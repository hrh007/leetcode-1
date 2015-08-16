#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class Solution2
{

public:
    int rob(vector<int> &num)
    {
       int a=0;
       int b=0;
       for(int i=0;i<num.size();i++)
       {
           if(i%2==0)
           {
               a+=num[i];
               if(a<b)
                a=b;
           }
           else
           {
               b+=num[i];
               if(b<a)
                b=a;
           }
       }
      if(a<b)
        return b;
      else
        return a;
    }
};

class Solution
{

public:
    int rob(vector<int> &num)
    {
        if(num.size()==0)
            return 0;
        else
        {
            int arr1[num.size()];
            int arr2[num.size()];
            arr1[0]=0;
            arr2[0]=num[0];
            for(int i=1; i<num.size(); i++)
            {
                  arr2[i]=arr1[i-1]+num[i];
                  if(arr1[i-1]>=arr2[i-1])
                  arr1[i]=arr1[i-1];
                  else
                    arr1[i]=arr2[i-1];
            }
            if(arr1[num.size()-1]>=arr2[num.size()-1])
                return arr1[num.size()-1];
            else
                return arr2[num.size()-1];
        }
    }
};

int main()
{
    Solution2 s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(100);
    vec.push_back(100);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(100);
    vec.push_back(100);
    vec.push_back(3);
    vec.push_back(1);
    cout<<s.rob(vec)<<endl;
    return 0;
}
