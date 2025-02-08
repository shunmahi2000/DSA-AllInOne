#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

int kadanesAlgo(vector<int> &v)
{
    int maxSum = 0, curSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        curSum += v[i];
        if (maxSum < curSum)
        {
            maxSum = curSum;
        }
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

int main()
{
    vector<int> v = {1, -4, 6, -2, -1, -2, 34};
    cout << kadanesAlgo(v) << endl; // 35
}