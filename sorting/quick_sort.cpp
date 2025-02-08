#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)
int partition(vector<int> &v, int s, int e)
{
    int cnt = 0;
    for (int i = s; i < e; i++)
    {
        if (v[i] <= v[e])
            cnt++;
    }

    swap(v[e], v[s + cnt]);
    int i = s, j = s + cnt + 1;
    while (i < s + cnt && j <= e)
    {
        while (i < s + cnt && v[i] <= v[s + cnt])
        {
            i++;
        }
        while (j < e && v[j] > v[s + cnt])
        {
            j++;
        }
        if (i < s + cnt && j <= e)
        {
            swap(v[i], v[j]);
        }
    }
    return s + cnt;
}
void quickSort(vector<int> &v, int s, int e)
{

    if (s < e)
    {
        int mid = partition(v, s, e);
        quickSort(v, s, mid - 1);
        quickSort(v, mid + 1, e);
    }
}
void sort(vector<int> &v)
{
    quickSort(v, 0, v.size() - 1);
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