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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *newhead1=new ListNode(0);
        ListNode *newhead2=new ListNode(0);
        ListNode *cur=head;
        ListNode *newcur1=newhead1;
        ListNode *newcur2=newhead2;
        ListNode *temp;
        if(cur==NULL)
            return NULL;
        if(cur->next==NULL)
            return head;
        while(cur&&cur->next)
        {
            newcur1->next=cur;
            newcur1=newcur1->next;
            newcur2->next=cur->next;
            newcur2=newcur2->next;
            cur=cur->next->next;
        }
        if(cur!=NULL)
        {
            newcur1->next=cur;
            newcur1=newcur1->next;
        }
        newcur1->next=NULL;
        newcur2->next=NULL;
        temp=newhead1;
        newhead1=newhead1->next;
        delete(temp);
        temp=newhead2;
        newhead2=newhead2->next;
        delete(temp);
        ListNode *res=new ListNode(0);
        newcur1=newhead1;
        newcur2=newhead2;
        cur=res;
        while(newcur2)
        {
           cur->next=newcur2;
           temp=newcur2->next;
           cur->next->next=newcur1;
           cur=cur->next->next;
           newcur2=temp;
           newcur1=newcur1->next;
        }
        if(newcur1!=NULL)
            {
                cur->next=newcur1;
                cur=cur->next;
            }
        cur->next=NULL;
        temp=res;
        res=res->next;
        delete(temp);
        return res;
    }
};

int main()
{
    ListNode *x=new ListNode(1);
    ListNode *x1=new  ListNode(2);
    x->next=x1;
    ListNode *x2=new ListNode(3);
    x1->next=x2;
    Solution s;
    ListNode *res=s.swapPairs(x);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
