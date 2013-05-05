#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int A[10];
const long long mod = 1000000007;
long long C[101][101];
long long p10[101];
long long dp[101][11][11];
long long calc(int len, int first, int d) {
    long long &ret = dp[len][first][d];
    if (ret != -1) {
        return ret;
    }
    if (d == 10) {
        ret = (len==0 ? 1 : 0);
    } else {
        int need = A[d];
        if (first==d && need>0) {
            --need;
        }
        ret = 0;
        for (int take=need; take<=len; ++take) {
            ret = ret + C[len][take]*calc(len-take, first, d+1)%mod;
        }
        ret %= mod;
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i=0; i<10; ++i) {
        cin >> A[i];
        total += A[i];
    }
    memset(dp, 0xff, sizeof dp);
    
    C[0][0] = 1;
    for (int i=1; i<101; ++i) {
        C[i][0] = 1;
        for (int j=1; j<=i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    p10[0] = 1;
    for (int i=1; i<101; ++i) {
        p10[i] = p10[i-1]*10%mod;
    }

    long long sol = 0;
    for (int len=total; len<=n; ++len) {
        for (int first=1; first<10; ++first) {
            if (len==total && A[first]==0) {
                continue;
            }
            sol = (sol + calc(len-1, first, 0))%mod;
        }
    }
    
    cout << sol << '\n';
    
    return 0;
} 
