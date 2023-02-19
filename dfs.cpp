#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

const int SIZE = 1e6;
vector<int> adj[SIZE];
bool visited[SIZE];

void dfs(int v) {
    visited[v] = 1;
    for(auto i: adj[v]) {
        if(!visited[i])
            dfs(i);
    }
}

int main() {
    turbo;    
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
}
