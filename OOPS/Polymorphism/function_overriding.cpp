#include "bits/stdc++.h"
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "This is the base class's print function" << endl;
    }

    void display()
    {
        cout << "This is the base class's display function" << endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "This is the derived class's print function" << endl;
    }

    void display()
    {
        cout << "This is the derived class's display function" << endl;
    }
};

int main()
{
    base *baseptr;
    derived obj;
    baseptr = &obj;

    baseptr->print();
    baseptr->display();

    return 0;
}