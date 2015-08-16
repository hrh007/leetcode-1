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
    ListNode *sortList(ListNode *head) {
        if(!head||!head->next)
            return head;
        return mergeSort(head);
    }
    ListNode * mergeSort(ListNode *head){
        if(!head||!head->next)
            return head;
        ListNode *p=head, *q=head, *pre=NULL;
        while(q&&q->next!=NULL){
            q=q->next->next;
            pre=p;
            p=p->next;
        }
        pre->next=NULL;
        ListNode *lhalf=mergeSort(head);
        ListNode *rhalf=mergeSort(p);
        return merge(lhalf, rhalf);
    }
    ListNode * merge(ListNode *lh, ListNode *rh){
        ListNode *temp=new ListNode(0);
        ListNode *p=temp;
        while(lh&&rh){
            if(lh->val<=rh->val){
                p->next=lh;
                lh=lh->next;
            }
            else{
                p->next=rh;
                rh=rh->next;
            }
            p=p->next;
        }
        if(!lh)
            p->next=rh;
        else
            p->next=lh;
        p=temp->next;
        temp->next=NULL;
        delete temp;
        return p;
    }
};

class Solution2 {
public:

     void mergeList(ListNode *begin_l1,ListNode *end_l1,ListNode *begin_l2,ListNode *end_l2)
    {
        ListNode *temp1;
        ListNode *temp2;
        ListNode *test=begin_l1;
        ListNode *cur;
        if(begin_l1->val<begin_l2->val)
        {
            cur=begin_l1;
            test=cur;
            begin_l1=begin_l1->next;
        }
        else
        {
            cur=begin_l2;
            test=cur;
            begin_l2=begin_l2->next;
        }
        while(begin_l1!=end_l1&&begin_l2!=end_l2)
        {
            if(begin_l1->val<begin_l2->val)
            {
                cur->next=begin_l1;
                begin_l1=begin_l1->next;
                cur=cur->next;
            }
            else
            {
                cur->next=begin_l2;
                begin_l2=begin_l2->next;
                cur=cur->next;
            }
        }
        while(begin_l2!=end_l2)
        {
            cur->next=begin_l2;
            cur=cur->next;
            begin_l2=begin_l2->next;
        }
        while(begin_l1!=end_l1)
        {
            cur->next=begin_l1;
            cur=cur->next;
            begin_l1=begin_l1->next;
        }
        cur->next=end_l2;
        begin_l1=test;
       while(test!=end_l2)
       {
          cout<<"123    "<<test->val<<endl;
           test=test->next;
       }
       cout<<endl;
    }
    void mergesort(ListNode *begin_list,ListNode *end_list)
    {
        if(begin_list->next==end_list)
            {
                return ;
            }
        else
        {
            int sum=0;
            ListNode *cur=begin_list;
            while(cur!=end_list)
            {
                ++sum;
                cur=cur->next;
            }
            int count=0;
            cur=begin_list;
            ListNode *temp;
            while(cur)
            {
                ++count;
                cur=cur->next;
                temp=cur;
                if(count==sum/2)
                    break;
            }
           // cout<<count<<endl;
           // cout<<temp->val<<endl;
            mergesort(begin_list,temp);
            mergesort(temp,end_list);
            mergeList(begin_list,temp,temp,end_list);
        }
    }

    ListNode* sortList(ListNode* head) {
    if(head==NULL)
        return head;
    int sum=0;
    ListNode *cur=head;
    while(cur)
    {
        ++sum;
        cur=cur->next;
    }
  //  cout<<sum<<endl;
    if(sum==1)
        return head;
    cur=head;
    ListNode *end_l1;
    //ListNode *begin_l2;
    int count=0;
    while(cur)
    {
        ++count;
        cur=cur->next;
        end_l1=cur;
        if(count==sum/2)
            break;
    }
   // cout<<count<<endl;
   // cout<<end_l1->val<<endl;
    mergesort(head,end_l1);
    mergesort(end_l1,NULL);
    mergeList(head,end_l1,end_l1,NULL);
    return head;
    }
};


int main()
{
    ListNode *x=new ListNode(2);
    ListNode *x1=new ListNode(1);
    x->next=x1;
    ListNode *x2=new ListNode(0);
    x1->next=x2;
    Solution s;
    ListNode  *res=s.sortList(x);
    while(res)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}
