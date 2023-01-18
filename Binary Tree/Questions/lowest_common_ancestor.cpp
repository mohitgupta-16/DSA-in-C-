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

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    // here we are storing paths
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    // if any of left or right true we return that is we got the path
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    // if not found key then pop the data and return false
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pathChange;
    // loop works upto smallest path size
    for (pathChange = 0; pathChange < path1.size() && pathChange < path2.size(); pathChange++)
    {
        // it means the previous node was the node where the path changes
        if (path1[pathChange] != path2[pathChange])
        {
            break;
        }
    }

    return path1[pathChange - 1];
}

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    // when we found both n1 and n2 at one node we return that node
    if (leftLCA && rightLCA) // not NULL
    {
        return root;
    }

    // when we found n1 or n2 in leftLCA we return leftLCA
    if (leftLCA)
    {
        return leftLCA;
    }
    // when we found n1 or n2 in rightLCA we return rightLCA
    else
    {
        return rightLCA;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 7;
    int n2 = 6;

    Node *lca = LCA2(root, n1, n2);

    if (lca == NULL)
    {
        cout << "LCA doesn't exist" << endl;
    }
    else
    {
        cout << "LCA: " << lca->data << endl;
    }

    return 0;
}