#include<bits/stdc++.h>
using namespace std;
const int MAX = 1<<19;
#define ll long long
ll tr[2*MAX];

ll query(int l, int r) {
    ll sum = 0;
    l+=MAX;
    r+=MAX;
    while(l<=r) {
        if(l&1)
            sum+=tr[l];
        if(!(r&1))
            sum+=tr[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    return sum;
}

void update(int x, int val) {
    x+=MAX;
    tr[x] += val;
    while(x/=2)
        tr[x] = tr[2*x]+tr[2*x+1];
}

void build() {
    for(int i=MAX-1; i>0; i--) 
        tr[i] = tr[2*i]+tr[2*i+1];
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
            cout<<query(l, r)<<'\n';
        } else {
            int v, val; cin>>v>>val;
            update(v, val);
        }
    }
}
