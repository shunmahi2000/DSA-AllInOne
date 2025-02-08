#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(int n, vector<vector<int>> &e)
{
    vector<int> indeg(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < e.size(); i++)
    {
        adj[e[i][0]].push_back(e[i][1]);
        indeg[e[i][1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (auto it : adj[cur])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    /** IMPORTANT */ // If count != n, it means there is a cycle in the graph
    if (ans.size() != n)
    {
        cout << "Cycle detected! Topological sort not possible." << endl;
        return {};
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
4 5 2 0 3 1
0 1 2 3
0 1 2 3 4
3 4 5 0 1 2
0 1 2 3 4 5 6
*/