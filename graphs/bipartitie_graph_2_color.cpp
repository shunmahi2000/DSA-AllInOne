#include <bits/stdc++.h>
using namespace std;

bool dfs(int cur,int col,vector<int> &color,vector<vector<int>> &adj){
    color[cur]=col;
    for(auto it:adj[cur]){
        if(color[it]==-1){
            if(!dfs(it,1-col,color,adj)) return false;
        }else if(color[it]==col){
            return false;
        }
    }
    return true;
}
bool using_dfs(int n,vector<vector<int>> &adj){
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(i,0,color,adj)) return false;
        }
    }
    return true;
}

bool using_bfs(int n,vector<vector<int>> &adj){
    vector<int> color(n,-1);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto &neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }

        }
    }
    return true;
}
bool isBipartite(int n,vector<vector<int>> &e){
    vector<vector<int>> adj(n);
    for(int i=0;i<e.size();i++){
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
    }
    // DFS 
    //return using_dfs(n,adj);
    // BFS
    return using_bfs(n,adj);
}
void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    /* GIVEN GRAPH IS 0-BASED INDEXED*/
    cout<<(isBipartite(n,edges)?"Y":"N")<<endl;
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
Input
9
4 3
0 1
1 2
2 3
3 3
0 1
1 2
2 0
4 4
0 1
1 2
2 3
3 0
5 4
0 1
0 2
0 3
0 4
6 9
0 3
0 4
0 5
1 3
1 4
1 5
2 3
2 4
2 5
4 6
0 1
0 2
0 3
1 2
1 3
2 3
6 5
0 1
1 2
2 3
3 0
4 5
10 9
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
7 8
0 1
1 2
2 3
3 0
4 5
5 6
6 4
2 4
Ouput
Y
N
Y
Y
Y
N
Y
Y
N
*/