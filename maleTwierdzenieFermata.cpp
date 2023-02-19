#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1e9+7;
ll ferm(ll a, ll k) {
    if(k == 0) 
        return 1;
    if(k & 1) 
        return (ferm(a , k-1)*a)%MOD;
    ll res = ferm(a, k/2);
    return (res*res)%MOD;
}


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
}
