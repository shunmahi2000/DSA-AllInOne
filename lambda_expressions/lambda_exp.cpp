#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    auto addition = [&ans](int &x, int y)
    {
        ans += x + y;
    };
    forn(i, n)
    {
        int a;
        cin >> a;
        addition(a, 0);
    }
    cout << ans << endl;
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
7
12 13 1 43 54 23 2

Expected Output:
148
 */