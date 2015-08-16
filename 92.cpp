#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:

    ListNode *reverse_List(ListNode *start,ListNode *stop)
    {
        ListNode *newhead=start;
        ListNode *newcur=newhead;
        ListNode *cur=start->next;
        ListNode *temp;
        while(cur!=stop)
        {
            temp=cur->next;
            cur->next=newcur;
            newcur=cur;
            cur=temp;
        }
        newhead->next=stop;
        return newcur;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
     if(head==NULL||head->next==NULL||m==n)
        return head;
     ListNode *newhead=new ListNode(0);
     ListNode *newcur=newhead;
     newhead->next=head;
     int count=0;
     ListNode *l1;
     ListNode *l2;
     ListNode *l3;
     ListNode *l4;
     ListNode *temp;
     while(newcur)
     {
         ++count;
         if(count==m)
         {
             l1=newcur;
             l2=newcur->next;
         }
         if(count==n)
         {
             l3=newcur->next;
             l4=newcur->next->next;
             break;
         }
         newcur=newcur->next;
     }
     l1->next=reverse_List(l2,l4);
     temp=newhead;
     newhead=newhead->next;
     delete(temp);
     return newhead;
    }
};

int main()
{
    ListNode *x=new ListNode(1);
    ListNode *x1=new ListNode(2);
    x->next=x1;
    ListNode *x2=new ListNode(3);
    x1->next=x2;
    ListNode *x3=new ListNode(4);
    x2->next=x3;
    ListNode *x4=new ListNode(5);
    x3->next=x4;
    Solution s;
    ListNode *res=s.reverseBetween(x,1,5);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
