#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1e6;
vector<int> adj[SIZE];
const int LOGN = 21;
int subTree[SIZE];
int pre[SIZE];
int jump[LOGN][SIZE];
int timer = 0;
bool dead[SIZE];

bool child(int x, int y) {
    return pre[x] >= pre[y] && pre[x] < pre[y] + subTree[y];
}

void dfs(int v) {
    timer++;
    dead[v] = 1;
    pre[v] = timer;
    subTree[v] = 1;
    for(auto i: adj[v]) {
        if(!dead[i]) {
            jump[0][i] = v;
            dfs(i);
            subTree[v]+=subTree[i];
        }
    }
}

int lca(int a, int b) {
    if(child(a, b)) return b;
    if(child(b, a)) return a;

    int j = LOGN-1, i = a;
    while(j>=0) {
        if(child(b, jump[j][i]))
            j--;
        else 
            i = jump[j][i];
    }
    return jump[0][i];
}

int main() {
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for(int i=1; i<n; i++) {
        int a; cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(0);

	jump[0][1] = 0;
	for(int i = 1; i < LOGN; i++)
		for(int j = 1; j < SIZE; j++)
			jump[i][j] = jump[i-1][jump[i-1][j]];
    
    while(q--) {
        int a, b; cin>>a>>b;
        cout<<lca(a, b)<<'\n';
    }

}
