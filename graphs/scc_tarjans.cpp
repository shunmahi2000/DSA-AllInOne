#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, int time, stack<int> &st, vector<int> &disc, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &sccs)
{
    disc[cur] = time;
    low[cur] = time;
    st.push(cur);
    for (auto it : adj[cur])
    {
        if (disc[it] == -1)
        {
            dfs(it, time + 1, st, disc, low, adj, sccs);
            low[cur] = min(low[cur], low[it]);
        }
        else
        {
            low[cur] = min(low[cur], disc[it]);
        }

        /*edge cur---it
        if(dis[cur]<low[it]) cur--low is a  "AB";
        if(dis[cur]<=low[it]) cur is a  "AP";*/
    }
    if (disc[cur] == low[cur])
    {
        vector<int> scc;
        while (true)
        {
            int v = st.top();
            scc.push_back(st.top());
            st.pop();
            if (v == cur)
                break;
        }
        sccs.push_back(scc);
    }
}
vector<vector<int>> find_scc(int n, vector<vector<int>> &e)
{
    vector<int> disc(n, -1), low(n, -1);
    stack<int> st;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e.size(); i++)
    {
        adj[e[i][0]].push_back(e[i][1]);
    }
    vector<vector<int>> sccs;
    dfs(0, 1, st, disc, low, adj, sccs);
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
4
3
2 1 0

3 2 1 0

4 3 5
6
2 1 0

 */