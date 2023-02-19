#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define turbo cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
const int SIZE = 1e6;
vector<int> ele;

int main() {
    turbo;    
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++) {
        int a; cin>>a;
        ele.push_back(a);
    }

    sort(ele.begin(), ele.end());
    while(q-->0) {
        int a; cin>>a;
        int lo = -1; int hi = ele.size();
        int ope = 0;
        while((lo+1)<hi) {
            int mid = (lo+hi)/2;
            ope++;
            if(ele[mid] < a) lo = mid;
            else hi = mid;
        }
        cout<<ele[hi]<<" znaleziono po "<<ope<<endl;
    }
}
