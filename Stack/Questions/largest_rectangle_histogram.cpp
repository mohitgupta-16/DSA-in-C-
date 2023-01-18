// Given an array.Each element reprsents the height to the histogram's bar and the width of each bar is 1, find the area of largest rectangle in the histogram
#include "bits/stdc++.h"
using namespace std;

int get_max_area(vector<int> a)
{
    // we here maintain bars in increasing order
    stack<int> st;
    int n = a.size();
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // we will find left smaller and right smaller of the bar and then calculate the area
        while (!st.empty() && a[st.top()] > a[i]) // put larger value's index at top
        {
            int popped = st.top();
            st.pop();
            if (st.empty())
            { // if stack is empty the we have to take full width that is i
                area = max(area, a[popped] * i);
            }
            else
            {
                area = max(area, a[popped] * (i - (st.top() + 1))); // width is right smaller - (left smaller(top of st)+1)
            }
        }
        st.push(i);
    }

    while (!st.empty())
    { // now there is no right smaller left so we take right smaller to be length of array that is n
        int popped = st.top();
        st.pop();
        if (st.empty())
        {
            area = max(area, a[popped] * n);
        }
        else
        {
            area = max(area, a[popped] * (n - (st.top() + 1)));
        }
    }

    return area;
}

int main()
{
    vector<int> h1 = {2, 1, 5, 6, 2, 3};
    vector<int> h2 = {2, 1, 5, 6, 2, 3, 2, 2, 2, 2};
    vector<int> h3 = {5, 5, 2, 2, 2, 2};
    vector<int> h4 = {4, 4, 4, 4, 4};

    vector<vector<int>> h = {h1, h2, h3, h4};

    for (auto i : h)
    {
        cout << "Histogram : ";
        for (auto num : i)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Maximum area of rectangle: " << get_max_area(i) << endl;
    }

    return 0;
}