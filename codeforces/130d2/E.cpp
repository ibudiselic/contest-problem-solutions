#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define MAXN 100000

int n;
int P[MAXN][17]; // [i][k] is the 2^k-ancestor of i or -1 if none
int node_level[MAXN]; // level of node starting at 0 for the roots
vector<int> children[MAXN];
vector<int> nodes_on_level[MAXN];
bool done[MAXN];
int maxdesc[MAXN];
int toDfs[MAXN];
int fromDfs[MAXN];
int dfsnum;

struct context {
    int u, level, cind;
    context(int u_, int level_, int cind_): u(u_), level(level_), cind(cind_) {}
};
void dfs(int u, int level) {
    int cind;
    stack<context> S;
    S.push(context(u, level, -1));
    while (S.size() > 0) {
        const context ctx = S.top();
        S.pop();
        u = ctx.u; level = ctx.level; cind = ctx.cind;
        
        if (cind == -1) {
            done[u] = true;
            toDfs[u] = dfsnum;
            node_level[u] = level;
            fromDfs[dfsnum] = u;
            nodes_on_level[level].push_back(dfsnum);
            ++dfsnum;
            S.push(context(u, level, 0));
        } else if (cind == (int)children[u].size()) {
            maxdesc[u] = dfsnum;
        } else {
            S.push(context(u, level, cind+1));
            int v = children[u][cind];
            if (!done[v]) {
                S.push(context(v, level+1, -1));
            }
        }
    }
}

int get_k_parent(int u, int k) {
    int offset = 0;
    while (u!=-1 && (1<<offset)<=k) {
        if (k & (1<<offset)) {
            u = P[u][offset];
        }
        ++offset;
    }
    return u;
}
int getsol(int u, int level) {
    if (u == -1) {
        return 0;
    }
    
    int a = lower_bound(nodes_on_level[level].begin(), nodes_on_level[level].end(), toDfs[u]) - nodes_on_level[level].begin();
    int b = lower_bound(nodes_on_level[level].begin(), nodes_on_level[level].end(), maxdesc[u]) - nodes_on_level[level].begin();
    return b-a-1;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int p;
        scanf("%d", &p);
        P[i][0] = p - 1;
        if (p != 0) {
            children[p-1].push_back(i);
        }
    }
    
    for (int i=1; i<17; ++i) {
        for (int u=0; u<n; ++u) {
            if (P[u][i-1] == -1) {
                P[u][i] = -1;
            } else {
                P[u][i] = P[P[u][i-1]][i-1];
            }
        }
    }
    
    dfsnum = 0;
    for (int i=0; i<n; ++i) {
        if (!done[i]) {
            dfs(i, 0);
        }
    }
    int m;
    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        if (i) putchar(' ');
        int u, k;
        scanf("%d %d", &u, &k);
        --u;
        int p = get_k_parent(u, k);
        printf("%d", getsol(p, node_level[u]));
    }
    putchar('\n');
    
    return 0;
}
