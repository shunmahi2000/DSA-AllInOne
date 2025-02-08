#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

ll dsu_find(ll x, vector<ll> &par)
{
    if (par[x] == x)
        return x;
    return par[x] = dsu_find(par[x], par);
}

void dsu_union(ll x, ll y, vector<ll> &par, vector<ll> &rank)
{
    ll px = dsu_find(x, par), py = dsu_find(y, par);
    if (px == py)
        return;

    if (rank[px] < rank[py])
    {
        par[px] = py;
    }
    else if (rank[py] < rank[px])
    {
        par[py] = px;
    }
    else
    {
        par[py] = px;
        rank[px]++;
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> e;
    forn(i, m)
    {
        ll x, y;
        cin >> x >> y;
        e.push_back({x, y});
    }

    vector<ll> par(n), rank(n, 0);
    forn(i, n) par[i] = i;

    forn(i, m)
    {
        ll x = e[i][0], y = e[i][1];
        dsu_union(x, y, par, rank);
    }

    forn(i, n)
    {
        par[i] = dsu_find(i, par);
        cout << par[i] << " ";
    }
    cout << endl;
}

int main()
{
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

/*
Test Cases
1
7 5
0 1
1 2
3 4
0 4
5 6

Expected Output:
0 0 0 0 0 5 5
 */