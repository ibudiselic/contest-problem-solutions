#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int m, n;
const int mod = 1000000009;
int choose[51][51];

long long fastexp(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k&1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return ret;
}
int dp[51][51];
int calc(int h1, int w1, int h2, int w2, int H) {
    memset(dp, 0, sizeof dp);
    dp[h2][w1] = 1;
    for (int i=h2-1; i>=0; --i) {
        for (int j=0; j<=w1; ++j) {
            dp[i][j] = 0;
            for (int k=0; k<=w1-j; ++k) {
                long long add = choose[w1-j][k]*fastexp(H, w1-j-k)%mod*fastexp(H+1, j + (i<h1 ? w2-w1 : 0))%mod;
                if (k==0 && i<h1) {
                    add -= fastexp(H, (i<h1 ? w2 : w1));
                    if (add < 0) {
                        add += mod;
                    }
                }
                dp[i][j] = (dp[i][j] + add*dp[i+1][j+k]%mod)%mod;
            }
        }
    }
    return dp[0][0];
}
class AxonometricProjection {
public:
    int howManyWays(vector <int> R, vector <int> C) {
        m = R.size();
        n = C.size();
        sort(R.begin(), R.end());
        sort(C.begin(), C.end());
        if (R.back() != C.back()) {
            return 0;
        }
        choose[0][0] = 1;
        for (int i=1; i<51; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j=1; j<i; ++j) {
                choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % mod;
            }
        }
        
        long long sol = 1;
        for (int iter=0; iter<2; ++iter) {
            for (int i=0; i<m; ++i) {
                if (i==0 || R[i]!=R[i-1]) {
                    pair<vector<int>::iterator, vector<int>::iterator> range = equal_range(C.begin(), C.end(), R[i]);
                    int j = range.first - C.begin();
                    int h1 = upper_bound(R.begin(), R.end(), R[i]) - R.begin() - i;
                    assert(h1 > 0);
                    int w1 = range.second - range.first;
                    int h2 = (w1==0 ? h1 : m-i);
                    int w2 = n - j;
                    if (!iter || w1==0) {
                        sol = sol*calc(h1, w1, h2, w2, R[i])%mod;
                    }
                }
            }
            
            R.swap(C);
            swap(m, n);
        }
        
        return sol;
    }
};
