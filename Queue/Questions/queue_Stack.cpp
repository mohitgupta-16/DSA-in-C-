#include "bits/stdc++.h"
using namespace std;

// class Queue
// {
//     stack<int> s1;
//     stack<int> s2;

// public:
//     void enqueue(int x)//O(1)
//     {    // just push the element in stack
//         s1.push(x);
//     }

//     int dequeue()//O(n)
// {    // pop all the elements from stack1 and push into stack2 and now pop the top of stack2
//         if (s1.empty() && s2.empty())
//         {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         if (s2.empty())
//         {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int topval = s2.top();
//         return topval;
//     }

//     bool empty()
//     {
//         if (s1.empty() and s2.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     Queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);

//     cout << q.dequeue() << endl;

//     return 0;
// }

// Using recursion

class Queue
{
    stack<int> s1;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            exit(0); // to return nothing
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        // Recursively pop everything from the stack1, store the popped item in a variable res, push the res back to stack1 and return res
        int item = dequeue();
        // push popped item back to the stack
        s1.push(x);
        return item;
    }

    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}