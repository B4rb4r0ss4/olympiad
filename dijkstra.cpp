#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6;
typedef long long ll;
vector<pair<int, int>> adj[SIZE];
ll distancee[SIZE];
int backTrack[SIZE];
int t;
void dijkstra(int a) {
    priority_queue<pair<ll, pair<int, vector<int>>>> q;
    q.push({0, {a, {a}}});
    distancee[a] = 0;
    while(!q.empty()) {
        int cur = q.top().second.first;
        auto ajd = q.top().second.second;
        ll val = -q.top().first;
        q.pop();
        if(distancee[cur] < val)
            continue;
        for(auto i: adj[cur]) {
            if(distancee[i.second] > val+i.first) {
                distancee[i.second] = val+i.first;
                backTrack[i.second] = cur; 
                q.push({-(val+i.first), {i.second, ajd}});
            }

        }
    }
}

int main() {
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    
    int n, m, s; cin>>n>>m>>s>>t;
    for(int i=0; i<m; i++) {
        int a, b, x; cin>>a>>b>>x;
        adj[a].push_back({x, b});
    }
    for(int i=0; i<=n; i++) distancee[i] = 1e18;
    dijkstra(s);
    
    if(distancee[t]==1e18) distancee[t] = -1; 
    cout<<distancee[t];
       
    if(distancee[t]!=-1) {
        int xd = t;

        vector<int> trasa;
        trasa.push_back(xd);
        while(xd != s) {
            xd = backTrack[xd];
            trasa.push_back(xd);
        }
        cout<<' ';
        cout<<trasa.size()-1<<'\n';
        for(int i=trasa.size()-1; i>=1; i--) {
            cout<<trasa[i]<<' '<<trasa[i-1]<<'\n';
        }
    }
}
