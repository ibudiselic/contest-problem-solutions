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
int A[MAXN][MAXN];
int R[MAXN], C[MAXN];
int main() {
    int m, n, q;
    scanf("%d %d %d", &m, &n, &q);
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i=0; i<m; ++i) {
        R[i] = i;
    }
    for (int j=0; j<n; ++j) {
        C[j] = j;
    }

    for (int i=0; i<q; ++i) {
        char type;
        int x, y;
        scanf("\n%c %d %d", &type, &x, &y);
        --x; --y;
        if (type == 'c') {
            swap(C[x], C[y]);
        } else if (type == 'r') {
            swap(R[x], R[y]);
        } else {
            printf("%d\n", A[R[x]][C[y]]);
        }
    }

    return 0;
}
