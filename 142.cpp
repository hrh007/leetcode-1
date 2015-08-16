#include <iostream>
#include <set>

using namespace std;


//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution3
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* ptr1,* ptr2;
        if(head == NULL)
            return NULL;
        ptr1 = head ;
        ptr2 = head;

        while(ptr2->next != NULL && ptr2->next->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr2 = head;
                while(ptr1 != ptr2)
                {
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                }
                return ptr1;
            }

        }
        return NULL;

    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head==NULL)
            return NULL;

        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                fast=head;
                while(fast&&slow)
                {
                    if(fast==slow)
                      return fast;
                    fast=fast->next;
                    slow=slow->next;
                }
                 return fast;
            }
        }
        return NULL;
    }
};

class Solution2
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *cur=head;
        set<ListNode *> s1;
        while(cur)
        {
            if(s1.find(cur)!=s1.end())
                return cur;
            else
            {
                s1.insert(cur);
                cur=cur->next;
            }
        }
        return NULL;
    }
};

int main()
{

    return 0;
}
