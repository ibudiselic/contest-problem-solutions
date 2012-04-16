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

const int mod = 10007;
inline void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int fastexp(int n, int k) {
    int ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return ret;
}
int F[5001];
int invF[5001];
inline int C(int n, int k) {
    return n<k ? 0 : F[n]*invF[n-k]%mod*invF[k]%mod;
}
int line_ways[2501][101]; // [i][j] #ways to get sum j with i cells containing x in [0, S] with no choices
int down_ways[2501][101]; // [i][j] #ways to get sum j with i downward moves, choosing between down and right at each step
int right_ways[2501][101];
int powSp1[2500*2500+1]; // [i] (S+1)^i
class FoxAndGreed {
public:
    int count(int H, int W, int S) {
        memset(line_ways, 0, sizeof line_ways);
        line_ways[0][0] = 1;
        for (int i=1; i<2501; ++i) {
            for (int sum=0; sum<=S; ++sum) {
                line_ways[i][sum] = 0;
                for (int x=0; x<=sum; ++x) {
                    add(line_ways[i][sum], line_ways[i-1][sum-x]);
                }
            }
        }
        if (H == 1) {
            return line_ways[W-1][S];
        }
        if (W == 1) {
            return line_ways[H-1][S];
        }

        powSp1[0] = 1;
        for (int i=1; i<=H*W; ++i) {
            powSp1[i] = powSp1[i-1]*(S+1)%mod;
        }
        
        F[0] = 1;
        invF[0] = 1;
        for (int i=1; i<5001; ++i) {
            F[i] = F[i-1]*i%mod;
            invF[i] = invF[i-1]*fastexp(i, mod-2)%mod;
        }
        
        memset(down_ways, 0, sizeof down_ways);
        memset(right_ways, 0, sizeof right_ways);
        down_ways[0][0] = right_ways[0][0] = 1;
        for (int i=1; i<2501; ++i) {
            for (int sum=0; sum<=S; ++sum) {
                for (int chosen=0; chosen<=sum; ++chosen) {
                    down_ways[i][sum] += down_ways[i-1][sum-chosen]*chosen; // right must be strictly less
                    right_ways[i][sum] += right_ways[i-1][sum-chosen]*(chosen + 1); // down can be LTE
                }
                down_ways[i][sum] %= mod;
                right_ways[i][sum] %= mod;
            }
        }
        
        int sol = 0;
        for (int j=0; j<W-1; ++j) {
            int ndown = H - 1;
            int nright = j;
            for (int sum=0; sum<=S; ++sum) {
                for (int dsum=0; dsum<=sum; ++dsum) {
                    int rsum = sum - dsum;
                    add(sol, down_ways[ndown][dsum]*right_ways[nright][rsum]%mod*line_ways[W-1-j][S-sum]%mod*powSp1[W*(H-1)+j+1-1-2*(ndown+nright)]%mod*C(ndown+nright-1, nright)%mod);
                }
            }
        }
        
        for (int i=0; i<H-1; ++i) {
            int ndown = i;
            int nright = W - 1;
            for (int sum=0; sum<=S; ++sum) {
                for (int dsum=0; dsum<=sum; ++dsum) {
                    int rsum = sum - dsum;
                    add(sol, down_ways[ndown][dsum]*right_ways[nright][rsum]%mod*line_ways[H-1-i][S-sum]%mod*powSp1[(W-1)*H+i+1-1-2*(ndown+nright)]%mod*C(ndown+nright-1, ndown)%mod);
                }
            }
        }
        
        return sol;
    }
};
