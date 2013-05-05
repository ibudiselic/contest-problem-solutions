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

bool G[100][100];
bool done[100];
bool cyc;
int n, m;

int dfs(int u, int p) {
    done[u] = true;
    int ret = 1;
    for (int v=0; v<n; ++v) {
        if (v == p) {
            continue;
        }
        if (G[u][v]) {
            if (done[v]) {
                cyc = true;
            } else {
                ret += dfs(v, u);
            }
        }
    }

    return ret;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        G[a][b] = G[b][a] = 1;
    }

    int A=0, B=0;
    for (int i=0; i<n; ++i) {
        if (!done[i]) {
            cyc = false;
            int k = dfs(i, -1);
            if (cyc) {
                A += k/2;
                B += k/2;
            } else {
                A += k/2;
                B += (k+1)/2;
                if (A < B) {
                    swap(A, B);
                }
            }
        }
    }

    printf("%d\n", n - (A+B - (A!=B)));
    return 0;
}
