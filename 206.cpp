#include <iostream>

using namespace std;

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:

    ListNode *trans(ListNode *node,ListNode *&newhead)
    {
        if(node->next==NULL)
        {
            newhead=new ListNode(node->val);
            return newhead;
        }
        else
        {
            ListNode *temp=new ListNode(node->val);
            trans(node->next,newhead)->next=temp;
            return temp;
        }
    }
    ListNode* reverseList(ListNode* head) {
    ListNode *newhead;
    ListNode *tail;
    if(head==NULL)
        return NULL;
   // tail=new ListNode(head->val);
   // tail->next=NULL;
    trans(head,newhead)->next=NULL;
    return newhead;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode *x=head;
    if(head==NULL)
        return NULL;
    ListNode * temp;
    ListNode * newhead=new ListNode(head->val);
    newhead->next=NULL;
    head=head->next;
    while(head)
    {
        temp=new ListNode(head->val);
        temp->next=head->next;
        head->next=newhead;
        newhead=head;
        head=temp->next;
    }
    return newhead;
    }
};

int main()
{

    Solution s;
    ListNode *head=new ListNode(1);
    ListNode *h2=new ListNode(2);
    h2->next=new ListNode(3);
    head->next=h2;
    ListNode *res=s.reverseList(head);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
