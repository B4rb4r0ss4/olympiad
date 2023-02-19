#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#define ll long long

ll fastExp(ll base, ll power) {
    if(!power) return 1;
    if(power & 1) return (base * fastExp(base, power-1))%MOD;
    ll x = fastExp(base, power/2);
    return (x*x)%MOD;
}


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int q; cin>>q;
    while(q-->0) {
        ll a, b; cin>>a>>b;
        cout<<fastExp(a, b)<<'\n';
    }

}
