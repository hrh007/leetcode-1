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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if(l1==NULL&&l2==NULL)
         return NULL;
     else if(l1==NULL&&l2!=NULL)
        return l2;
     else if(l2==NULL&&l1!=NULL)
        return l1;
     else
     {
         ListNode *newhead=new ListNode(0);
         ListNode *cur=newhead;
         while(l1&&l2)
         {
             if(l1->val<l2->val)
             {
                 cur->next=l1;
                 cur=cur->next;
                 l1=l1->next;
             }
             else
             {
                 cur->next=l2;
                 cur=cur->next;
                 l2=l2->next;
             }
         }
         if(l1==NULL)
         {
             while(l2)
             {
                 cur->next=l2;
                 cur=cur->next;
                 l2=l2->next;
             }
         }
         if(l2==NULL)
         {
             while(l1)
             {
                 cur->next=l1;
                 cur=cur->next;
                 l1=l1->next;
             }
         }
           return newhead->next;
     }

    }
};

int main()
{

    return 0;
}
