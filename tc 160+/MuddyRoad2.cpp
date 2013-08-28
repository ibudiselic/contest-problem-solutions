#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int mod = 555555555;
inline void modadd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
const int MAXN = 555;
int ways[MAXN+1][MAXN+1][2];
int C[MAXN+1][MAXN+1];
class MuddyRoad2 {
public:
    int theCount(int N, int K) {
        C[0][0] = 1;
        for (int n=1; n<=MAXN; ++n) {
            C[n][0] = 1;
            for (int k=1; k<=n; ++k) {
                C[n][k] = C[n-1][k-1];
                modadd(C[n][k], C[n-1][k]);
            }
        }
        memset(ways, 0, sizeof ways);
        ways[1][1][0] = 1;
        ways[2][2][0] = 1;
        ways[2][1][1] = 1;
        for (int i=3; i<=N; ++i) {
            for (int j=1; j<=K+1; ++j) {
                modadd(ways[i][j][0], ways[i-1][j-1][0]);
                modadd(ways[i][j][0], ways[i-2][j-1][1]);
                modadd(ways[i][j][0], ways[i-3][j][0]);

                modadd(ways[i][j][1], ways[i-2][j-1][0]);
                modadd(ways[i][j][1], ways[i-1][j-1][1]);
                modadd(ways[i][j][1], ways[i-3][j][1]);
            }
        }

        int sol = C[N-2][K];
        modadd(sol, mod - ways[N-K][K+1][0]);
        modadd(sol, mod - ways[N-K][K+1][1]);
        return sol;
    }
};
