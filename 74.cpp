#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      int left=0;
      int rows=matrix.size();
      int right=matrix[0].size()-1;
      while(left<rows&&right>=0)
      {
          if(target==matrix[left][right])
            return true;
          else if(target<matrix[left][right])
            right--;
          else
            left++;
      }
      return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
       int rows=matrix.size();
       int cloums=matrix[0].size();
       int up=0;
       int down=rows-1;
       int mid=0;
       int row=0;
       int left=0;
       int right=cloums-1;
       while(up<down)
       {
           mid=(up+down)/2;
           if(matrix[mid][0]==target)
            return true;
            else if(matrix[mid][0]<target)
                up=mid+1;
            else
                down=mid-1;
       }
       if(cloums-1>=0&&matrix[up][0]<=target&&matrix[up][cloums-1]>=target)
        row=up;
       if(up-1>=0&&cloums-1>=0&&matrix[up-1][0]<=target&&matrix[up-1][cloums-1]>=target)
        row=up-1;
       if(up+1<rows&&cloums-1>=0&&matrix[up+1][0]<=target&&matrix[up+1][cloums-1]>=target)
        row=up+1;
       while(left<=right)
       {
           mid=(left+right)/2;
           if(matrix[row][mid]==target)
            return true;
           else if(matrix[row][mid]<target)
            left=mid+1;
           else
            right=mid-1;
       }
       return false;
    }
};

int main()
{
    vector<vector<int> >test;
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(1);
    test.push_back(test1);
    Solution s;
    cout<<s.searchMatrix(test,0)<<endl;
    return 0;
}
