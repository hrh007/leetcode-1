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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *res;
        ListNode *curA=headA;
        ListNode *curB=headB;
        ListNode *lastA;
        ListNode *lastB;
        int sumA=0;
        int sumB=0;
        while(curA)
        {
            lastA=curA;
            curA=curA->next;
            ++sumA;
        }
        while(curB)
        {
            lastB=curB;
            curB=curB->next;
            ++sumB;
        }
        if(lastB!=lastA)
            return NULL;
        int dis=sumA-sumB;
        curA=headA;
        curB=headB;
        int count=0;
        int sum=0;
        if(dis<0)
        {
            dis=-dis;
            while(curB)
            {
                ++count;
                curB=curB->next;
                if(count==dis)
                    break;
            }

        }
        else if(dis>0)
        {
            while(curA)
            {
                ++count;
                curA=curA->next;
                if(count==dis)
                    break;
            }

        }
         while(curA&&curB)
            {
                if(curA==curB)
                {
                    if(sum==0)
                        res=curA;
                    ++sum;
                }
                else
                {
                    sum=0;
                }
                curA=curA->next;
                curB=curB->next;
            }
            return res;

    }
};

int main()
{

    return 0;
}
