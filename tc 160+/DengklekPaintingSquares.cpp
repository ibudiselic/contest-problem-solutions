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

const int mod = 1000000007;
int dp[2][1<<8][1<<8];
int minset[1<<8][1<<8];
int notset[1<<8][1<<8];
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class DengklekPaintingSquares {
public:
    int numSolutions(int M, int N) { // swapped M and N
        for (int prev=0; prev<(1<<N); ++prev) {
            for (int cur=0; cur<(1<<N); ++cur) {
                int mask = 0;
                int notmask = 0;
                for (int i=0; i<N; ++i) {
                    if (cur & (1<<i)) {
                        int bit = (prev>>i)&1;
                        if (i > 0) bit ^= (cur>>(i-1))&1;
                        if (i+1 < N) bit ^= (cur>>(i+1))&1;
                        if (bit) {
                            mask |= (1<<i);
                        } else {
                            notmask |= (1<<i);
                        }
                    }
                }
                minset[prev][cur] = mask;
                notset[prev][cur] = notmask;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int row0=0; row0<(1<<N); ++row0) {
            dp[0][0][row0] = 1;
        }
        for (int i=1; i<M; ++i) {
            int cur = i&1;
            int prev = 1 - cur;
            for (int m0=0; m0<(1<<N); ++m0) {
                for (int m1=0; m1<(1<<N); ++m1) {
                    if (dp[prev][m0][m1] > 0) {
                        int base = minset[m0][m1];
                        int notbase = notset[m0][m1];
                        for (int mask=base; mask<(1<<N); mask=((mask+notbase+1)|base|notbase)^notbase) {
                            add(dp[cur][m1][mask], dp[prev][m0][m1]);
                        }
                        dp[prev][m0][m1] = 0;
                    }
                }
            }
        }
        
        int sol = 0;
        for (int m0=0; m0<(1<<N); ++m0) {
            for (int m1=0; m1<(1<<N); ++m1) {
                if (minset[m0][m1] == 0) {
                    add(sol, dp[(M+1)&1][m0][m1]);
                }
            }
        }
        
        return sol;
    }
};
