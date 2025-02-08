#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floydWarshall(int n, vector<vector<int>> &e)
{
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < e.size(); i++)
    {
        dp[e[i][0]][e[i][1]] = e[i][2];
    }
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    return dp;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back({x, y, w});
    }
    vector<vector<int>> dist = floydWarshall(n, e);
    for (auto &it : dist)
    {
        for (auto &it2 : it)
            cout << it2 << " ";
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
}

/*
Input
3
4 4
0 1 5
1 2 3
2 3 1
0 3 10
3 6
0 1 2
0 2 4
1 0 2
1 2 1
2 0 4
2 1 1
4 3
0 1 4
1 2 8
2 3 6
output
0 5 8 9
2147483647 0 3 4
2147483647 2147483647 0 1
2147483647 2147483647 2147483647 0

0 2 3
2 0 1
3 1 0

0 4 12 18
2147483647 0 8 14
2147483647 2147483647 0 6
2147483647 2147483647 2147483647 0

 */