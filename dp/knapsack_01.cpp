#include <bits/stdc++.h>
using namespace std;
int knapsack01_v1(vector<int> &v, vector<int> &w, int &k)
{
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= w[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    /* TC - O(n*k) SC-O(n*k) */
    return dp[n][k];
}
int knapsack01_v2(vector<int> &v, vector<int> &w, int &k)
{
    int n = v.size();
    vector<int> previous(k + 1, 0);
    vector<int> cur(k + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= w[i - 1])
            {
                cur[j] = max(previous[j], v[i - 1] + previous[j - w[i - 1]]);
            }
            else
                cur[j] = previous[j];
        }
        previous = cur;
    }
    /* TC - O(n*k) SC-O(k) with 2 Rows */
    return cur[k];
}
int knapsack01_v3(vector<int> &v, vector<int> &w, int &k)
{
    int n = v.size();
    vector<int> cur(k + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = k; j >= 1; j--)
        { // right to left
            if (j >= w[i - 1])
            {
                cur[j] = max(cur[j], v[i - 1] + cur[j - w[i - 1]]);
            }
        }
    }
    /* TC - O(n*k) SC-O(k) with 1 Row */
    return cur[k];
}
void solve()
{
    /**
     * k: max weight bag can handle
     * v: value array representing money you will get, if we pick current item
     * w: weight of each item
     */
    int n, k;
    cin >> n >> k;
    vector<int> v, w;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        w.push_back(a);
    }

    cout << knapsack01_v1(v, w, k) << endl;
    // cout << knapsack01_v2(v, w, k) << endl;
    // cout << knapsack01_v3(v, w, k)<< endl;
    // cout << endl;
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
Inputs:
5
4 8
10 40 30 50
5 4 6 3
3 5
10 20 30
1 2 2
5 7
15 10 40 30 50
2 3 1 4 6
4 5
100 200 300 400
10 5 20 25
6 50
60 100 120 200 240 300
10 20 30 40 50 60

Output:
90
60
90
200
260
 */