#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void dfs(ll par, ll cur, vector<vector<ll>> &adj, vector<vector<ll>> &dp, vector<ll> &depth)
{
    dp[cur][0] = par;
    depth[cur] = depth[par] + 1;
    for (ll i = 1; i < 21; i++)
    {
        dp[cur][i] = dp[dp[cur][i - 1]][i - 1];
    }
    for (auto &it : adj[cur])
    {
        if (it != par)
        {
            dfs(cur, it, adj, dp, depth);
        }
    }
}
ll lca(ll x, ll y, vector<vector<ll>> &dp, vector<ll> &depth)
{
    if (x == y)
        return x;
    if (depth[x] > depth[y])
        swap(x, y);
    int diff = abs(depth[x] - depth[y]);
    for (int i = 0; i < 21; i++)
    {
        if (diff & (1 << i))
        {
            y = dp[y][i];
        }
    }
    if (x == y)
        return x;
    for (ll i = 20; i >= 0; i--)
    {
        if (dp[x][i] != dp[y][i])
        {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> e;
    forn(i, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        e.push_back({x, y});
    }
    vector<vector<ll>> adj(n + 1);
    vector<ll> depth(n + 1, 0);
    for (ll i = 0; i < e.size(); i++)
    {
        adj[e[i][0] + 1].push_back(e[i][1] + 1);
        adj[e[i][1] + 1].push_back(e[i][0] + 1);
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(21, 0));
    dfs(0, 1, adj, dp, depth);
    ll q;
    cin >> q;
    forn(i, q)
    {
        ll x, y;
        cin >> x >> y;
        cout << lca(x + 1, y + 1, dp, depth) - 1 << endl;
    }
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

/*
Test Cases
1
9
0 1
0 2
2 3
2 4
4 5
4 6
6 7
6 8
4
5 8
1 8
2 6
2 2

Expected Output:
4
0
2
2
 */