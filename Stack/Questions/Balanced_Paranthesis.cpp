#include "bits/stdc++.h"
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool answer = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        // if opening and closing paranthesis matches out then pop the top element(opening bracket)
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                answer = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                answer = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                answer = false;
                break;
            }
        }
    }
    // if stack is empty then string is valid otherwise not valid
    if (!st.empty())
    {
        return false;
    }
    else
    {

        return answer;
    }
}

int main()
{
    string s = "{([])}";

    if (isValid(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Not Valid String" << endl;
    }

    return 0;
}