#include "bits/stdc++.h"
using namespace std;

void reverseSentence(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word); // so the first world will place at the bottom of the stack and so on
    }

    while (!st.empty())
    {
        cout << st.top() << " "; // print the top word that is actually last word of the sentence and so on
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Hey, how are you doing?";
    reverseSentence(s);

    return 0;
}
