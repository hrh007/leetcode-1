#include <iostream>

using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    ListNode *temp;
    ListNode *cur=new  ListNode(0);
    cur->next=head;
    head=cur;
    while(cur->next)
    {
        if(cur->next->val==val)
        {
            temp=cur->next;
            cur->next=cur->next->next;
            delete(temp);
        }
        else
        cur=cur->next;
    }
   // cout<<newhead->next->val<<endl;
    return head->next;
    }
};

int main()
{
    ListNode * n1=new ListNode(1);
    n1->next=new ListNode(1);
    Solution s;
    ListNode *res=s.removeElements(n1,2);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
