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

void SumReplacement(Node *root)
{
    if (root == NULL)
    {
        // if root is null simply return
        return;
    }

    SumReplacement(root->left);
    SumReplacement(root->right);

    // first we are adding left node data then right node data

    // if not null then only we can add data to data of root
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
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

    inorder(root);
    cout << endl;

    SumReplacement(root);
    inorder(root);
    cout << endl;

    return 0;
}