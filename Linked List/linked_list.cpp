#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// pointer to pointer
// void insertAtHead(node **head, int val)
// reference to pointer
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    // n->next = *head;
    // *head = n;
    n->next = head;
    head = n;
}

void insertAfterNode(node *prevnode, int val)
{
    node *n = new node(val);

    n->data = val;

    n->next = prevnode->next;
    prevnode->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deleteAtTail(node *&head, int val)
{
    node *p = head;
    node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    // p->next = q->next;
    p->next = NULL;
    delete q;
}

void deletion(node *&head, int val)
{
    if (head = NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // insertAtHead(head, 4);
    // insertAfterNode(head->next->next, 5);
    // display(head);
    // cout << search(head, 3) << endl;
    // deletion(head, 4);
    // deleteAtHead(head);
    // deleteAtTail(head, 4);
    display(head);

    return 0;
}