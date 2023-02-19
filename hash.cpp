#include <bits/stdc++.h>
using namespace std;
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
typedef long long ll;

const ll SIZE = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll BASE = 31;

ll hsh[SIZE], potPre[SIZE];
string text;

void pre() {
    potPre[0] = 1;
    for (int i=1; i<text.size(); i++) {
        potPre[i] = (potPre[i-1]*BASE) % MOD;
    }
    for (int i=0; i<text.size(); i++) {
        hsh[i+1] = (hsh[i]*BASE+text[i]) % MOD;
    }
}

ll getHash(int l, int r) {
    ll result = (hsh[r] - (hsh[l-1] * potPre[r-l+1]) % MOD + MOD) % MOD;
    return result;
}

int main() {
    turbo;
    int q;
    cin>>text>>q;
    pre();
    while(q-->0) {
        int l1, r1, l2, r2; cin>>l1>>r1>>l2>>r2;
        ll has1 = getHash(l1, r1);
        ll has2 = getHash(l2, r2);
        if(has1==has2) cout<<"ROWNY";
        else {
            int lo = -1; 
            int hi = min(r1-l1, r2-l2);
            while((lo+1)<hi) {
                int mid = (lo+hi)/2;
                if(getHash(l1, l1+mid) == getHash(l2, l2+mid))
                    lo = mid;
                else 
                    hi = mid;
            }
            ll ha1 = getHash(l1, l1+hi);
            ll ha2 = getHash(l2, l2+hi);
            if(ha1 == ha2) {
                if(r1-l1 > r2-l2) cout<<"WIEKSZY";
                else cout<<"MNIEJSZY";
            } else if(ha1 > ha2) cout<<"WIEKSZY";
            else cout<<"MNIEJSZY";
        }
        cout<<'\n';
    }
    return 0;
}
