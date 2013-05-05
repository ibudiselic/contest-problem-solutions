#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 1000;
bool A[MAXN][MAXN];
int C[MAXN];
int m, n, x, y;
int dp[MAXN+1][2];
const int inf = 987654321;
int go(int row, bool need) {
    int &ret = dp[row][need];
    if (ret != -1) {
        return ret;
    }
    if (row == m) {
        return ret = 0;
    } else if (row+x > m) {
        ret = inf;
    } else {
        int val = 0;
        for (int i=0; i<x; ++i) {
            val += C[row+i];
        }
        if (need) {
            val = x*n - val;
        }
        ret = val + go(row+x, !need);
        for (int i=x; i<y && row+i<m; ++i) {
            if (need) {
                val += n - C[row+i];
            } else {
                val += C[row+i];
            }
            ret = min(ret, val + go(row+i+1, !need));
        }
    }

    return ret;
}
int main() {
    cin >> n >> m >> x >> y;
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<m; ++j) {
            A[j][i] = (s[j] == '#');
        }
    }
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j]) {
                ++C[i];
            }
        }
    }

    memset(dp, 0xff, sizeof dp);
    cout << min(go(0, 0), go(0, 1)) << '\n';
    return 0;
}
