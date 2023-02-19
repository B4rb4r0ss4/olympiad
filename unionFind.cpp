#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1e6;
int repre[SIZE];

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
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++) 
        repre[i]=i;

    while(q-->0) {
        int o; cin>>o;
        if(!o) {
            int a, b; cin>>a>>b;
            unionn(a, b);
        } else {
            int a, b; cin>>a>>b;
            if(find(a) == find(b)) cout<<1;
            else cout<<0;
            cout<<'\n';
        }
    }



}
