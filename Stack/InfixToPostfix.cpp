#include "bits/stdc++.h"
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i]; // if operand add to result for printing answer
        }
        else if (s[i] == '(')
        {
            st.push(s[i]); // if opening bracket push to the stack
        }
        else if (s[i] == ')') // if closing bracket then add to the result and pop the elements until '('
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top(); // to pop opening bracket at last
                st.pop();
            }
            if (!st.empty())
            {
                st.pop(); // to pop the last element
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            { // if precedence of top operator is greater,add it to the result and pop it
                result += st.top();
                st.pop();
            }
            st.push(s[i]); // to push the operator less precedence
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop(); // pop until the stack is empty
    }

    return result;
}

int main()
{
    cout << InfixToPostfix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}