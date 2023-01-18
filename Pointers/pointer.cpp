#include <iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int *aptr = &a;

    // cout << *aptr << endl;
    // *aptr = 20;
    // cout << a << endl;
    // cout << aptr << endl;
    // aptr++;
    // cout << aptr << endl;

    // char ch = 'a';
    // char *cptr = &ch;

    // cout << cptr << endl;
    // cptr++;
    // cout << cptr << endl;

    //  POINTERS AND ARRAYS

    int arr[] = {10, 20, 30};
    cout << *arr << endl;

    int *ptr = arr;
    for (int i = 0; i < 3; i++)
    {
        // cout << *ptr <<" ";
        // ptr++;
        // cout << *arr << " ";
        // arr++;   //illegal
        cout << *(arr+i) << " ";
    }
    cout << endl;

    //  POINTER TO POINTER

    int a = 10;
    int *p;
    p = &a;

    cout << *p << endl;

    int **q = &p;
    cout << *q << endl;
    cout << **q << endl;

    return 0;
}