#include <iostream>

using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int countNodes(TreeNode* root) {
    if(root==NULL)
        return 0;
    int l=1;
    int r=1;
    TreeNode *tempLeft=root;
    TreeNode *tempRight=root;
    while(tempLeft)
    {
        tempLeft=tempLeft->left;
        ++l;
    }
    while(tempRight)
    {
        tempRight=tempRight->right;
        ++r;
    }
    if(l==r)
        return 1<<l-1;
    else
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

int main()
{

    return 0;
}
