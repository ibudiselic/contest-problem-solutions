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
#include <cmath>

using namespace std;

int sz[55][55];
long long fmask[55][55];
long long base_mask[55];
vector< vector<int> > G;
double nchoose[55];
int compsz(int u, int p) {
    int &ret = sz[u][p];
    if (ret != -1) {
        return ret;
    }
    ret = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != p) {
            ret += compsz(v, u);
        }
    }
    return ret;
}
long long compfmask(int u, int p) {
    long long &ret = fmask[u][p];
    if (ret != -1) {
        return ret;
    }
    ret = base_mask[u];
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != p) {
            ret |= compfmask(v, u);
        }
    }
    return ret;
}
inline double side(int u, int v, int f) {
    return (compfmask(u, v) & (1ll<<f)) ? 1 : 0;
}
class FoxAndTouristFamilies {
public:
    double expectedLength(vector <int> A, vector <int> B, vector <int> f) {
        int n = A.size() + 1;
        G.assign(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            G[A[i]].push_back(B[i]);
            G[B[i]].push_back(A[i]);
        }

        nchoose[0] = 1.0;
        for (int i=1; i<=n; ++i) {
            nchoose[i] = nchoose[i-1]*(n-i+1)/(i-1);
        }

        memset(sz, 0xff, sizeof sz);
        memset(fmask, 0xff, sizeof fmask);
        memset(base_mask, 0, sizeof base_mask);
        int m = f.size();
        for (int i=0; i<m; ++i) {
            base_mask[f[i]] |= 1ll<<i;
        }

        double sol = 0.0;
        for (int i=0; i<n-1; ++i) {
            int u = A[i];
            int v = B[i];
            double p = 1.0;
            for (int j=0; j<m; ++j) {
                p *= side(u, v, j)*compsz(v, u)/(n-1) + side(v, u, j)*compsz(u, v)/(n-1);
            }
            sol += p;
        }
        return sol;
    }
};
