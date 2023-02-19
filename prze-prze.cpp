#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1<<20;

int lazy[2*MAX], tr[2*MAX];

void lazyPro(int v, int lo, int hi, int mid) {
    if(lazy[v] != -1) {
        lazy[2*v] = lazy[v];
        lazy[2*v+1] = lazy[v];
        tr[2*v] = (mid - lo) * lazy[v];
        tr[2*v+1] = (hi - mid) * lazy[v];
        lazy[v] = -1;
    }

}

ll query(int l, int r, int v, int lo, int hi) {
    if(l == lo && r == hi) {
        return tr[v];
    }
    if(r<=l) return 0;
    
    int mid = (lo+hi)/2;
    lazyPro(v, lo, hi, mid);
    ll L = query(l, min(mid, r), 2*v, lo, mid);
    ll R = query(max(l, mid), r, 2*v+1, mid, hi);
    return L+R;
}

void update(int l, int r, int v, int lo, int hi, int val) {
    if(l == lo && r == hi) {
        lazy[v] = val;
        tr[v] = (hi - lo) * val;
        return;
    }
    if(r<=l) return;

    int mid = (lo+hi)/2;
    lazyPro(v, lo, hi, mid);
    update(l, min(r, mid), 2*v, lo, mid, val);
    update(max(l, mid), r, 2*v+1, mid, hi, val);
    tr[v] = tr[2*v]+tr[2*v+1];
}

void build() {
    for(int i=MAX-1; i>0; i--) {
        lazy[i] = -1;
        tr[i] = tr[2*i] + tr[2*i+1];
    }
    for(int i=MAX; i<MAX*2; i++)
        lazy[i] = -1;
}


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for(int i=1; i<=n; i++) 
        cin>>tr[i+MAX];
    build();

    while(q-->0) {
        int o; cin>>o;
        if(o) {
            int l, r; cin>>l>>r;
            r++;
            cout<<query(l, r, 1, 1, MAX)<<'\n';
        } else {
            int l, r, v; cin>>l>>r>>v;
            r++;
            update(l, r, 1, 1, MAX, v);
        }

    }
}

