#include <bits/stdc++.h>
using namespace std;
bool isSafe(int cur,vector<int> &color,vector<vector<int>> &adj){
    for(auto it:adj[cur]){
        if(color[it]==color[cur]) return false;
    }
    return true;
}
bool isPossible(int cur,vector<int> &color, vector<vector<int>> &adj,int &m){
    if(cur==adj.size()) return true;
    for(int i=1;i<=m;i++){
        color[cur]=i;
        if(isSafe(cur,color,adj)){
            if(isPossible(cur+1,color,adj,m)) return true;
        }
        color[cur]=0;
    }
    return false;
}
bool isMColoringGraph(int n,int m,vector<vector<int>> &e){
    vector<vector<int>> adj(n);
    for(int i=0;i<e.size();i++){
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
    }
    
    vector<int> color(n,0);
    return isPossible(0,color,adj,m);
}
void solve()
{
    int n, e, m;
    cin >> n >> e>> m;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    /* GIVEN GRAPH IS A CONNECTED GRAPH */
    cout<<(isMColoringGraph(n,m,edges)?"Y":"N")<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
Input:
8
4 3 3
0 1
1 2
2 3
3 3 3
0 1
1 2
2 0
3 3 2
0 1
1 2
2 0
5 4 2
0 1
0 2
0 3
0 4
4 6 4
0 1
0 2
0 3
1 2
1 3
2 3
4 6 3
0 1
0 2
0 3
1 2
1 3
2 3
5 4 2
0 1
1 2
2 3
3 4
10 15 3
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 0
1 4
2 7
3 6
5 8
0 5
Output:
Y
Y
N
Y
Y
N
Y
Y
 */