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

const int mod = 1000000007;
int dp[2][51][2];
bool LW[50][50], LB[50][50], RW[50][50], RB[50][50];
void add(int &a, int b) {
    if ((a+=b) >= mod) a -= mod;
}
class TwoConvexShapes {
public:
    int countWays(vector <string> grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(LW, 0, sizeof LW);
        memset(LB, 0, sizeof LB);
        memset(RW, 0, sizeof RW);
        memset(RB, 0, sizeof RB);
        for (int i=0; i<m; ++i) {
            LW[i][0] = (grid[i][0]!='B');
            LB[i][0] = (grid[i][0]!='W');
            for (int j=1; j<n; ++j) {
                LW[i][j] = LW[i][j-1] && (grid[i][j]!='B');
                LB[i][j] = LB[i][j-1] && (grid[i][j]!='W');
            }

            RW[i][n-1] = (grid[i][n-1]!='B');
            RB[i][n-1] = (grid[i][n-1]!='W');
            for (int j=n-2; j>=0; --j) {
                RW[i][j] = RW[i][j+1] && (grid[i][j]!='B');
                RB[i][j] = RB[i][j+1] && (grid[i][j]!='W');
            }
        }

        int sol = 0;
        for (int iter=0; iter<2; ++iter) {
            memset(dp, 0, sizeof dp);
            dp[1][0][0] = 1;
            for (int i=0; i<m; ++i) {
                int cur = i&1;
                int prev = 1 - cur;
                for (int B=0; B<=n; ++B) {
                    for (int mixed=0; mixed<2; ++mixed) {
                        if (dp[prev][B][mixed] > 0) {
                            for (int nB=B; nB<=n; ++nB) {
                                if ((nB==0 && RW[i][0]) || (LB[i][nB-1] && (nB==n || RW[i][nB]))) {
                                    add(dp[cur][nB][mixed || (nB!=0 && nB!=n)], dp[prev][B][mixed]);
                                }
                            }
                            dp[prev][B][mixed] = 0;
                        }
                    }
                }
            }

            for (int i=0; i<=n; ++i) {
                for (int mixed=iter; mixed<2; ++mixed) {
                    add(sol, dp[(m+1)&1][i][mixed]);
                }
            }

            memset(dp, 0, sizeof dp);
            dp[1][n][0] = 1;
            for (int i=0; i<m; ++i) {
                int cur = i&1;
                int prev = 1 - cur;
                for (int B=0; B<=n; ++B) {
                    for (int mixed=0; mixed<2; ++mixed) {
                        if (dp[prev][B][mixed] > 0) {
                            for (int nB=B; nB>=0; --nB) {
                                if ((nB==0 && RW[i][0]) || (LB[i][nB-1] && (nB==n || RW[i][nB]))) {
                                    add(dp[cur][nB][mixed || (nB!=0 && nB!=n)], dp[prev][B][mixed]);
                                }
                            }
                            dp[prev][B][mixed] = 0;
                        }
                    }
                }
            }
            for (int i=0; i<=n; ++i) {
                for (int mixed=iter; mixed<2; ++mixed) {
                    add(sol, dp[(m+1)&1][i][mixed]);
                }
            }

            for (int B=0; B<=n; ++B) {
                bool ok = true;
                for (int i=0; i<m; ++i) {
                    if (!((B==0 && RW[i][0]) || (LB[i][B-1] && (B==n || RW[i][B])))) {
                        ok = false;
                        break;
                    }
                }
                if (ok && (iter==0 || (B!=0 && B!=n))) {
                    add(sol, mod-1);
                }
            }

            memcpy(LB, LW, sizeof LB);
            memcpy(RW, RB, sizeof RW);
        }

        return sol;
    }
};
