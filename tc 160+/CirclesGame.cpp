#include <algorithm>
#include <cassert>
#include <cctype>
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

long long dist2(long long x1, long long y1, long long x2, long long y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

vector<int> x, y, r;
bool inside(int i, int j) {
    return r[i]<r[j] && dist2(x[i], y[i], x[j], y[j])<(long long)(r[i]+r[j])*(r[i]+r[j]);
}

bool in[51][51];
bool vis[51];
vector< vector<int> > G;

void uniq(vector<int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}
int grundy(int);
void go(int u, int base, vector<int> &res) {
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        base ^= grundy(v);
    }
    res.push_back(base);
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        go(v, base^grundy(v), res);
    }
}
int dp[51];
int grundy(int u) {
    int &ret = dp[u];
    if (ret != -1) {
        return ret;
    }

    vector<int> under;
    int base = 0;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        base ^= grundy(v);
    }
    if (u+1 != (int)G.size()) { // can't just take dummy
        under.push_back(base);
    }

    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        go(v, base^grundy(v), under);
    }

    uniq(under);
    int val = 0;
    for (int i=0; i<(int)under.size(); ++i, ++val) {
        if (under[i] != val) {
            break;
        }
    }
    ret = val;
    return ret;
}
class CirclesGame {
public:
    string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
        ::x = x;
        ::y = y;
        ::r = r;
        memset(in, 0, sizeof in);
        int n = x.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i!=j && inside(i, j)) {
                    in[i][j] = 1;
                }
            }
            in[i][n] = 1;
        }

        G.assign(n+1, vector<int>());
        memset(vis, 0, sizeof vis);
        queue<int> Q;
        Q.push(n);
        vis[n] = 1;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<n; ++i) {
                if (vis[i] || !in[i][u]) continue;
                bool direct = true;
                for (int j=0; j<n; ++j) {
                    if (in[i][j] && in[j][u]) {
                        direct = false;
                        break;
                    }
                }
                if (direct) {
                    G[u].push_back(i);
                    vis[i] = 1;
                    Q.push(i);
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        return grundy(n)==0 ? "Bob" : "Alice";
    }
};
