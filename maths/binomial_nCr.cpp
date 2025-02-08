#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

int binomial(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    int ans = 1;

    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << binomial(n, r) << endl;
    return 0;
}