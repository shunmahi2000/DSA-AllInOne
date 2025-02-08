#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    forn(i, n)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), [](int &a, int &b)
         { return a > b; });
    for (auto &it : v)
        cout << it << " ";
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
7
12 13 1 43 54 23 2

Expected Output:
54 43 23 13 12 2 1
 */