#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

/** FENWICK -> WI -> UI */

void updateTree(int ind, int oldval, int newval, vector<int> &tree)
{
    ind++;

    while (ind < tree.size())
    {
        tree[ind] = tree[ind] + newval - oldval;
        ind = ind + (ind & (-ind));
    }
}

int getPrefix(int ind, vector<int> &tree)
{
    ind++;
    int sum = 0;
    while (ind > 0)
    {
        sum += tree[ind];
        ind = ind - (ind & (-ind));
    }
    return sum;
}

int getSum(int x, int y, vector<int> &tree)
{
    return getPrefix(y, tree) - getPrefix(x - 1, tree);
}

int main()
{
    vector<int> v = {1, 4, 6, 2, 1, 2, 34};
    int n = v.size();

    vector<int> tree(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        updateTree(i, 0, v[i], tree);
    }

    cout << getSum(3, 5, tree) << endl; // 2+1+2 = 5
    updateTree(4, 1, 10, tree);
    cout << getSum(3, 5, tree) << endl; // 2+10+2 = 14
}