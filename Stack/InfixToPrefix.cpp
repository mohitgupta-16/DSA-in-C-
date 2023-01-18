#include "bits/stdc++.h"
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '-' || c == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string InfixToPrefix(string s)
{
    reverse(s.begin(), s.end()); // reverse the string to change it into infix to postfix
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i]; // if operand add to result for printing answer
        }
        else if (s[i] == ')') // to change opening bracket into closing bracket
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
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

    reverse(result.begin(), result.end()); // to reverse the result to change into prefix ecpression

    return result;
}

int main()
{
    cout << InfixToPrefix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}