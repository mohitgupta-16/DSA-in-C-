#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLeveOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root); // root element is at 0th level
    // q.push(NULL); // to maintain to push NULL after every level

    while (!q.empty())
    {
        // store in node and pop from queue
        Node *node = q.front();
        q.pop();

        // when node is not NULL then push the left and right of node in queue
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        // else if (!q.empty()) // when q is not empty(means elements of next level present and node is NULL)
        // {
        //     q.push(NULL); // push NULL after every level
        // }
        // else if q is empty then we will exit by while loop condition
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printLeveOrder(root);

    return 0;
}