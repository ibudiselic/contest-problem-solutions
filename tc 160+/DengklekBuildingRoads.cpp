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
int dp[2][31][9][1<<9];
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class DengklekBuildingRoads {
public:
    int numWays(int N, int M, int K) {
        memset(dp, 0, sizeof dp);
        dp[0][M][0][0] = 1;
        for (int i=0; i<N; ++i) {
            const int cur = i&1;
            const int next = 1 - cur;
            const int offsetmax = min(K, i) - 1;
            for (int rem=M; rem>=0; --rem) {
                for (int offset=0; offset<=offsetmax; ++offset) {
                    for (int mask=0; mask<(1<<(K+1)); ++mask) {
                        if (dp[cur][rem][offset][mask] > 0) {
                            const int even_mask = mask;
                            const int odd_mask = mask ^ (1<<K) ^ (1<<(K-1-offset));
                            const int val = dp[cur][rem][offset][mask];
                            dp[cur][rem][offset][mask] = 0;
                            for (int take=0; take<=rem; ++take) {
                                add(dp[cur][rem-take][offset+1][(take&1) ? odd_mask : even_mask], val);
                            }
                        }
                    }
                }
                for (int mask=0; mask<(1<<(K+1)); mask+=2) {
                    dp[next][rem][0][mask>>1] = dp[cur][rem][offsetmax+1][mask];
                    dp[cur][rem][offsetmax+1][mask] = 0;
                }
            }
        }
        return dp[N&1][0][0][0];
    }
};
