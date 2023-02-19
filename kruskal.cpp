#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1e6;
int repre[SIZE];
vector<pair<int, int>> adj;
vector<pair<int, int>> val;

int find(int a) {
    if(repre[a] == a) return a;
    repre[a] = find(repre[a]);
    return repre[a];
}

void unionn(int a, int b) {
    repre[find(a)] = find(b);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a, b, w; cin>>a>>b>>w;
        adj.push_back({a, b});
        val.push_back({w, i});
    }
    sort(val.begin(), val.end());
    
    for(int i=0; i<=n; i++) repre[i] = i;
    long long valu = 0;
    for(auto i: val) {
        if(find(adj[i.second].first) != find(adj[i.second].second)) {
            unionn(adj[i.second].first, adj[i.second].second);
            valu += i.first;
        }
    
    }
    cout<<valu;
}
