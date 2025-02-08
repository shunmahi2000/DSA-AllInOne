#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void merge(vector<int> &v, int s, int mid, int e)
{
    vector<int> dp(e - s + 1, 0);
    int dpind = 0, x = s, y = mid + 1;
    while (x <= mid && y <= e)
    {
        if (v[x] <= v[y])
        {
            dp[dpind++] = v[x++];
            /** No of elements smaller than y => x-s+1
             * y is in the right of all elements in {s,mid}
             */
        }
        else
            dp[dpind++] = v[y++];
    }
    while (x <= mid)
        dp[dpind++] = v[x++];
    while (y <= e)
        dp[dpind++] = v[y++];
    ;
    for (int i = 0; i < dp.size(); i++)
    {
        v[s + i] = dp[i];
    }
}

void mergeSort(vector<int> &v, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        mergeSort(v, s, mid);
        mergeSort(v, mid + 1, e);
        merge(v, s, mid, e);
    }
}
void sort(vector<int> &v)
{
    mergeSort(v, 0, v.size() - 1);
}

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
    sort(v);
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
2
5
5 7 1 2 5
7
12 13 1 43 54 23 2

Expected Output:
1 2 5 5 7
1 2 12 13 23 43 54
 */