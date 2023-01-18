#include <iostream>
using namespace std;

int sum(int a, int b)
{
    cout << "Using function with two arguments" << endl;
    return a + b;
}

int sum(int a, int b, int c)
{
    cout << "Using function with three arguments" << endl;
    return a + b + c;
}

// calculate the volume of cylinder
int volume(double r, int h)
{
    return (3.14 * r * r * h);
}

// calculate the volume of cube
int volume(int a)
{
    return (a * a * a);
}

// volume of rectangular box
int volume(int l, int b, int h)
{
    return (l * b * h);
}

int main()
{
    cout << "The sum of 3 and 6 is " << sum(3, 6) << endl;
    cout << "The sum of 3, 7 and 6 is " << sum(3, 7, 6) << endl;
    cout << "The volume of cuboid length 3, breadth 7 and height 6 is " << volume(3, 7, 6) << endl;
    cout << "The volume of cylinder of radius 3 and height 6 is " << volume(3, 6) << endl;
    cout << "The volume of cube side 3 is " << volume(3) << endl;

    return 0;
}