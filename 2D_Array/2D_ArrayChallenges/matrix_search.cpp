#include <iostream>
using namespace std;

//  for O(n) ( sorted array )
int main()
{
    int n, m;
    cin >> n >> m;

    int target;
    cin >> target;

    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    bool found = false;
    int r = 0, c = m - 1;
    // int r = n -1 , c = 0;
    while (r < n and c >= 0)
    {
        if (mat[r][c] == target)
        {
            found = true;
            break;
        }
        else if (mat[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (found)
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}