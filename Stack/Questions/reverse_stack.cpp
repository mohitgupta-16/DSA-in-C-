#include "bits/stdc++.h"
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    // In this we will store the top of reverse stack and push element in the bottom(below element of top)
    int topEle = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topEle);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st); // this will empty the stack
    insertAtBottom(st, ele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}