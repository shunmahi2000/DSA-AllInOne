#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void solve()
{
    auto comp = [](vector<int> &a, vector<int> &b)
    { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>
        pq(comp);
    /**
     * When comparator function return true in
     * 1. Vector
     *      1.1 a<b -> true a get the priority in vector
     * 2. Priority Queue
     *      2.1  a<b -> true b get the priority in pq, b will come at top
     */

    pq.push({1, 5});
    pq.push({1, 6});
    pq.push({1, 7});
    pq.push({2, 5});

    if (pq.top()[0] == 1 & pq.top()[1] == 7)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;
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

Expected Output:
True
 */