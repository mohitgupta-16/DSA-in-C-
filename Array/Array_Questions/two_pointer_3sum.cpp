#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    bool found = false;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            int current = a[i] + a[lo] + a[hi];
            if (current == target)
            {
                found = true;
            }
            // if we write else if here then if if statement is true then it will lead to infinite loop as lo < hi is always true for while loop
            if (current < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }

    if (found == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}