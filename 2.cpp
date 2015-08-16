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

    ListNode *reverse_List(ListNode *head)
    {
        ListNode *cur=head;
        ListNode *newhead=head;
        cur=cur->next;
        head->next=NULL;
        ListNode *newcur=newhead;
        ListNode *temp;
        while(cur)
        {
            temp=cur->next;
            cur->next=newcur;
            newcur=cur;
            cur=temp;
        }
        return newcur;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
       // ListNode *rl1=reverse_List(l1);
       // ListNode *rl2=reverse_List(l2);
        ListNode *rl1=l1;
        ListNode *rl2=l2;
        ListNode *newhead=new ListNode(0);
        ListNode *newcur=newhead;
        int count=0;
        int sum=0;
        while(rl1&&rl2)
        {
            sum=rl1->val+rl2->val+count;
            count=sum/10;
            sum=sum%10;
            ListNode *temp=new ListNode(sum);
            newcur->next=temp;
            newcur=newcur->next;
            rl1=rl1->next;
            rl2=rl2->next;
        }
        while(rl1)
        {
            sum=rl1->val+count;
            count=sum/10;
            sum=sum%10;
            ListNode *temp=new ListNode(sum);
            newcur->next=temp;
            newcur=newcur->next;
            rl1=rl1->next;
        }
        while(rl2)
        {
            sum=rl2->val+count;
            count=sum/10;
            sum=sum%10;
            ListNode *temp=new ListNode(sum);
            newcur->next=temp;
            newcur=newcur->next;
            rl2=rl2->next;
        }
        if(count!=0)
        {
            ListNode *temp=new ListNode(count);
            newcur->next=temp;
            newcur=newcur->next;
        }
        newcur->next=NULL;
        ListNode *temp;
        temp=newhead;
        newhead=newhead->next;
        delete(temp);
        return newhead;
    }
};

int main()
{

    ListNode *l1=new ListNode(5);
    ListNode *l2=new ListNode(5);
    Solution s;
    ListNode *res=s.addTwoNumbers(l1,l2);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
