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

int R[50][50];
int C[50][50];
int m, n;
void go_r(int i, int j, int val, vector<string> &G) {
    R[i][j] = val;
    if (j>0 && G[i][j-1]=='.' && R[i][j-1]==-1) {
        go_r(i, j-1, val, G);
    }
    if (j+1<n && G[i][j+1]=='.' && R[i][j+1]==-1) {
        go_r(i, j+1, val, G);
    }
}
void go_c(int i, int j, int val, vector<string> &G) {
    C[i][j] = val;
    if (i>0 && G[i-1][j]=='.' && C[i-1][j]==-1) {
        go_c(i-1, j, val, G);
    }
    if (i+1<m && G[i+1][j]=='.' && C[i+1][j]==-1) {
        go_c(i+1, j, val, G);
    }
}

vector< vector<int> > G;
int dp[2501][51][2][2];
const int inf = 12345678;
int go(int u, int parent, int child_idx, bool took_parent, bool must_child) {
    int &ret = dp[u][child_idx][took_parent][must_child];
    if (ret != -1) {
        return ret;
    }
    if (child_idx == (int)G[u].size()) {
        ret = (must_child ? inf : 0);
    } else if (G[u][child_idx] == parent) {
        ret = go(u, parent, child_idx + 1, took_parent, must_child);
    } else {
        ret = go(G[u][child_idx], u, 0, 0, !took_parent && !must_child) + go(u, parent, child_idx+1, took_parent, must_child); // don't take it and potentially try to skip the next level
        ret = min(ret, go(G[u][child_idx], u, 0, 0, 1) + go(u, parent, child_idx+1, took_parent, must_child)); // don't take it and take one on the next level
        ret = min(ret, 1 + go(G[u][child_idx], u, 0, 1, 0) + go(u, parent, child_idx+1, 1, 0)); // take it and try to skip the next level
        ret = min(ret, 1 + go(G[u][child_idx], u, 0, 1, 1) + go(u, parent, child_idx+1, 1, 0)); // take it and take one on the next level
    }
    return ret;
}
class FoxBomb {
public:
    int getMinimumCost(vector <string> grid) {
        m = grid.size();
        n = grid[0].size();
        int r = 0;
        int c = 0;
        memset(R, 0xff, sizeof R);
        memset(C, 0xff, sizeof C);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '#') {
                    continue;
                }
                if (R[i][j] == -1) {
                    go_r(i, j, r++, grid);
                }
                if (C[i][j] == -1) {
                    go_c(i, j, c++, grid);
                }
            }
        }
        
        G.assign(r+c, vector<int>());
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] != '#') {
                    int rr = R[i][j];
                    int cc = C[i][j] + r;
                    G[rr].push_back(cc);
                    G[cc].push_back(rr);
                }
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        return min(go(0, -1, 0, 0, 0), go(0, -1, 0, 0, 1));
    }
};
