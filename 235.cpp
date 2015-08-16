#include<iostream>

using namespace std;

// Definition for a binary tree node.
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

    TreeNode* cal(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root->val>q->val)
            return cal(root->left,p,q);
        else if(root->val<p->val)
            return cal(root->right,p,q);
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(p==q)
            return p;
        else
        {
            if(p->val>q->val)
                return cal(root,q,p);
            else
                return cal(root,p,q);
        }
    }
};

int main()
{

    return 0;
}
