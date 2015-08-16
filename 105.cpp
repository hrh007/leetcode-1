#include <iostream>
#include <vector>

using namespace std;


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
    TreeNode *build(vector<int> &preorder,int start1,int end1,vector<int> &inorder,int start2,int end2)
    {
        TreeNode  *temp=new TreeNode(preorder[start1]);
        int i;
        if(start1!=end1)
        {
            for(i=start2; i<=end2; i++)
                if(preorder[start1]==inorder[i])
                       break;
            if(i-1>=start2)
                    temp->left= build(preorder,start1+1,start1+i-start2,inorder,start2,i-1);
            if(i+1<=end2)
                    temp->right=build(preorder,start1+i-start2+1,end1,inorder,i+1,end2);
        }
        return temp;

    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if(preorder.size()==0)
            return NULL;
        else
        {

            TreeNode* tree;
            tree=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
            return tree;
        }
    }
};

void output(TreeNode *tree)
{
    if(tree==NULL)
        return ;
    else
    {

        output(tree->left);

        output(tree->right);
        cout<<tree->val<<endl;

    }
}

int main()
{
    Solution s;
    vector<int> preorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(6);
    preorder.push_back(7);
    preorder.push_back(3);
    preorder.push_back(8);
    preorder.push_back(10);
    preorder.push_back(9);
    vector<int> inorder;
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(6);
    inorder.push_back(5);
    inorder.push_back(7);
    inorder.push_back(1);
    inorder.push_back(8);
    inorder.push_back(10);
    inorder.push_back(3);
    inorder.push_back(9);
    TreeNode* tree=s.buildTree(preorder,inorder);
    output(tree);
    return 0;

}
