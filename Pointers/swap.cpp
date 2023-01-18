// #include <iostream>
// using namespace std;

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main()
// {
//     int a = 2;
//     int b = 4;

//     int *aptr = &a;
//     int *bptr = &b;

//     // swap(aptr, bptr);
//     swap(&a, &b);
//     cout << a << " " << b << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

void increment(int *a)
{
    // *a++;    increment the pointer not value
    (*a)++;
}

int main()
{
    int a = 2;

    increment(&a);
    cout << a << endl;

    return 0;
}