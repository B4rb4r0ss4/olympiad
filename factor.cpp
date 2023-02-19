#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e7;
#define ll long long 
int factor[SIZE];

void sito() {
    factor[1] = 1;
    for(int i=2; i*i<SIZE; i++) {
        if(!factor[i]) {
            for(int j=i*i; j<SIZE; j+=i) {
                if(!factor[j])
                    factor[j] = i;
            }
        }
    }

    for(int i=1; i<SIZE; i++) {
        if(!factor[i]) factor[i] = i;
    }
}

vector<int> factoring(int a) {
    vector<int> f;
    do {
        f.push_back(factor[a]);
        a/=factor[a];
    } while(factor[a] != 1);
    sort(f.begin(), f.end());
    return f;
}

vector<ll> factoringBig(ll a) {
    vector<ll> f;
    ll N = a;
    for(ll i=2; i*i<=N; i++) {
        while(a%i==0) {
            a/=i;
            f.push_back(i);
        }
    }
    if(a!=1) f.push_back(a);
    return f;
}

int main() {
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
//    sito();
    ll n; cin>>n;
    vector<ll> factors = factoringBig(n);
    for(auto i: factors) cout<<i<<' ';
}

