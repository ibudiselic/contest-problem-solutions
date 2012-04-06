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

#define MAX_SIGS 205000
const int mod = 1000000007;

int F[101];
int invF[101];
int C[51][51];

int sig_ways[MAX_SIGS]; // the signature is a sorted representation of the kinds of items in the row
int sig_perms[MAX_SIGS]; // how many non-sorted representations are there for every sorted repr. (this is the representation from the problem that is used to define beauty)
int total[MAX_SIGS]; // sig_ways*sig_perms
int sig_lim[MAX_SIGS]; // how many of the different non-sorted representations can be used in a single matrix (all larger than 10 will have 10 here)
int dp[2][MAX_SIGS+1][11]; // [i&1][j][k] is the number of ways to choose i rows such that the lowest index signature that is used is no smaller than j and exactly k of the non-sorted representations of signature j have been used

long long fastexp(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return ret;
}

int N, K;
int nsigs;
void gen(int at, int start, int rem, int eq_sz, long long ways, long long perms) {
    if (at == K) {
        if (rem == 0) {
            perms = perms*invF[eq_sz]%mod;
            sig_ways[nsigs] = int(ways);
            sig_perms[nsigs] = int(perms);
            total[nsigs] = int(ways*perms%mod);
            if (K <= 10) {
                sig_lim[nsigs] = min(10, int(perms));
            } else {
                sig_lim[nsigs] = (eq_sz==K ? 1 : 10);
            }
            ++nsigs;
        }
        return;
    }
    if ((K-at)*start < rem) {
        return;
    }
    if (start <= rem) {
        gen(at+1, start, rem-start, eq_sz+1, ways*C[rem][start]%mod, perms);
    }
    for (int v=min(start-1, rem); v>=0; --v) {
        gen(at+1, v, rem-v, 1, ways*C[rem][v]%mod, perms*invF[eq_sz]%mod);
    }
}
class DengklekCountingFormations {
public:
    int numFormations(int M, int N, int K) { // swapped N and M => M rows, N cols
        ::N = N;
        ::K = K;
        F[0] = invF[0] = 1;
        for (int i=1; i<=100; ++i) {
            F[i] = int((long long)F[i-1]*i % mod);
            invF[i] = int(invF[i-1]*fastexp(i, mod-2) % mod);
        }
        C[0][0] = 1;
        for (int i=1; i<=N; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }

        nsigs = 0;
        gen(0, N, N, 0, 1, F[K]);
        
        memset(dp, 0, sizeof dp);
        for (int i=0; i<=nsigs; ++i) {
            dp[1][i][0] = 1;
        }
        for (int i=0; i<M; ++i) {
            int cur = i&1;
            int prev = 1 - cur;
            memset(dp[cur], 0, sizeof dp[cur]);
            for (int take=nsigs-1; take>=0; --take) {
                long long val = 0;
                for (int k=0; k<=sig_lim[take+1]; ++k) { // don't take the 'take' signature
                     val += (long long)dp[cur][take+1][k]*invF[k];
                }
                dp[cur][take][0] = int(val%mod);
                
                int factor = total[take];
                for (int k=1; k<=sig_lim[take]; ++k) { // take the 'take' signature
                    //dp[cur][take][k] = dp[prev][take][k-1]*(sig_perms[take]-(k-1)+mod)%mod*sig_ways[take]%mod;
                    dp[cur][take][k] = int((long long)dp[prev][take][k-1]*factor%mod);
                    factor -= sig_ways[take];
                    if (factor < 0) {
                        factor += mod;
                    }
                }
            }
        }
        
        long long sol = 0;
        for (int k=0; k<=sig_lim[0]; ++k) {
            sol += (long long)dp[(M+1)&1][0][k]*invF[k]%mod;
        }
        sol = sol%mod*F[M]%mod;
        return int(sol);
    }
};
