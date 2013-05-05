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

struct edge_t {
    int a, b;
    edge_t(int a_, int b_): a(a_), b(b_) {}
    int other(int u) const { return u==a ? b : a; }
};
vector< vector<edge_t> > adj;
const int MAXN = 200000;
int F[MAXN], B[MAXN];
int go(int u, int p, int fwd=0, int bck=0) {
    F[u] = fwd;
    B[u] = bck;
    int ret = 0;
    for (int i=0; i<(int)adj[u].size(); ++i) {
        const edge_t &e = adj[u][i];
        if (e.other(u) == p) continue;
        if (e.a == u) {
            ret += go(e.b, u, fwd+1, bck);
        } else {
            ret += 1 + go(e.a, u, fwd, bck+1);
        }
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    adj.resize(n, vector<edge_t>());
    for (int i=1; i<n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        edge_t e(a, b);
        adj[a].push_back(e);
        adj[b].push_back(e);
    }

    int total_back = go(0, -1);

    int best = n;
    vector<int> cands;
    for (int i=0; i<n; ++i) {
        int need = total_back + F[i] - B[i];
        if (need < best) {
            best = need;
            cands.assign(1, i);
        } else if (need == best) {
            cands.push_back(i);
        }
    }

    printf("%d\n", best);
    for (int i=0; i<(int)cands.size(); ++i) {
        if (i) putchar(' ');
        printf("%d", cands[i] + 1);
    }
    putchar('\n');
    return 0;
}
