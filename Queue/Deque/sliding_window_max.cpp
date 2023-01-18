// to find maximum element upto k elements in array
#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &i : a) // &i to work with actual values and i for copies
        cin >> i;

    // O(nlog(n))
    // multiset<int, greater<int>> s;
    // vector<int> ans;
    // // for first k elements
    // for (int i = 0; i < k; i++)
    // {
    //     s.insert(a[i]);
    // }
    // ans.push_back(*s.begin()); // value

    // // for next elements
    // for (int i = k; i < n; i++)
    // {
    //     s.erase(s.lower_bound(a[i - k])); // to delete one element only
    //     s.insert(a[i]);
    //     ans.push_back(*s.begin());
    // }
    // for (auto i : ans) // here we are not working with actual values just need copies
    //     cout << i << " ";

    // O(n)
    deque<int> dq;
    vector<int> ans;

    // for first k elements
    for (int i = 0; i < k; i++)
    {
        // we have to keep only bigger element's index in deque and pop all smaller ones
        while (!dq.empty() and a[dq.back()] < a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]); // pushing the index not the values

    // for next elements
    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k)
        { // to pop the largest element's index from last k elements and empty deque
            dq.pop_front();
        }
        while (!dq.empty() and a[dq.back()] < a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}