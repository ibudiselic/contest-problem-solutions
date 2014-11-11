//# walls, game, board, 2-player game, dp
//# => See bottom up version (without _memo).
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
int dp_rabbit[MAXN][MAXN][MAXN][MAXN];
int dp_eel[MAXN][MAXN][MAXN][MAXN];
int m, n;

inline int cost(int i, int j) {
    return rowsum[i][j+1] - rowsum[i][j];
}
inline int sum(int i, int j1, int j2) { //[j1, j2)
    assert(j2 >= j1);
    return rowsum[i][j2] - rowsum[i][j1];
}

int rabbit(int, int, int, int);
int eel(int i, int j, int b1, int b2) {
    int &ret = dp_eel[i][j][b1][b2];
    if (ret != -1) {
        return ret;
    }
    assert(j==b1-1 || j==b2);
    if (i == m-1) {
        ret = 0;
    } else {
        ret = rabbit(i, j, b1, b2);
        if (b2-b1+1 < n) {
            ret = max(ret, rabbit(i, j, min(b1, j), max(b2, j+1)));
        }
    }
    return ret;
}
int rabbit(int i, int j, int b1, int b2) {
    int &ret = dp_rabbit[i][j][b1][b2];
    if (ret != -1) {
        return ret;
    }
    assert(i+1 < m);
    if (b1<=j && j<b2) { // blocked
        ret = INF;
        if (b1 > 0) {
            ret = min(ret, sum(i, b1-1, j) + eel(i, b1-1, b1, b2));
        }
        if (b2+1 <= n) {
            ret = min(ret, sum(i, j+1, b2+1) + eel(i, b2, b1, b2));
        }
    } else { // not blocked - go down
        ret = cost(i+1, j) + eel(i+1, j, j, j);
    }
    return ret;
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
        memset(dp_rabbit, 0xff, sizeof dp_rabbit);
        memset(dp_eel, 0xff, sizeof dp_eel);
        int sol = INF;
        for (int j=0; j<n; ++j) {
            sol = min(sol, cost(0, j) + eel(0, j, j, j));
        }
        return sol;
    }
};
