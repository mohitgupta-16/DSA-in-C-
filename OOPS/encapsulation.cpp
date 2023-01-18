#include "bits/stdc++.h"
using namespace std;

class A
{
public:
    int a;
    void funcA()
    {
        cout << "Func A" << endl;
    }

private:
    int b;
    void funcB()
    {
        cout << "Func B" << endl;
    }

private:
    int c;
    void funcC()
    {
        cout << "Func C" << endl;
    }
};

int main()
{
    A obj;
    obj.funcA();
    // obj.funcB();

    return 0;
}