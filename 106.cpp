#include <iostream>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* build(vector<int> & inorder, vector<int> & postorder,int in_left ,int in_right,int post_left,int post_right)
    {

       // cout<<in_left<<"   "<<in_right<<"   "<<post_left<<"   "<<post_right<<"    123"<<endl;
        if(post_left>post_right)
            return NULL;
        else
        {
            TreeNode *node=new TreeNode(postorder[post_right]);
            int i;
            for(i=in_left;i<=in_right;i++)
                if(inorder[i]==postorder[post_right])
                break;
            node->left=build(inorder,postorder,in_left,i-1,post_left,post_left+i-1-in_left);
            node->right=build(inorder,postorder,i+1,in_right,post_left+i-in_left,post_right-1);
            return node;
        }
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};

void output(TreeNode * tree)
{
    if(tree==NULL)
        return ;
    else
    {
        cout<<tree->val<<endl;
        output(tree->left);
        output(tree->right);
    }
}

int main()
{
    vector<int> inorder;
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(6);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(3);
    inorder.push_back(10);
    inorder.push_back(8);
    inorder.push_back(7);
    inorder.push_back(9);
        vector<int> postorder;
    postorder.push_back(4);
    postorder.push_back(6);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(10);
    postorder.push_back(8);
    postorder.push_back(9);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    Solution s;
    TreeNode *tree=s.buildTree(inorder,postorder);
    cout<<"____________________"<<endl;
    output(tree);
    return 0;
}
