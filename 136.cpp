#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
            map<int,int> temp;
            map<int,int>::iterator ite;
            int len=nums.size();
            for(int i=0;i<len;i++)
            {
                ite=temp.find(nums[i]);
                if(ite==temp.end())
                    temp.insert(pair<int,int>(nums[i],0));
                else
                    ite->second++;
            }
            for(ite=temp.begin();ite!=temp.end();ite++)
            {
                if(ite->second==0)
                    return ite->first;
            }
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
           int len=nums.size();
           if(len==0)
            return 0;
           int res=nums[0];
           for(int i=1;i<len;i++)
           {
               res=res^nums[i];
           }
           return res;
    }
};


int main()
{

    return 0;
}
