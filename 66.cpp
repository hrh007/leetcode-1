#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
       int temp=1;
       for(int i=digits.size()-1;i>=0;i--)
       {
           temp+=digits[i];
            digits[i]=temp%10;
            temp=temp/10;
           if(temp==0)
           {
               return digits;
           }
       }
       digits.insert(digits.begin(),1);
       return digits;
    }
};

class Solution2 {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        int temp=digits[digits.size()-1]+1;
            res.push_back(temp%10);
            temp=temp/10;
        for(int i=digits.size()-2;i>=0;i--)
        {
            temp+=digits[i];
            res.insert(res.begin(),temp%10);
            temp=temp/10;
        }
        if(temp!=0)
            res.insert(res.begin(),temp);
        return res;
    }
};

int main()
{
    Solution s;
   vector<int> temp;
   temp.push_back(9);
   temp.push_back(9);
   temp.push_back(1);
   temp.push_back(9);
   temp.push_back(9);
   vector<int> res=s.plusOne(temp);
   for(int i=0;i<res.size();i++)
    cout<<res[i];
   cout<<endl;
    return 0;
}
