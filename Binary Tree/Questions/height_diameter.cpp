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

int calcHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeigth = calcHeight(root->left);
    int rHeigth = calcHeight(root->right);

    return max(lHeigth, rHeigth) + 1;
}
// O(n2)

int calcDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lHeigth = calcHeight(root->left);
    int rHeigth = calcHeight(root->right);
    // when root node to be included
    int currDiameter = lHeigth + rHeigth + 1;

    // when root node is not included
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}
// O(n)

int calcDiameter2(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lHeigth = 0;
    int rHeigth = 0;

    // it is giving us both diameter and height
    int lDiameter = calcDiameter2(root->left, &lHeigth);
    int rDiameter = calcDiameter2(root->right, &rHeigth);
    int currDiameter = lHeigth + rHeigth + 1;
    // here we are changing the height by passing it as reference
    *height = max(lHeigth, rHeigth) + 1;

    return max(currDiameter, max(rDiameter, lDiameter));
}

pair<int, int> Height_Diameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftTree = Height_Diameter(root->left);
    pair<int, int> rightTree = Height_Diameter(root->right);
    int lHeight = leftTree.first;
    int lDiameter = leftTree.second;
    int rHeight = rightTree.first;
    int rDiameter = rightTree.second;

    int Height = max(lHeight, rHeight) + 1;
    int Diameter = max((lHeight + rHeight + 1), max(lDiameter, rDiameter));
    pair<int, int> p;
    p.first = Height;
    p.second = Diameter;

    return p;
}

// O(n)

int height(Node *root, int *ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left, ans);
    int rh = height(root->right, ans);

    *ans = max(*ans, lh + rh + 1);

    return max(lh, rh) + 1;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 0;
    height(root, &ans);
    return ans;
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

    cout << "Height: " << calcHeight(root) << endl;
    cout << "Diameter: " << calcDiameter(root) << endl;
    cout << endl;

    int height = 0;
    cout << "Diameter2: " << calcDiameter2(root, &height) << endl;
    cout << endl;

    pair<int, int> ans = Height_Diameter(root);
    cout << "Height: " << ans.first << endl;
    cout << "Diameter: " << ans.second << endl;
    cout << endl;

    // cout << "Height: " << height(root, ) << endl;
    cout << "Diameter: " << diameter(root) << endl;
    return 0;
}
