//# dp, medium dp, excavations, depth, digging, artefacts
//# => The key insight is that we need to choose one location for each kind in found. Once we do that, we can remember the deepest depth we need to dig to find them. Then any of the remaining locations can be chosen as long as their depth is strictly greater or if they are equal and the location also has one of the found kinds...
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

bool ls(int f1, int k1, int d1, int f2, int k2, int d2) {
    if (f1 != f2) return f1 > f2;
    if (k1 != k2) return k1 < k2;
    return d1 < d2;
}

long long C[55][55];
int deeper_cnt[55];
int nxt[55];
vector<int> depth;
int m, n, K;
int found_kinds;

long long dp[55][55][55];
long long go(int at, int rempick, int depthidx) {
    long long &ret = dp[at][rempick][depthidx];
    if (ret != -1) return ret;
    
    if (at == m) {
        ret = C[rempick + deeper_cnt[depthidx]][K-found_kinds];
    } else {
        ret = 0;
        if (nxt[at] > at+1) { // can skip
            ret += go(at+1, rempick, depthidx);
        }
        ret += go(nxt[at], rempick+nxt[at]-at-1, depth[at]>depth[depthidx] ? at : depthidx); // take
    }

    return ret;
}
class Excavations {
public:
    long long count(vector <int> kind, vector <int> depth, vector <int> found_, int K) {
        ::K = K;
        vector<int> found(55);
        for (int k : found_) found[k] = 1;

        n = kind.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (ls(found[kind[j]], kind[j], depth[j], found[kind[i]], kind[i], depth[i])) {
                    swap(kind[i], kind[j]);
                    swap(depth[i], depth[j]);
                }
            }
        }

        C[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }

        m = 0;
        while (m<n && found[kind[m]]) {
            ++m;
        }

        for (int i=0; i<m; ++i) {
            deeper_cnt[i] = 0;
            for (int j=m; j<n; ++j) {
                if (depth[j] > depth[i]) {
                    ++deeper_cnt[i];
                }
            }
        }
        deeper_cnt[n] = n-m;
        kind.push_back(-1);
        kind[m] = -1;
        depth.push_back(-1);
        depth[m] = -1;

        found_kinds = found_.size();

        int nxt_at = m;
        for (int i=m-1; i>=0; --i) {
            if (kind[i] != kind[i+1]) nxt_at = i+1;
            nxt[i] = nxt_at;
        }

        memset(dp, 0xff, sizeof dp);
        ::depth = depth;
        return go(0, 0, n);
    }
};
