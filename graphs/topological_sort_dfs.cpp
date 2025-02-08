#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[cur] = 1;
    for (auto it : adj[cur])
    {
        if (vis[it] == 0)
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(cur);
}
vector<int> topologicalSort(int n, vector<vector<int>> &e)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < e.size(); i++)
    {
        adj[e[i][0]].push_back(e[i][1]);
    }

    vector<int> vis(n, 0);
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {

            dfs(i, vis, st, adj);
        }
    }
    while (st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

    vector<int> ans = topologicalSort(n, e);
    for (auto it : ans)
        cout << it << " ";
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
5
6 6
5 2
5 0
4 0
4 1
2 3
3 1
4 3
0 1
1 2
2 3
5 4
0 1
0 2
1 3
2 4
6 3
5 2
4 1
3 0
7 7
0 1
0 2
1 3
2 3
3 4
3 5
5 6
Output
5 4 2 3 1 0
0 1 2 3
0 2 4 1 3
5 4 3 2 1 0
0 2 1 3 5 6 4
*/