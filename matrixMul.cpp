#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6;
const int n = 1e6;
long long val[SIZE];

struct Matrix {
    long long GL;
    long long GP;
    long long DL;
    long long DP;
    Matrix operator* (Matrix &b) {
        Matrix temp;
        temp.GL = ((GL * b.GL)%MOD + (GP * b.DL)%MOD)%MOD;
        temp.GP = ((GL * b.GP)%MOD + (GP * b.DP)%MOD)%MOD;
        temp.DL = ((DL * b.GL)%MOD + (DP * b.DL)%MOD)%MOD;
        temp.DP = ((DL * b.GP)%MOD + (DP * b.DP)%MOD)%MOD;
        return temp;
    }
    
    void one(long long gl, long long dl) {
        GL = gl;
        DL = dl;
        GP = 0;
        DP = 0;
    }

    void two(long long gl, long long dl, long long gp, long long dp) {
        GL = gl;
        DL = dl;
        GP = gp;
        DP = dp;
    }

    void neutral() {
        GL = 1;
        DL = 0;
        GP = 0;
        DP = 1;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
}
