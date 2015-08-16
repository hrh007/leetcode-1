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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL)
            return NULL;
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* last;
        int sum=0;
        while(temp1)
        {
            ++sum;
            temp1=temp1->next;
        }
        // cout<<sum<<endl;;
         k=k%sum;
       //  cout<<k<<endl;
         if(k==0)
            return head;
        temp1=head;
        int count=0;
        while(temp1)
        {
            ++count;
            if(count==k)
                break;
            //last=temp1;
            temp1=temp1->next;;
        }
          ListNode *newhead;
        if(temp1==NULL)
        {
            return head;
        }
        if(temp1->next==NULL)
            return head;

        while(temp1->next)
        {
            temp1=temp1->next;
            last=temp2;
            temp2=temp2->next;
        }
        last->next=NULL;
        // cout<<last->val<<endl;
      //  cout<<temp2->val<<endl;
        newhead=temp2;
        while(temp2->next)
        {
            temp2=temp2->next;
        }
        temp2->next=head;
        return newhead;
    }
};

int main()
{

    Solution s;
    ListNode *x=new ListNode(1);
    ListNode *x1=new ListNode(2);
    x->next=x1;
    ListNode *x2=new ListNode(3);
    x1->next=x2;
  //  ListNode *x3=new ListNode(4);
  //  x2->next=x3;
  //  ListNode *x4=new ListNode(5);
  //  x3->next=x4;
    ListNode * res=s.rotateRight(x, 2000000000);
    while(res)
    {
        cout<<"   "<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
