#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "((a+b))";
    // string s = "";
    // string s = "(a+(b)/c)";
    // string s = "(a+b*(c-d))";

    stack<int> st;

    bool ans = false;

    for (int i = 0; i < s.size(); i++)
    { // we ignore variables else push
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        { // if ) we check top and if there is operator or ( we pop them and if there is ) then true
            if (st.top() == '(')
            {
                ans = true;
            }

            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                st.pop();
            }
            st.pop(); // to pop '('
        }
    }

    if (ans == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}