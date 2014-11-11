//# walls, game, board, 2-player game
//# => The key idea to notice is that eel should never place a wall before rabbit is in the cell above it - it is just giving away information that way. Furthermore, if eel doesn't place a wall below rabbit on some turn, it is optimal for the rabbit to go down (otherwise, eel can block all of his remaining moves on that row and ultimately force him to move down in that same position with a worse score). If eel blocks rabbit's current position, he can move either left or right to the first non-blocked cell. This implies that that blocked portion of any row is a continuous interval which makes it possible to solve the problem with dynamic programming.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 50+1;
const int INF = 1234567890;
int rowsum[MAXN][MAXN];
int rabbit[2][MAXN][2][MAXN];
int eel[2][MAXN][2][MAXN];
int m, n;

inline int cost(int i, int j) {
    return rowsum[i][j+1] - rowsum[i][j];
}
inline int sum(int i, int j1, int j2) { //[j1, j2)
    assert(j2 >= j1);
    return rowsum[i][j2] - rowsum[i][j1];
}

class WallGameDiv1 {
public:
    int play(vector <string> costs) {
        m = costs.size();
        n = costs[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                rowsum[i][j+1] = rowsum[i][j] + (costs[i][j]-'0');
            }
        }

        for (int j=0; j<n; ++j) {
            eel[(m+1)&1][j][0][j] = 0;
        }
        for (int i=m-2; i>=0; --i) {
            int cur = i&1;
            int next = 1-cur;
            for (int len=n-1; len>=0; --len) {
                for (int b1=0; b1<n && b1+len<=n; ++b1) {
                    int b2 = b1+len;
                    if (b1 > 0) {
                        rabbit[cur][b1-1][len&1][b1] = cost(i+1, b1-1) + eel[next][b1-1][0][b1-1];
                    }
                    if (b2 < n) {
                        rabbit[cur][b2][len&1][b1] = cost(i+1, b2) + eel[next][b2][0][b2];
                    }
                    for (int j=b1-1; j<=b2; j+=len+1) { // j in [b1-1, b2]
                        if (j<0 || j==n) continue;
                        assert(j==b1-1 || j==b2);
                        eel[cur][j][len&1][b1] = rabbit[cur][j][len&1][b1];
                    }

                    for (int j=b1-1; j<=b2; j+=len+1) { // j in [b1-1, b2]
                        if (j<0 || j==n) continue;
                        assert(j==b1-1 || j==b2);
                        if (len < n-1) {
                            eel[cur][j][len&1][b1] = max(eel[cur][j][len&1][b1], rabbit[cur][j][(len+1)&1][min(b1, j)]);
                        }
                    }

                    for (int j=b1; j<b2; j+=max(1, len-1)) { // j in [b1, b2-1]
                        assert(j==b1 || j==b2-1);
                        rabbit[cur][j][len&1][b1] = INF;
                    }
                    if (b1 > 0) {
                        for (int j=b1; j<b2; j+=max(1, len-1)) { // j in [b1, b2-1]
                            assert(j==b1 || j==b2-1);
                            rabbit[cur][j][len&1][b1] = min(rabbit[cur][j][len&1][b1], sum(i, b1-1, j) + eel[cur][b1-1][len&1][b1]);
                        }
                    }
                    if (b2 < n) {
                        for (int j=b1; j<b2; j+=max(1, len-1)) { // j in [b1, b2-1]
                            assert(j==b1 || j==b2-1);
                            rabbit[cur][j][len&1][b1] = min(rabbit[cur][j][len&1][b1], sum(i, j+1, b2+1) + eel[cur][b2][len&1][b1]);
                        }
                    }
                }
            }
        }
        int sol = INF;
        for (int j=0; j<n; ++j) {
            sol = min(sol, cost(0, j) + eel[0][j][0][j]);
        }
        return sol;
    }
};
