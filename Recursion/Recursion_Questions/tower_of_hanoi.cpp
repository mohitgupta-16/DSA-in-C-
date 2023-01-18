//  1. Move n-1 disc from Source to Helper using Destination
//  2. Move disc from Source to Destination
//  3. Move n-1 disc from Helper to Destination using Source

#include <iostream>
using namespace std;

void towerofHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerofHanoi(n - 1, src, helper, dest); //  initialise on behalf for which they are called
    cout << "Move from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, helper, dest, src);
}

int main()
{
    towerofHanoi(3, 'A', 'C', 'B');

    return 0;
}