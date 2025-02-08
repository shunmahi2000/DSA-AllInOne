#include <bits/stdc++.h>
using namespace std;
vector<int> bellman(int n, int src, vector<vector<int>> &e)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < e.size(); j++)
        {
            int src = e[j][0], dest = e[j][1], weight = e[j][2];
            if (dist[dest] > dist[src] + weight)
            {
                dist[dest] = dist[src] + weight;
            }
        }
    }
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
    vector<int> dist = bellman(n, s, e);
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