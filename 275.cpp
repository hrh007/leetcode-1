#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
         int sum=citations.size();
        int left=0;
        int right=sum-1;
        while(left<=right)
        {
            int mid=(right+left)/2;
            if(sum-mid==citations[mid])
                return sum-mid;
            else if(sum-mid<citations[mid])
                right=mid-1;
            else
                left=mid+1;
        }
        return sum-left;
    }
};

int main()
{

    return 0;
}
