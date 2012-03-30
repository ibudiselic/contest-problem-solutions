#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
int G[50][50];
bool done[50];
void dfs(int u) {
    done[u] = true;
    for (int v=0; v<n; ++v) {
        if (!done[v] && G[u][v]>0) {
            dfs(v);
        }
    }
}
bool cyc_vis[50];
bool cyc(int u, int start) {
    if (cyc_vis[u]) {
        return false;
    }
    cyc_vis[u] = true;
    if (u == start) {
        return true;
    }
    for (int v=0; v<n; ++v) {
        if (G[u][v]>0 && cyc(v, start)) {
            return true;
        }
    }
    return false;
}
int outdeg[50];
const int mod = 1000000007;
typedef vector< vector<long long> > matrix;

matrix I(int n) {
    matrix ret(n, vector<long long>(n, 0));
    for (int i=0; i<n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}
matrix mul(const matrix &A, const matrix &B) {
    int n = A.size();
    matrix ret = I(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            long long val = 0;
            for (int k=0; k<n; ++k) {
                val += (long long)A[i][k]*B[k][j]%mod;
            }
            ret[i][j] = int(val%mod);
        }
    }
    return ret;
}
matrix fastexp(matrix A, int n) {
    matrix ret = I(n);
    while (n > 0) {
        if (n & 1) {
            ret = mul(ret, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return ret;
}
class MonsterFarm {
public:
    int numMonsters(vector <string> transforms) {
        memset(G, 0, sizeof G);
        memset(outdeg, 0, sizeof outdeg);
        n = transforms.size();
        for (int i=0; i<n; ++i) {
            istringstream is(transforms[i]);
            int x;
            while (is >> x) {
                ++outdeg[i];
                ++G[i][x-1];
            }
        }
        
        memset(done, 0, sizeof done);
        dfs(0);
        for (int i=0; i<n; ++i) {
            if (outdeg[i]>1 && done[i]) {
                memset(cyc_vis, 0, sizeof cyc_vis);
                for (int j=0; j<n; ++j) {
                    if (G[i][j]>0 && cyc(j, i)) {
                        return -1;
                    }
                }
            }
        }
        
        matrix A(n, vector<long long>(n, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                A[i][j] = G[i][j];
            }
        }
        A = fastexp(A, n);
        long long sol = 0;
        for (int j=0; j<n; ++j) {
            sol += A[0][j];
        }
        return int(sol%mod);
    }
};
