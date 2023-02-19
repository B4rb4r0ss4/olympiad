#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
const int M = 1e9+7;

ll chlopyRosyjskie(ll a,ll b){
	ll res = 0;
	while(b > 0){
		if(b & 1)
	      res += a;
	    a <<= 1;
	    b >>= 1;
 	}
 	return res;
}


int main() {
    turbo;    
    cout<<chlopyRosyjskie(2, 4);
}
