#include <bits/stdc++.h>
using namespace std;

int randi(int a, int b) {
    return a+rand()%(a+b-1);
}

int main(int xd, char *lol[]) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    srand(atoi(lol[1]));
    int n = randi(5, 1000);
    int q = randi(1000, 2000);
    cout<<n<<' '<<q<<'\n';
    for(int i=0; i<n; i++) {
        cout<<randi(100, 10000)<<' ';
    }
   while(q-->0) {
        int a = randi(1, 2);
        cout<<a-1<<' ';
        if(a==2) {
            int l = randi(1, n);
            cout<<l; 
        } else {
            int l = randi(1, n);
            int r = randi(l, n);
            int val = randi(100, 1000);
            cout<<l<<' '<<r<<' '<<val;
        }
        cout<<'\n';
    }
}
