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

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);

        // 1. we store right of root in temp
        Node *temp = root->right;

        // 2. we add left of root to the right of root
        root->right = root->left;
        // 3. add null to the left of root
        root->left = NULL;

        // 4. store the tail of right of root that was previously left of root
        Node *tail = root->right;
        while (tail->right != NULL)
        {
            tail = tail->right;
        }
        // here tail node is the tail of right of root that was previously left of root

        // 5. add temp that was right of root at starting to right of tail
        tail->right = temp; // now the tree is flattened
    }
    flatten(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
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

    flatten(root);
    inorder(root);
    cout << endl;

    return 0;
}