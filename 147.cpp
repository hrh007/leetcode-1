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
    ListNode* insertionSortList(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        ListNode *cur=head;
        ListNode *newhead=head;
        cur=cur->next;
        newhead->next=NULL;
        ListNode *newcur=newhead;
        ListNode *temp;
        ListNode *temp2;
        while(cur)
        {
            if(cur->val==newcur->val)
            {
                temp2=newcur->next;
                newcur->next=cur;
                temp=cur->next;
                cur->next=temp2;
                cur=temp;
            }
            else
            {
                if(cur->val<newcur->val)
                    newcur=newhead;
                while(newcur)
                {
                    if(cur->val<newcur->val)
                    {
                        if(newcur==newhead)
                        {
                            temp=cur->next;
                            cur->next=newhead;
                            newhead=cur;
                            cur=temp;
                        }
                        else
                        {
                            temp=cur->next;
                            temp2->next=cur;
                            cur->next=newcur;
                            cur=temp;
                        }
                        break;;
                    }
                     temp2=newcur;
                            newcur=newcur->next;
                }
                if(newcur==NULL)
                {
                    temp=cur->next;
                    cur->next=NULL;
                    temp2->next=cur;
                    newcur=cur;
                    cur=temp;
                }
            }
        }
        return newhead;
    }
};

int main()
{
    Solution s;
    ListNode *x=new ListNode(0);
    ListNode *x1=new ListNode(2);
    x->next=x1;
    ListNode *x2=new ListNode(1);
    x1->next=x2;
    ListNode *res=s.insertionSortList(x);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
