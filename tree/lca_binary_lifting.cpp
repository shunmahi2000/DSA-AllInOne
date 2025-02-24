#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

void dfs(int cur,int par,vector<int> &depth,vector<vector<int>> &dp,vector<vector<int>> &adj){
    dp[cur][0]=par;
    depth[cur]=depth[par]+1;
    for(int i=1;i<21;i++){
        dp[cur][i]=dp[dp[cur][i-1]][i-1];
    }

    for(auto &it:adj[cur]){
        if(it!=par){
            dfs(it,cur,depth,dp,adj);
        }
    }
}
int lca(int x,int y,vector<int> &depth,vector<vector<int>> &dp){
    if(x==y) return x;

    if(depth[x]>depth[y]){
        swap(x,y);
    }

    int diff=depth[y]-depth[x];
    int ind=0;
    while(diff){
        if(diff&1){
            y=dp[y][ind];
        }
        ind++;
        diff=diff>>1;
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(dp[x][i]!=dp[y][i]){
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}
vector<int> find_lca(int n,vector<vector<int>> &e,vector<vector<int>> & q){
    vector<vector<int>> adj(n);
    for(int i=0;i<e.size();i++){
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
    }

    vector<int> depth(n,0);
    vector<vector<int>> dp(n,vector<int>(21,0));

    dfs(0,0,depth,dp,adj);

    vector<int> ans;
    forn(i,q.size()){
        ans.push_back(lca(q[i][0],q[i][1],depth,dp));
    }
    return ans;

}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<int>> edges;
    forn(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    ll q;
    cin >> q;
    vector<vector<int>> queries;
    forn(i,q){
        int x,y;
        cin>>x>>y;
        queries.push_back({x,y});
    }
    
    vector<int> ans = find_lca(n,edges,queries);
    forn(i,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ll t;
    cin >> t;
    for (ll it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}






/*
Test Cases
6
9
0 1
0 2
2 3
2 4
4 5
4 6
6 7
6 8
4
5 8
1 8
2 6
2 2
5
0 1
0 2
1 3
1 4
3
3 4
3 2
2 4
6
0 1
1 2
2 3
3 4
4 5
3
2 5
3 4
1 5
7
0 1
0 2
1 3
1 4
2 5
2 6
4
3 4
5 6
3 6
2 3
1
2
0 0
0 0
6
0 1
0 2
0 3
0 4
0 5
3
1 2
4 5
2 3

Expected Output:
4 0 2 2 
1 0 0 
2 3 1 
1 2 0 0 
0 0 
0 0 0 
 */