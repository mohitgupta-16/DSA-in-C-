#include "bits/stdc++.h"
using namespace std;

//  Polish Notation
//  <operator><operand><operand>
int prefixEvaluation(string s)
{
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--) // moving from right to left
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // taking two inputs of operand
        }
        else // if operators came then do the operation by poping top two operands
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2); // push the result
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << prefixEvaluation("-+7*45+20") << endl;

    return 0;
}
// "- + 7 * 4 5 + 2 0"