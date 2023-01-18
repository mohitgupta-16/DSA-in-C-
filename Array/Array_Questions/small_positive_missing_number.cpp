#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            check[a[i]] = true;
        }
    }

    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long n;
//     cin >> n;
//     long long a;
//     cin >> a;
//     int arr[100];
//     int i = 0;
//     while (n)
//     {
//         arr[i] = n % 10;
//         n = n / 10;
//         i++;
//     }
//     long long size = sizeof(arr) / sizeof(arr[0]);
//     int count = 0;
//     for (long long i = 0; i < size; i++)
//     {
//         if (arr[i] == a)
//         {
//             count++;
//         }
//     }
//     cout << count;

//     return 0;
// }