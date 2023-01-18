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

// Lowest Common Ancestor
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA)
    {
        return leftLCA;
    }
    else
    {
        return rightLCA;
    }
}

int findDistance(Node *root, int k, int distance) // root is lca
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return distance;
    }

    // we add 1 to distance every time we call function for right or left
    int lDistance = findDistance(root->left, k, distance + 1);
    if (lDistance != -1)
    {
        return lDistance;
    }

    int rDistance = findDistance(root->right, k, distance + 1);
    if (rDistance != -1)
    {
        return rDistance;
    }

    return distance;
}

// it is basically number of edges between two nodes
int distanceBtw2Nodes(Node *root, int n1, int n2)
{

    // first we found lca then we found distance node from lca

    Node *lca = LCA(root, n1, n2);

    // to find number of edges for n1
    int d1 = findDistance(lca, n1, 0);
    // to find number of edges for n2
    int d2 = findDistance(lca, n2, 0);

    // add both distances and return

    return d1 + d2;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(4);

    int n1 = 1, n2 = 2;
    cout << "Shortest Distance B/w " << n1 << " and " << n2 << " is " << distanceBtw2Nodes(root, n1, n2) << endl;

    return 0;
}