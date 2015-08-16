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

    ListNode * reserve(ListNode *head)
    {
        ListNode *newhead=head;
        head=head->next;
        newhead->next=NULL;
        ListNode *temp;
        while(head)
        {
            temp=head->next;
            head->next=newhead;
            newhead=head;
            head=temp;
        }
        return newhead;
    }

    void reorderList(ListNode* head) {
     ListNode *cur=head;
     int sum=0;
     while(cur)
     {
         ++sum;
         cur=cur->next;
     }
     if(sum<=2)
        return ;
     if(sum%2==0)
        sum=sum/2;
     else
        sum=sum/2+1;
    int count=0;
    cur=head;
    while(cur)
    {
            ++count;
        if(count>sum)
            break;
              cur=cur->next;
    }
    ListNode *start2=reserve(cur);
      ListNode *start1=head;
     while(start1)
    {
        if(start1->next==cur)
            start1->next=NULL;
        start1=start1->next;
    }
    start1=head;
    ListNode *temp1;
    ListNode *temp2;
    while(start1&&start2)
    {
        temp1=start1->next;
       // cout<<"123   "<<temp1->val<<endl;
        start1->next=start2;
       // cout<<"123   "<<start1->next->val<<endl;
        temp2=start2->next;
      //  cout<<"123   "<<temp2->val<<endl;
        start2->next=temp1;
      //  cout<<"123   "<<start2->next->val<<endl;
        start1=temp1;
      //  cout<<"123   "<<start1->val<<endl;
        start2=temp2;
     //   cout<<"123   "<<start2->val<<endl;
    }
    }
};

int main()
{
    ListNode * x=new ListNode(1);
    ListNode * x1=new ListNode(2);
    x->next=x1;
    //ListNode * x2=new ListNode(3);
   // x1->next=x2;
   // ListNode * x3=new ListNode(4);
   // x2->next=x3;
   // ListNode *x4=new ListNode(5);
   // x3->next=x4;
    Solution s;
    s.reorderList(x);
    while(x)
    {
        cout<<x->val<<endl;
        x=x->next;
    }
    return 0;
}
