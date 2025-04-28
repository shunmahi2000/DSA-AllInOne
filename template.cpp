/*---------------------------------------------------------*/
/* HIMANSHU YADAV | MAC GCC SETUP                          */
/*---------------------------------------------------------*/
/*
1. Install Homebrew
2. brew install gcc
3. brew list --versions gcc      # confirm version (e.g., gcc-14)
4. g++-14 --version              # confirm brew g++
5. g++ --version                 # still clang by default
6. cd /opt/homebrew/bin
7. ln -s g++-14 g++              # override clang (optional)
8. rm g++                        # restore clang if needed

VIDEO GUIDE: https://youtube.com/watch?v=CZ7Mf7qxbIU


Commands
g++ test.cpp -o test.bin
    1. g++ a compiler
    2. test.cpp - which file to run
    3. -o - Output file option: tells the compiler what the compiled executable should be named.
    4. -g = for debugging 
    5. -std=c++17	Use the C++17 standard
*/

// Optional: PBDS (only if you're using g++-14 with libstdc++)
// #include<bits/stdc++.h> - no compatible with clang (MacOS official compiler)
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <limits>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cstring> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<char> vchar;
typedef vector<bool> vbool;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<vector<char>> vvchar;
typedef vector<vector<bool>> vvbool;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll M = 1000000007;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void debg(ll a, ll b = 0, ll c = 0) { cout << a << ' ' << b << ' ' << c << endl; }
void debgv(v64 &v)
{
    forn(i, v.size()) cout << v[i] << ' ';
    cout << endl;
}
/*---------------------------------------------------------*/
/* Utility Functions                                       */
/*---------------------------------------------------------*/
v64 d4x = {-1, 0, 0, 1}, d4y = {0, 1, -1, 0};
v64 d8x = {-1, -1, -1, 0, 0, 1, 1, 1}, d8y = {-1, 0, 1, -1, 1, -1, 0, 1};
vbool primes;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
/*----Sieve----*/
void sieve(ll n)
{
    primes.resize(n + 1, true);
    primes[0] = false, primes[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
}
/*----x^N----*/
ll power(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res) * (x));
        }
        x = ((x) * (x));
        n = n >> 1;
    }
    return res;
}
/*----Binomial----*/
ll binomial(ll n, ll k)
{
    if (k == 0 || k == n)
        return 1;
    if (k > n - k)
        k = n - k;
    ll ans = 1;
    for (ll i = 0; i < k; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
/*----Fibonacci----*/
ll fibonacci(ll n)
{
    map<ll, ll> mp;
    mp[0] = 0, mp[1] = 1;
    if (mp.find(n) != mp.end())
    {
        return mp[n];
    }
    ll k = n / 2;
    if (n % 2 == 0)
        return mp[n] = ((fibonacci(k) * fibonacci(k)) + (fibonacci(k - 1) * fibonacci(k - 1))) % M;
    else
        return mp[n] = ((fibonacci(k) * fibonacci(k + 1)) + (fibonacci(k - 1) * fibonacci(k))) % M;
    return 0;
}
/*----Euclid----*/
void extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    extendedEuclid(b, a % b, x, y);
    ll cx = y, cy = x - (a / b) * y;
    x = cx, y = cy;
}
ll modInverse(ll a, ll b)
{
    ll x = 1, y = 0;
    extendedEuclid(a, b, x, y);
    return (x + b) % b;
}
ll crt(vv64 &v)
{
    ll ans = 0, n = v.size(), m = 1;
    forn(i, n) m *= v[i][0];
    forn(i, n)
    {
        ll term = 1;
        for (ll j = 0; j < i; j++)
        {
            term *= v[j][0];
            term *= modInverse(v[j][0], v[i][0]);
            term %= m;
        }
        ans += (term * (v[i][1] + m - ans)) % m;
        ans %= m;
    }
    return ans;
}
/*---------------------------------------------------------*/
/* DSU (Disjoint Set Union)                                */
/*---------------------------------------------------------*/
ll dsu_find(ll a, v64 &par)
{
    if (par[a] == a)
        return a;
    par[a] = dsu_find(par[a], par);
    return par[a];
}
void dsu_union(ll a, ll b, v64 &par, v64 &rank)
{
    ll pa = dsu_find(a, par), pb = dsu_find(b, par);
    if (pa == pb)
        return;
    else
    {
        int ra = rank[pa], rb = rank[pb];
        if (ra <= rb)
        {
            par[pa] = pb;
            rank[pa]++;
        }
        else
        {
            par[pb] = pa;
            rank[pb]++;
        }
    }
}
/*---------------------------------------------------------*/
/* Segment Tree (Iterative)                                */
/*---------------------------------------------------------*/
void build(v64 &arr, v64 &tree)
{
    ll n = arr.size();
    for (ll i = 0; i < n; i++)
        tree[n + i] = arr[i];
    for (ll i = n - 1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void updateTreeNode(ll p, ll value, v64 &tree, ll n)
{
    tree[p + n] = value, p += n;
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}
ll query(ll l, ll r, v64 &tree, ll n)
{
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += tree[l++];
        if (r & 1)
            res += tree[--r];
    }
    return res;
}
/*---------------------------------------------------------*/
/* Problem Solve                                           */
/*---------------------------------------------------------*/
v64 getArray(ll ind, v64 &box) {
    ll midX = (box[0] + box[2]) / 2;
    ll midY = (box[1] + box[3]) / 2;
    
    if (ind == 0) {
        return {box[0], box[1], midX, midY};
    } else if (ind == 1) {
        return {midX + 1, midY + 1, box[2], box[3]};
    } else if (ind == 2) {
        return {midX + 1, box[1], box[2], midY};
    }
    return {box[0], midY + 1, midX, box[3]};
}

v64 dfs(ll d, ll x,ll y, v64 box){
    if(x==y){
        return {box[0],box[1]};
    }
    ll diff = (y-x+1)/4;

    ll ind = 0;
    while(ind<4){
        if(x<=d && x+diff>d) {
            return dfs(d,x,x+diff-1, getArray(ind,box));
        }
        ind++;
        x+=diff;
    }
    return {};
}
bool isValid(v64 &box, ll &a, ll&b){
    return a>=box[0] && a<=box[2] && b>=box[1] && b<=box[3];
}
ll dfs2(ll a,ll b,ll x,ll y, v64 box){
    if(x==y) return x;
    ll diff = (y-x+1)/4;
    for(int i=0;i<4;i++){
        v64 newBox = getArray(i,box);
        if(isValid(newBox,a,b)){
            return dfs2(a,b,x,x+diff-1,newBox);
        }
        x+=diff;
    }
    return 0;

}
void solve(){
    ll n,q;
    cin>>n>>q;

    forn(i,q){
        string s;
        cin>>s;
        string temp = s.substr(0,2);
        ll x = 1, y= (1ll<<(2*n));
        v64 box= {1,1,1ll<<n, 1ll<<n};
        if(temp == "->"){
            ll a,b;
            cin>>a>>b;
            int val = dfs2(a,b,x,y,box);
            cout<<val<<endl;

        }else{
            ll d;
            cin>>d;
            v64 ans = dfs(d,x,y,box);
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_cin();
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}

/*
launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debugger Him",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/test.bin",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "build test.cpp"
        }
    ]
}
*/
/*
task.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build test.cpp",
            "type": "shell",
            "command": "g++",
            "args": [
                "test.cpp",
                "-g",
                "-o",
                "test.bin"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        }
    ]
}
*/
