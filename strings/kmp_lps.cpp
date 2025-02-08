#include <bits/stdc++.h>
using namespace std;

vector<int> calculate_lps(string s)
{
    if (s.size() == 1)
        return {0};
    vector<int> ans(s.size());
    int i = 0, j = 1;
    while (j < s.size())
    {
        if (s[i] == s[j])
        {
            ans[j] = ++i;
            j++;
        }
        else
        {
            if (i > 0)
                i = ans[i - 1];
            else
                j++;
        }
    }
    return ans;
}
bool isPatternExist(string &s, string &p)
{
    vector<int> lps = calculate_lps(p);
    int i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == p.size())
        {
            // use j= lps[j-1] to find all matches of p in s
            return true;
        }
    }
    return false;
}
vector<int> answerQueries(string &t, vector<string> &p)
{

    vector<int> ans;
    for (int i = 0; i < p.size(); i++)
    {

        ans.push_back(isPatternExist(t, p[i]));
    }
    return ans;
}
void solve()
{
    string t;
    int m;
    cin >> t;
    cin >> m;
    vector<string> patterns;
    for (int i = 0; i < m; i++)
    {
        string p;
        cin >> p;
        patterns.push_back(p);
    }
    vector<int> ans = answerQueries(t, patterns);
    for (auto it : ans)
        cout << it << " ";
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
ababcabc
3
abc
ab
xyz
aaaaa
4
a
aa
aaa
aaaaa
HelloWorld
3
Hello
world
oWo
Output
1 1 0
1 1 1 1
1 0 1
*/
