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
#include <numeric>

using namespace std;

const int mod = 1000000007;
int C[2501][2501];
int F[2501];
int ways[2501][2501]; // [i][j] ways to place j YY coders into challenger and challenged slots of i challenges such that they challenge before they are challenged
long long expmod(long long n, long long k) {
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
class SRMChallengePhase {
public:
    int countWays(vector <string> codersAttempted, vector <string> codersChallenged) {
        string A = accumulate(codersAttempted.begin(), codersAttempted.end(), string());
        string B = accumulate(codersChallenged.begin(), codersChallenged.end(), string());
        int n = A.size();
        int YY=0, YN=0, NY=0;
        for (int i=0; i<n; ++i) {
            if (A[i] == 'Y') {
                if (B[i] == 'Y') {
                    ++YY;
                } else {
                    ++YN;
                }
            } else if (B[i] == 'Y') {
                ++NY;
            }
        }
        F[0] = 1;
        for (int i=1; i<=n; ++i) {
            F[i] = (long long)F[i-1]*i%mod;
        }
        C[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<n; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }
        
        memset(ways, 0, sizeof ways);
        ways[0][0] = 1;
        for (int i=1; i<=YN+YY; ++i) {
            for (int j=0; j<=min(YY, i); ++j) {
                ways[i][j] = ways[i-1][j];
                if (j>0 && j<i) {
                    ways[i][j] += (long long)ways[i-1][j-1]*(i-j)%mod;
                    if (ways[i][j] >= mod) {
                        ways[i][j] -= mod;
                    }
                }
            }
        }
        
        return (long long)ways[YN+YY][YY]*F[YY]%mod*F[YN]%mod*C[YN][NY]%mod*F[NY]%mod*expmod(n-1, YN-NY)%mod;
    }
};
