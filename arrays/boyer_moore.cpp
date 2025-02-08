#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

vector<int> boyerMoore(vector<int> &v)
{
    int cnta = 0, elea = -1, cntb = 0, eleb = -1; // ASSUMPTIONS: Array elements v[i]>=0
    for (int i = 0; i < v.size(); i++)
    {
        if (elea == v[i])
            cnta++;
        else if (eleb == v[i])
            cntb++;
        else if (cnta == 0)
        {
            elea = v[i];
            cnta = 1;
        }
        else if (cntb == 0)
        {
            eleb = v[i];
            cntb = 1;
        }
        else
        {
            cnta--;
            cntb--;
        }
    }

    cnta = 0;
    cntb = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (elea == v[i])
            cnta++;
        if (eleb == v[i])
            cntb++;
    }
    vector<int> ans;
    if (cnta > v.size() / 3)
        ans.push_back(elea);
    if (cntb > v.size() / 3)
        ans.push_back(eleb);
    return ans;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 2, 34};
    vector<int> ans = boyerMoore(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}