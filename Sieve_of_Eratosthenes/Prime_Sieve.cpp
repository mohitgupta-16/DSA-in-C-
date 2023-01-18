#include <iostream>
using namespace std;

void primeSieve(int n)
{
    int prime[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0) //  0 are non-marked
        {
            for (int j = i * i; j <= n; j += i) //  j += i signifies 4+2 = 8
            {
                prime[j] = 1; // 1 are marked
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " "; //  print index not prime[i]
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    primeSieve(n);

    return 0;
}