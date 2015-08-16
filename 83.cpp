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
     ListNode *cur=head;
     ListNode *temp;
     while(cur->next)
     {
         if(cur->val==cur->next->val)
         {
             temp=cur->next;
             cur->next=cur->next->next;
             delete(temp);
         }
         else
            cur=cur->next;
     }
     return head;
    }
};

int main()
{

    return 0;
}
