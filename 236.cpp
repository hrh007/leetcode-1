#include <iostream>
#include <vector>
#include <deque>

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

    void getList(TreeNode *root,TreeNode *p,TreeNode * q,deque<TreeNode*> &dq1,deque<TreeNode*> &dq2,deque<TreeNode*> &temp)
    {
        if(root==NULL)
            return ;
        else
        {
            temp.push_back(root);
            if(root==p)
                dq1=temp;
            if(root==q)
                dq2=temp;
            getList(root->left,p,q,dq1,dq2,temp);
            getList(root->right,p,q,dq1,dq2,temp);
            temp.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        deque<TreeNode*> dq1;
        deque<TreeNode*> dq2;
        deque<TreeNode*> temp;
        getList(root,p,q,dq1,dq2,temp);

        int sum1=dq1.size();
        int sum2=dq2.size();
        int x=sum1-sum2;
        deque<TreeNode*>::reverse_iterator ite1=dq1.rbegin();
        deque<TreeNode*>::reverse_iterator ite2=dq2.rbegin();
        if(x>0)
            for(int i=0; i<x; ++i)
                ++ite1;
        else
            for(int i=0; i<(-x); ++i)
                ++ite2;
        while(ite1!=dq2.rend())
        {
            if(*ite1==*ite2)
                return *ite1;
            else
            {
                ++ite1;
                ++ite2;
            }
        }
    }
};

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    Solution s;
    TreeNode *res=s.lowestCommonAncestor(root,root->right,root->left);
    cout<<res->val<<endl;
    return 0;
}
