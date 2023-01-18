//  Given an array nums of distinct(non-repeating) integers, return all the possible permutations. You can return the answer in any order.

#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> ans;

void permutation(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permutation(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    cout << endl;
    // permutation(a, 0);   //recurive method

    sort(a.begin(), a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}