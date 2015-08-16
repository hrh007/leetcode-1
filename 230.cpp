#include <iostream>
#include <vector>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

    void cal(TreeNode *root,vector<int> &temp)
    {
        if(root==NULL)
            return ;
        else
        {
            cal(root->left,temp);
            temp.push_back(root->val);
            cal(root->right,temp);
        }
    }

    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> temp;
        cal(root,temp);
        return temp[k];
    }
};

int main()
{

    return 0;
}
