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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
            return NULL;
    if(head->next==NULL)
        return head;
    ListNode *temp;
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
      ListNode *cur=newhead;
    while(cur->next)
    {
        if(cur->next->next&&cur->next->val==cur->next->next->val)
        {
            while(cur->next->next&&cur->next->val==cur->next->next->val)
            {
                temp=cur->next->next;
                cur->next->next=cur->next->next->next;
                delete(temp);

            }
            temp=cur->next;
            cur->next=cur->next->next;
            delete(temp);
        }
        else
            cur=cur->next;
    }
    temp=newhead;
    newhead=newhead->next;
    delete(temp);
    return newhead;
    }
};

int main()
{


    return 0;
}
