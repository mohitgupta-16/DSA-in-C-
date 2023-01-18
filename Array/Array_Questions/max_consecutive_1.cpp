#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int ans = 0;
    int zeroCount = 0;

    // is left limit and j is right limit
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (a[i] == 0)
            {
                zeroCount--;
            }
            i++;
        }
        ans = max(ans, j - i + 1); // we are considering the last element therefore +1
    }

    cout << "Max Size: " << ans << endl;

    return 0;
}