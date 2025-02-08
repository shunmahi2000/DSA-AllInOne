#include <bits/stdc++.h>
using namespace std;

int dsu_find(int x, vector<int> &par)
{
    if (par[x] == x)
        return x;
    return par[x] = dsu_find(par[x], par);
}
void dsu_union(int x, int y, vector<int> &par, vector<int> &rank)
{
    int px = dsu_find(x, par), py = dsu_find(y, par);
    if (px == py)
        return;

    if (rank[px] < rank[py])
    {
        par[px] = py;
    }
    else if (rank[px] > rank[py])
    {
        par[py] = px;
    }
    else
    {
        par[py] = px;
        rank[px]++;
    }
}
int mstCost(int n, vector<vector<int>> &e)
{
    sort(e.begin(), e.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    vector<int> par(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        par[i] = i;
    int mstCost = 0;

    for (int i = 0; i < e.size(); i++)
    {
        int px = dsu_find(e[i][0], par), py = dsu_find(e[i][1], par);
        if (px != py)
        {
            mstCost += e[i][2];
            dsu_union(e[i][0], e[i][1], par, rank);
        }
    }
    return mstCost;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back({x, y, w});
    }

    cout << mstCost(n, e) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
Input
5
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 3
0 1 5
1 2 10
2 0 8
6 9
0 1 4
0 2 4
1 2 2
1 3 5
2 3 6
2 4 8
3 4 9
3 5 10
4 5 11
7 8
0 1 1
1 2 2
2 3 3
3 4 4
4 5 5
5 6 6
6 0 7
1 6 8
Output
19
16
13
29
21
 */