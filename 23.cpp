#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class com{
public :
    com(){}
    bool operator() (const ListNode *l1,const ListNode *l2) const {
    return l1->val>l2->val;
    }
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int len=lists.size();
        if(len==0)
            return NULL;
        if(len==1)
            return lists[0];
        priority_queue<ListNode*,vector<ListNode *>,com> pq;
        for(int i=0;i<len;++i)
        {
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode *newhead=new ListNode(0);
        ListNode *cur=newhead;
        ListNode *temp;
        while(!pq.empty())
        {
            temp=pq.top();
            pq.pop();
            cur->next=temp;
            cur=cur->next;
            temp=temp->next;
            if(temp)
                pq.push(temp);
        }
        temp=newhead;
        newhead=newhead->next;
        delete temp;
        temp=NULL;
        return newhead;
    }
};

int main()
{

    return 0;
}
