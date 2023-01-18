#include "bits/stdc++.h"
using namespace std;

#define n 3
// Array Implementation
class Queue
{
    int *arr;
    int front;
    int back; // rear

public:
    Queue() // constructor of Queue
    {
        arr = new int[n]; // allocating memory to the array upto n
        front = 0;        // intialising front and rear with -1
        back = 0;
    }

    void enqueue(int x)
    {
        if (back == n)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            // adding data first then incrementing pointer to add first element to front
            back++;
            arr[back] = x;
        }

        // if (front == -1)
        // {
        //     front++;
        // }
    }

    void dequeue()
    { // front is greater than back means we have deleted last element also and front has crossed back
        if (front == back)
        {
            cout << "No elements in Queue" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < back - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            back--;
        }
        return;
    }

    // to get the first element in the queue
    void peek()
    {
        if (front == back)
        {
            cout << "No elements in Queue" << endl;
            return;
        }
        else
        {
            cout << arr[front] << endl;
        }
    }
    void display()
    {
        if (front == back)
        {
            cout << "No elements in Queue" << endl;
            return;
        }
        else
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    bool empty()
    {
        if (front == back)
        {
            cout << "No elements in Queue" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    // q.enqueue(3);
    // q.dequeue();
    q.dequeue();
    // q.dequeue();
    // q.enqueue(4);
    // q.empty();
    q.peek();

    return 0;
}