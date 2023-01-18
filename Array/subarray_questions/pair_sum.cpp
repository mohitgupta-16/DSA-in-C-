#include "bits//stdc++.h"
using namespace std;

//  time complexity O(n^2) (sorted or unsorted)
/*
bool pairsum(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 31;

    cout << pairsum(arr, n, k) << endl;

    return 0;
}
*/

//  time complexity O(n) (sorted array)
bool pairsum(int arr[], int n, int k)
{
    // sort(arr, arr + n);  use for unsorted array

    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 31;

    cout << pairsum(arr, n, k) << endl;

    return 0;
}