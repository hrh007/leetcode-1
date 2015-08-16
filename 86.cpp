#include <iostream>

using namespace std;


//      Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
       ListNode *newhead1=new ListNode(0);
       ListNode *newhead2=new ListNode(0);
       ListNode *cur=head;
       ListNode *newcur1=newhead1;
       ListNode *newcur2=newhead2;
       while(cur)
       {
           if(cur->val<x)
           {
               newcur1->next=cur;
               newcur1=newcur1->next;
           }
           else
           {
               newcur2->next=cur;
               newcur2=newcur2->next;
           }
           cur=cur->next;
       }
       ListNode *temp;
       newcur2->next=NULL;
       temp=newhead2->next;
       newcur1->next=temp;
       delete(newhead2);
       temp=newhead1->next;
       delete(newhead1);
       return temp;
    }
};

int main()
{
    ListNode *x=new ListNode(1);
   // ListNode *x1=new ListNode(3);
   // x->next=x1;
   // ListNode *x2=new ListNode(2);
  //  x1->next=x2;
  //  ListNode *x3=new ListNode(3);
  //  x2->next=x3;
  //  ListNode *x4=new ListNode(4);
  //  x3->next=x4;
    Solution s;
    ListNode *res=s.partition(NULL,3);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
