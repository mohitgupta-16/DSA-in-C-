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

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeigth = Height(root->left);
    int rHeigth = Height(root->right);

    return max(lHeigth, rHeigth) + 1;
}

// O(n2)

// for root

bool checkBalance(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (checkBalance(root->left) == false)
    {
        return false;
    }
    if (checkBalance(root->right) == false)
    {
        return false;
    }

    int lh = Height(root->left);
    int rh = Height(root->right);

    if (abs(lh - rh) <= 1) // modulus| |
    {
        return true;
    }
    else
    {
        return false;
    }
}

// O(n)

// for root2

bool checkBalance(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }

    int lh = 0;
    int rh = 0;

    if (checkBalance(root->left, &lh) == false)
    {
        return false;
    }
    if (checkBalance(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1) // modulus||
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for root3

bool checkBalance(Node *root, int &height)
{
    if (root == NULL)
    {
        height = 0;
        return true;
    }

    int lh = 0;
    int rh = 0;

    if (checkBalance(root->left, lh) == false)
    {
        return false;
    }
    if (checkBalance(root->right, rh) == false)
    {
        return false;
    }

    height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1) // modulus||
    {
        return true;
    }
    else
    {
        return false;
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

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    Node *root3 = new Node(1);
    root3->right = new Node(3);
    root3->right->right = new Node(2);
    root3->right->right->right = new Node(2);

    if (checkBalance(root))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    int height = 0;

    if (checkBalance(root2, &height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    if (checkBalance(root3, height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    return 0;
}