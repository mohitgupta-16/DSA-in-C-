#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int> a)
{
    int n = a.size();
    stack<int> st;
    int water = 0;

    for (int i = 0; i < n; i++)
    {
        // to maintain non increasing stack
        while (!st.empty() and a[st.top()] < a[i]) // We have to put smaller value's index at top
        {
            int popped = st.top();
            st.pop();
            if (st.empty())
            {
                break; // if there is no wall water will not stay
            }
            else
            {
                int distance = i - (st.top() + 1);               // to find distance b/w bars
                int height = min(a[st.top()], a[i]) - a[popped]; // height of water
                water += (distance * height);
            }
        }
        st.push(i);
    }

    return water;
}

int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Water Trapped: " << maxWater(a) << endl;

    return 0;
}