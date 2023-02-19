#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e6+10;
int ans = 0;
int n; 
int next_free_index = 1;
int tr[SIZE][26];
int fathers[SIZE];
vector<int> koniec;

int add(char c, int father) {
    if(!tr[father][c-'a']) {
        tr[father][c - 'a'] = next_free_index;
        fathers[tr[father][c - 'a']] = father;
        next_free_index++;
    }
    int xd = tr[father][c-'a']; 
    return xd;
}

void insert(string s) {
    int u = 0;
    for(auto i: s) {
        u = add(i, u);
    }
    koniec.push_back(u);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    
    for(int i=1; i<=n; i++) {
        string s; cin>>s;
        insert(s);       
    }
}
