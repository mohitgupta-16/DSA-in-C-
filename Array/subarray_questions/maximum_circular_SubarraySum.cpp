#include "bits//stdc++.h"
using namespace std;

int kadane(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

     //  if all elements of array are negative
    int maxNo = *max_element(arr, arr + n);
    if (maxNo < 0)
    {
        cout << maxNo << endl;
        return 0;
    }

    int wrapsum;
    int nonwrapsum;

    nonwrapsum = kadane(arr, n);

    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = totalsum + kadane(arr, n);

    cout << max(wrapsum, nonwrapsum) << endl;

    return 0;
}