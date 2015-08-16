#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty()&&q2.empty())
            q1.push(x);
        else if(!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int temp;
        if(!q1.empty())
        {
            temp=q1.front();
            q1.pop();
            while(!q1.empty())
            {
                q2.push(temp);
                temp=q1.front();
                q1.pop();
            }
        }
        else
        {
            temp=q2.front();
            q2.pop();
            while(!q2.empty())
            {
                q1.push(temp);
                temp=q2.front();
                q2.pop();
            }
        }
    }

    // Get the top element.
    int top() {
          int temp;
        if(!q1.empty())
        {
            while(!q1.empty())
            {
                temp=q1.front();
                q2.push(temp);
                q1.pop();
            }
        }
        else
        {
            while(!q2.empty())
            {
                temp=q2.front();
                q1.push(temp);
                q2.pop();
            }
        }
        return temp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty()&&q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};

int main()
{

    return 0;
}
