#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const long long mod = 1000000007ll;
const int MAXN = 100;
long long C[MAXN + 1][MAXN + 1];
long long C2[MAXN + 1][MAXN + 1];
long long exp(long long x, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*x%mod;
        }
        x = x*x%mod;
        k /= 2;
    }
    return ret;
}
int n, k;
long long m;
int extra;
long long dp[MAXN + 1][MAXN*MAXN + 1];
long long go(int at, int rem) {
    long long &ret = dp[at][rem];
    if (ret != -1) {
        return ret;
    }
    if (at == n) {
        ret = (rem==0);
    } else {
        ret = 0;
        int lim = min(rem, n);
        for (int take=0; take<=lim; ++take) {
            ret = (ret + (at<extra ? C2[n][take] : C[n][take])*go(at+1, rem-take))%mod;
        }
    }
    return ret;
}
int main() {
    C[0][0] = 1;
    for (int i=1; i<=MAXN; ++i) {
        C[i][0] = 1;
        for (int j=1; j<=i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if (C[i][j] >= mod) {
                C[i][j] -= mod;
            }
        }
    }

    cin >> n >> m >> k;
    for (int i=0; i<=n; ++i) {
        long long val = C[n][i];
        C[n][i] = exp(C[n][i], m/n);
        C2[n][i] = C[n][i]*val%mod;
    }

    extra = int(m%n);
    memset(dp, 0xff, sizeof dp);
    cout << go(0, k) << '\n';
    return 0;
}
