#include <bits/stdc++.h>
using namespace std;

int longestSubString(string s)
{
    int n = s.size();
    vector<int> lastIndex(256, -1);
    int ans = 0, start = -1;

    for (int i = 0; i < n; i++)
    {
        // if it character is repeated lastindex[character] will be greater than start
        if (lastIndex[s[i]] > start)
        {
            start = lastIndex[s[i]];
        }
        // to update lastindex of character
        lastIndex[s[i]] = i;
        ans = max(ans, i - start);
    }

    return ans;
}

int main()
{
    // string s = "pkwwew";
    string s = "geeksforgeeks";
    cout << "String: " << s << endl;
    cout << "Maximum length: " << longestSubString(s) << endl;

    return 0;
}