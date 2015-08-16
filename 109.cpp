#include <iostream>


using namespace std;


//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        else
        {
            ListNode *fast=head;
            ListNode *slow=head;
            ListNode *last=head;
            while(fast->next&&fast->next->next)
            {
                fast=fast->next->next;
                last=slow;
                slow=slow->next;
            }
            ListNode *newhead=last->next;
            last->next=NULL;
            TreeNode *tree=new TreeNode(newhead->val);
            tree->left=sortedListToBST(head);
            tree->right=sortedListToBST(newhead->next);
            return tree;
        }

    }
};

int main()
{

    return 0;
}
