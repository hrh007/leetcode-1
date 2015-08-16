#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {

         if(head==NULL)
            return NULL;
         else
         {
             map<RandomListNode *,RandomListNode *> m1;
             RandomListNode *cur=head;
             RandomListNode *new_head=new RandomListNode(cur->label);
             RandomListNode *new_cur=new_head;
             new_cur->random=cur->random;
             m1[cur]=new_cur;
             while(cur->next)
             {
                 RandomListNode *temp=new RandomListNode(cur->next->label);
                 new_cur->next=temp;
                 new_cur=new_cur->next;
                 cur=cur->next;
                 new_cur->random=cur->random;
                 m1[cur]=new_cur;
             }
             cur=head;
             new_cur=new_head;
             while(new_cur)
             {
                 if(new_cur->random!=NULL)
                 {
                     new_cur->random=m1[new_cur->random];
                 }
                 new_cur=new_cur->next;
             }
             return new_head;
         }
    }
};

int main()
{


    return 0;
}
