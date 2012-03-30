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

long long dp[2][101];
const long long mod = 1000000007;
void add(long long &a, long long b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class NoRepeatPlaylist {
public:
    int numPlaylists(int N, int M, int P) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i=0; i<P; ++i) {
            for (int used=0; used<=N; ++used) {
                if (dp[i&1][used] > 0) {
                    if (used < N) {
                        add(dp[(i+1)&1][used+1], dp[i&1][used]*(N-used)%mod);
                    }
                    if (used > M) {
                        assert(i > M);
                        add(dp[(i+1)&1][used], dp[i&1][used]*(used-M)%mod);
                    }
                    dp[i&1][used] = 0;
                }
            }
        }
        
        return dp[P&1][N];
    }
};
