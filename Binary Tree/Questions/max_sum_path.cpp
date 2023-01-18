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

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    // max path through left child
    int leftPathSum = maxPathSumUtil(root->left, ans);
    // max path through right child
    int rightPathSum = maxPathSumUtil(root->right, ans);

    // maximum path sum "starting" from the given node in a binary tree
    int singlePathSum = max(max(root->data + leftPathSum, root->data + rightPathSum), root->data);

    int nodeMax = max(singlePathSum, root->data + leftPathSum + rightPathSum);

    ans = max(ans, nodeMax);

    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;

    maxPathSumUtil(root, ans);

    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << maxPathSum(root) << endl;

    return 0;
}