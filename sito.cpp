#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e7;
bool isPrime[SIZE];

void sito() {
    isPrime[1] = 1;
    for(int i=2; i*i<SIZE; i++) 
        if(!isPrime[i])
            for(int j=i*i; j<SIZE; j+=i)
                isPrime[j] = 1;
}

int main() {
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    sito();
    for(int i=1; i<100; i++) {
        if(!isPrime[i])
            cout<<i<<" is Prime :D\n";
        else 
            cout<<i<<" id not Prime :(\n";
                
    }

}

