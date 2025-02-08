#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n, int src, vector<vector<int>> &e)
{
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < e.size(); i++)
    {
        adj[e[i][0]].push_back({e[i][1], e[i][2]});
    }

    /* SET IMPL */
    set<vector<int>> st;
    st.insert({0, src});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (st.size())
    {
        vector<int> temp = *(st.begin());
        st.erase(st.begin());
        int cur = temp[1], curCost = temp[0];

        for (auto &it : adj[cur])
        {
            if (dist[it[0]] > dist[cur] + it[1])
            {
                if (st.find({dist[it[0]], it[0]}) != st.end())
                {
                    st.erase({dist[it[0]], it[0]});
                }
                dist[it[0]] = dist[cur] + it[1];
                st.insert({dist[it[0]], it[0]});
            }
        }
    }
    /* PRIORITY QUEUE IMPL
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src}); // {distance, node}
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int curCost = temp[0], cur = temp[1];

        for (auto &[next, weight] : adj[cur])
        {
            if (dist[next] > dist[cur] + weight)
            {
                dist[next] = dist[cur] + weight;
                pq.push({dist[next], next});
            }
        }
    }*/
    return dist;
}
void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    vector<vector<int>> e;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back({x, y, w});
    }
    vector<int> dist = dijkstra(n, s, e);
    for (auto &it : dist)
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
}

/*
Input
3
5 0 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
4 0 3
0 1 5
1 2 10
2 3 2
6 0 9
0 1 1
0 2 5
1 2 2
1 3 2
2 3 1
2 4 3
3 4 2
3 5 1
4 5 2
output
0 2 3 9 6
0 5 15 17
0 1 3 3 5 4
 */