#include "bits/stdc++.h"
using namespace std;

// push costly
// class Stack
// {
//     int N;
//     queue<int> q1;
//     queue<int> q2;

// public:
//     Stack()
//     {
//         N = 0;
//     }

//     void push(int val)
//     {
//         N++;
//         q2.push(val);
//         while (!q1.empty()) // One by one dequeue everything from q1 and enqueue to q2
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         queue<int> temp_q = q1;
//         q1 = q2;
//         q2 = temp_q;
//     }

//     void pop()
//     {
//         if (q1.empty())
//         {
//             cout << "Stack is Empty" << endl;
//         }

//         q1.pop();
//         N--;
//     }

//     int top()
//     {
//         if (q1.empty())
//         {
//             cout << "Stack is Empty" << endl;
//             exit(0);
//         }
//         return q1.front();
//     }

//     int size()
//     {
//         return N;
//     }

//     bool empty()
//     {
//         if (q1.empty())
//         {
//             cout << "Stack is Empty" << endl;
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     cout << st.top() << endl;
//     st.pop();
//     cout << st.top() << endl;
//     st.pop();
//     cout << st.top() << endl;
//     st.pop();
//     cout << st.top() << endl;
//     st.pop();

//     cout << st.size() << endl;

//     return 0;
// }

// pop costly
class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q1.push(val);
        N++;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty" << endl;
        }

        while (q1.size() != 1) // One by one dequeue all except the last element from q1 and enqueue to q2
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // element to be poped
        N--;

        queue<int> temp_q = q1;
        q1 = q2;
        q2 = temp_q;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty" << endl;
            exit(0);
        }
        while (q1.size() != 1) // One by one dequeue all except the last element from q1 and enqueue to q2
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front(); // store the top element
        q2.push(top);

        queue<int> temp_q = q1;
        q1 = q2;
        q2 = temp_q;

        return top;
    }

    int size()
    {
        return N;
    }

    bool empty()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    cout << st.size() << endl;

    return 0;
}