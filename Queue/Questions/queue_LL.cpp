#include "bits/stdc++.h"
using namespace std;

// Linked List Implementation
class node
{
public:
    int data;
    node *next;

    node(int val) // to assign values to the nodes
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        node *n = new node(x);
        if (back == NULL) // new element will be added to the last
        {
            front = n; // for starting node
            back = n;
            return;
        }
        back->next = n;
        back = n;
        n->next = NULL;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            node *toDelete = front;
            front = front->next;
            if (front == NULL)
            {
                back = NULL;
            }

            delete toDelete;
        }
    }

    void peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << front->data << endl;
        }
    }

    void empty()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue is not empty" << endl;
    }

    void display()
    {
        node *temp;
        temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    // q.dequeue();
    // q.empty()
    // q.peek();
    q.display();

    return 0;
}
