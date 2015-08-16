#include <iostream>
#include <vector>

using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode*cur=head;
    int i=0;
    while(cur)
    {
     i++;
     cur=cur->next;
    }
    if(i==1)
        return NULL;
    cur=head;
    n=i-n;
    if(n==0)
    {
           ListNode * temp=head;
            head=head->next;
            delete(temp);
             return head;
    }
    i=0;
    while(cur)
    {
        i++;
        if(n==i)
        {
            ListNode * temp=cur->next;
            cur->next=cur->next->next;
            delete(temp);
             return head;
        }
        cur=cur->next;

    }
    }
};

int main()
{

    return 0;
}
