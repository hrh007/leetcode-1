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
    else
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

int main()
{

    return 0;
}
