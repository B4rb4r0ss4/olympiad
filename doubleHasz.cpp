#include <bits/stdc++.h>
using namespace std;
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
typedef long long ll;
const int SIZE = 1e6+10;
const int MOD = 1e9+9, MOD2 = 1e9+7;
const int BASE = 31, BASE2 = 29;

ll hasz[SIZE], hasz2[SIZE];
ll prePo[SIZE], prePo2[SIZE];
string text; int q;

void pre() {
    prePo[0] = 1;
    prePo2[0] = 1;
    for(int i=1; i<=text.size(); i++) {
        prePo[i] = (prePo[i-1] * BASE)%MOD;
        prePo2[i] = (prePo2[i-1] * BASE2)%MOD2;
    }
    
    for(int i=0; i<text.size(); i++) {
        hasz[i+1] = (hasz[i] * BASE + text[i]-'a')%MOD; 
        hasz2[i+1] = (hasz2[i] * BASE2 + text[i]-'a')%MOD2;
    }
}

pair<ll, ll> getHash(int l, int r) {
    ll xd = (hasz[r] - (hasz[l-1] * prePo[r-l+1])%MOD+MOD)%MOD;
    ll xd2 = (hasz2[r] - (hasz2[l-1] * prePo2[r-l+1])%MOD2+MOD2)%MOD2;
    return {xd, xd2};
}

bool cmp(pair<ll, ll> xd, pair<ll, ll> xd2) {
    if(xd.first == xd2.first && xd.second == xd2.second) return true;
    return false;
}

int main() {
    turbo;
    cin>>text>>q;
    pre();
    while(q-->0) {
        int l, p, l2, p2; cin>>l>>p>>l2>>p2;
        pair<ll, ll> xd = getHash(l, p);
        pair<ll, ll> xd2 = getHash(l2, p2);
        if(cmp(xd, xd2)) {
            cout<<"Te same\n";
            continue;
        }
        cout<<"Rozne\n";

    }
}
