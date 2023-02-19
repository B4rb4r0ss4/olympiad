#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

const int SIZE = 1e6;
vector<int> adj[SIZE];
bool visited[SIZE];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto i: adj[cur]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
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
    bfs(1);
}
