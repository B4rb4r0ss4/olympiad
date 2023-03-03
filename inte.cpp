#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int N = 1e7;

ld fun1(ld x) {
    ld xpow = x*x;
    return ((xpow*xpow*2-5*xpow-12)/1000);
}

ld fun2(ld x) {
    ld xpow = x*x; 
    return ((-(xpow*x*2)+3*x+10)/60);
}

ld calcIntegral(ld p, ld k, ld(*f)(ld)) {
    ld dx = (k-p)/N;
    ld val = 0;
    for(int i=1; i<=N; i++) 
        val+=f(p+i*dx);
    return val*dx;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    ld ans1 = calcIntegral(2, 10, fun1);
    ld ans2 = calcIntegral(10, 2, fun2);
    cout<<setprecision(3)<<fixed<<(ans1+ans2);
}
