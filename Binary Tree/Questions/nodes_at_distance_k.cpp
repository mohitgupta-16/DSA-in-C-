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

// Case:1 For Subtrees

void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// Case:2 For ancestor

int printNodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        return 0;
    }

    // when we found target on right we will search in left
    int leftDistance = printNodesAtK(root->left, target, k);
    if (leftDistance != -1)
    {
        if (leftDistance + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // as we are moving two steps back therefore -2
            printSubtreeNodes(root->right, k - leftDistance - 2);
        }
        return leftDistance + 1;
    }

    // when we found target on left we will search in right
    int rightDistance = printNodesAtK(root->right, target, k);
    if (rightDistance != -1)
    {
        if (rightDistance + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->left, k - rightDistance - 2);
        }
        return rightDistance + 1;
    }

    return -1;
}

int main()
{
    //     Node *root = new Node(1);
    //     root->left = new Node(2);
    //     root->right = new Node(3);
    //     root->right->left = new Node(6);
    //     root->right->left->left = new Node(7);
    //     root->right->left->right = new Node(8);
    //     root->left->left = new Node(4);
    //     root->left->right = new Node(5);
    //     root->left->right->left = new Node(8);
    //     root->left->right->left->left = new Node(9);
    //     root->left->right->left->left->right = new Node(10);

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    // node * target = root->left->right;

    printNodesAtK(root, root->left->right, 2);

    return 0;
}