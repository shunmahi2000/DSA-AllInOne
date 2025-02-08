#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

/** 236. Lowest Common Ancestor of a Binary Tree */
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    // NOTE: cant use this.val becuase `this` itself is a pointer, Uncomment down, to get error while compilation
};

/**
class Hello
{
public:
    int val;

    Hello(int val)
    {
        this.val = val;
    }
};
*/

TreeNode *findLca(TreeNode *root, TreeNode *a, TreeNode *b)
{
    if (root == NULL)
        return NULL;
    if (root == a)
        return a;
    if (root == b)
        return b;
    TreeNode *l = findLca(root->left, a, b);
    TreeNode *r = findLca(root->right, a, b);
    if (l && r)
    {
        return root;
    }
    if (l == NULL)
        return r;
    return l;
}
void solve()
{
}

int main()
{
    ll t;
    cin >> t;
    for (ll it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}