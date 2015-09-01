#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

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

    string intToString(int x)
    {
        stringstream ss;
        ss<<x;
        string res;
        ss>>res;
        return res;
    }

    string dequeToString(deque<int> origin)
    {
        deque<int>::iterator ite=origin.begin();
        string res=intToString(*ite);
        ++ite;
        for(; ite!=origin.end(); ++ite)
        {
            res+="->";
            res+=intToString(*ite);
        }
        return res;
    }

    void cal(TreeNode* root,vector<string> &res,deque<int> &temp)
    {

        if(root->left==NULL&&root->right==NULL)
        {
            temp.push_back(root->val);
            res.push_back(dequeToString(temp));
            temp.pop_back();
            return ;
        }
        temp.push_back(root->val);
        if(root->left)
            cal(root->left,res,temp);
        if(root->right)
            cal(root->right,res,temp);
        temp.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        if(root==NULL)
            return res;
        deque<int> temp;
        cal(root,res,temp);
        return res;
    }
};

int main()
{

    return 0;
}
