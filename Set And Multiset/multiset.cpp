#include "bits/stdc++.h"
using namespace std;

int main()
{
    multiset<int> s;
    // multiset<int, greater<int>> s; // for descending order
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size() << endl;
    s.erase(s.upper_bound(2)); // it erase all the 2 // s.find()
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    return 0;
}