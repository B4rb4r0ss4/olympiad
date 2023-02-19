#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6+10;
vector<int> adj[SIZE];
bool dead[SIZE];
int pre[SIZE], low[SIZE];
int ktoraSpojna[SIZE];
vector<int> spojne[SIZE];
stack<int> st;
int timer = 0, ile = 0; 
int inc[SIZE];


void scc(int v) {
    dead[v] = 1;
    st.push(v);
    pre[v] = timer;
    timer++;
    low[v] = pre[v];
    for(auto i: adj[v]) {
        if(!dead[i]) {
            scc(i);
        }
        low[v] = min(low[v], low[i]);
    }
    if(low[v] == pre[v]) {
        int rep = v;
        while(st.top() != rep) {
            ktoraSpojna[st.top()] = rep;
            spojne[rep].push_back(st.top());
            low[st.top()] = SIZE + 69;
            st.pop();
        }
        ktoraSpojna[st.top()] = rep;
        spojne[rep].push_back(st.top());
        low[st.top()] = SIZE + 69;
        st.pop();
        ile++;
    }
}
bool visited[SIZE];
set<int> adj2[SIZE];
void dfs(int v) {
    visited[v] = 1;
    for(auto i: adj[v]) {
        if(ktoraSpojna[i] != ktoraSpojna[v]) {
            int XD = adj2[ktoraSpojna[v]].size();
            adj2[ktoraSpojna[v]].insert(ktoraSpojna[i]);
            if(XD != adj2[ktoraSpojna[v]].size())
                inc[ktoraSpojna[i]]++;
        }
        if(!visited[i]) dfs(i);
    }

}
unordered_set<int> v[SIZE];
int main() {
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=0; i<n; i++) {
        if(!dead[i]) scc(i);
    }
    cout<<ile<<'\n'; 

    

    for(int i=0; i<n; i++) {
        if(!visited[i]) 
        dfs(i);
    }
    unordered_set<int> sortedTop;
    for(int i=0; i<n; i++) {
        if(inc[ktoraSpojna[i]] == 0) {
            sortedTop.insert(ktoraSpojna[i]);
        }
    }   
    queue<int> q;
    for(auto i: sortedTop) {
        q.push(i);
    }
    vector<int> ve;
    while(!q.empty()) {
        ve.push_back(q.front());
        int xd = q.front();
        q.pop();
        for(auto i: adj2[xd]) {
            inc[i]--;
            if(inc[i] == 0) q.push(i);
        }
    }

    for(auto i: ve) {
        cout<<spojne[i].size()<<' ';
        for(auto j: spojne[i]) cout<<j<<' ';
        cout<<'\n';
    }
}
