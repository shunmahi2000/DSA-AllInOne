#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

int expo(int x, int n)
{
    int ans = 1, mul = x;
    if (n == 0)
        return 1;

    while (n > 0)
    {
        if (n & 1)
        {
            ans *= (mul);
        }
        mul *= mul;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << expo(x, n) << endl;
    return 0;
}