#include "bits/stdc++.h"
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // default constructor
    Complex() {}
    // Otherwise
    // Complex(int r = 0, int i = 0)

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res; // to return the result
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }

    void display()
    {
        cout << real << "+" << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(12, 7), c2(6, 7);
    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}