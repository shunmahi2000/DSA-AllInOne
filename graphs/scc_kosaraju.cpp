#include <bits/stdc++.h>
using namespace std;
void dfs(int cur, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[cur] = 1;
    // You cant put st.push(cur) here
    for (auto it : adj[cur])
    {
        if (vis[it] == 0)
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(cur);
}
void dfs2(int cur, vector<int> &vis, vector<int> &scc, vector<vector<int>> &adj)
{
    vis[cur] = 1;
    scc.push_back(cur);
    for (auto it : adj[cur])
    {
        if (vis[it] == 0)
        {
            dfs2(it, vis, scc, adj);
        }
    }
}
vector<vector<int>> find_scc(int n, vector<vector<int>> &e)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < e.size(); i++)
    {
        adj[e[i][0]].push_back(e[i][1]);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    dfs(0, st, vis, adj);

    vector<vector<int>> radj(n);
    for (int i = 0; i < e.size(); i++)
    {
        radj[e[i][1]].push_back(e[i][0]);
    }
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    vector<vector<int>> sccs;
    while (st.size())
    {
        int cur = st.top();
        st.pop();

        if (vis[cur] == 0)
        {
            vector<int> scc;
            dfs2(cur, vis, scc, radj);
            sccs.push_back(scc);
        }
    }
    return sccs;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e.push_back({x, y});
    }

    vector<vector<int>> sccs = find_scc(n, e);
    for (int i = 0; i < sccs.size(); i++)
    {
        for (int j = 0; j < sccs[i].size(); j++)
        {
            cout << sccs[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
3
5 5
0 1
1 2
2 0
1 3
3 4
4 6
0 1
1 2
2 0
2 3
3 1
3 0
7 8
0 1
1 2
2 0
3 4
4 5
5 3
2 6
6 5
Output
0 2 1
3
4

0 2 1 3

0 2 1
6
5 4 3

 */