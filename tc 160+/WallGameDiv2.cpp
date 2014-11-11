//# walls, game, board, 2-player game, dp, maximum path
//# => It's easy to see that eel can force rabbit to take any simple path through the board. Therefore, the problem is asking for the maximum value such path. This can easily be found via memoized recursion, but as an exercise it's done here with an explicit topological sort of the state-space DAG.
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

int di[] = { 0, 0, 1 };
int dj[] = { -1, +1, 0 };
const int MAXN = 50+2;
int dp[MAXN][MAXN][3];
int indeg[MAXN][MAXN][3];
vector<string> C;

void go(int i, int j, int blocked_dir) {
    const int m = C.size();
    const int n = C[0].size();
    if (i == m-1) return;
    for (int d=0; d<3; ++d) {
        if (blocked_dir<2 && d==blocked_dir) continue;
        int r = i + di[d];
        int c = j + dj[d];
        if (r<0 || r>=m || c<0 || c>=n || C[r][c]=='x') continue;
        int bd = (d==2) ? 2 : 1-d;
        if (indeg[r][c][bd] == 0) {
            go(r, c, bd);
        }
        ++indeg[r][c][bd];
    }
}

struct state {
    int i, j, blocked_dir;
};
class WallGameDiv2 {
public:
    int play(vector <string> costs) {
        int m = costs.size();
        int n = costs[0].size();
        C = costs;
        memset(indeg, 0, sizeof indeg);
        go(0, 0, 2);
        queue<state> Q;
        Q.push({0, 0, 2});
        int sol = 0;
        memset(dp, 0, sizeof dp);
        while (!Q.empty()) {
            state s = Q.front();
            Q.pop();
            if (s.i+1 == m) {
                sol = max(sol, dp[s.i][s.j][s.blocked_dir]);
                continue;
            }
            for (int d=0; d<3; ++d) {
                if (s.blocked_dir<2 && d==s.blocked_dir) continue;
                int r = s.i + di[d];
                int c = s.j + dj[d];
                if (r<0 || r>=m || c<0 || c>=n || C[r][c]=='x') continue;
                int bd = (d==2) ? 2 : 1-d;
                dp[r][c][bd] = max(dp[r][c][bd], dp[s.i][s.j][s.blocked_dir] + (costs[r][c]-'0'));
                if (--indeg[r][c][bd] == 0) {
                    Q.push(state{r, c, bd});
                }
            }
        }
        return sol;
    }
};
