#include "bits/stdc++.h"
using namespace std;

class A
{
public:
    void func()
    {
        cout << "I am a function with no arguement" << endl;
    }

    void func(int x)
    {
        cout << "I am a function with int arguement" << endl;
    }

    void func(double x)
    {
        cout << "I am a function with double arguement" << endl;
    }
};

int main()
{
    A obj;
    obj.func();
    obj.func(4);
    obj.func(6.2);

    return 0;
}