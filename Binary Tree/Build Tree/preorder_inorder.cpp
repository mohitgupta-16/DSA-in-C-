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

// to find positon of curr[idx] in inorder
int search(int inorder[], int start, int end, int curr)
{
    // loop from start upto end
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

// start and end are starting and ending index of inorder

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    }

    // store value at idx in preorder
    int curr = preorder[idx];
    idx++; // increment idx

    // make new node of data curr
    Node *node = new Node(curr);

    // when only one node is left
    if (start == end)
    {
        return node;
    }

    // store position of curr in inorder
    int pos = search(inorder, start, end, curr);

    // in preorder first root then left then right
    // to build left subtree
    node->left = buildTree(preorder, inorder, start, pos - 1);
    // to build right subtree
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(preorder, inorder, 0, 4);
    printInorder(root);

    return 0;
}