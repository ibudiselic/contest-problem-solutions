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

const int mod = 1000000007;
int m;
void matmul(int (*A)[52], int (*B)[52], int (*C)[52]) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<m; ++j) {
            C[i][j] = 0;
            for (int k=0; k<m; ++k) {
                C[i][j] = int((C[i][j] + (long long)A[i][k]*B[k][j])%mod);
            }
        }
    }
}
int A[52][52], B[52][52], C[52][52], L[52][52], ret[52][52];
int val(char c) {
    if (c <= 'Z') {
        return c - 'A' + 26;
    } else {
        return c - 'a';
    }
}
void matexp(long long n) {
    memcpy(A, L, sizeof A);
    for (int i=0; i<m; ++i) {
        ret[i][i] = 1;
    }

    while (n > 0) {
        if (n&1) {
            memcpy(B, ret, sizeof B);
            matmul(B, A, ret);
        }
        memcpy(B, A, sizeof A);
        memcpy(C, A, sizeof A);
        matmul(B, C, A);
        n >>= 1;
    }
}
int main() {
    int k;
    long long n;
    scanf("%I64d %d %d", &n, &m, &k);
    for (int i=0; i<m; ++i) {
        for (int j=0; j<m; ++j) {
            L[i][j] = 1;
        }
    }

    for (int i=0; i<k; ++i) {
        char a, b;
        scanf("\n%c%c", &a, &b);
        int x = val(a);
        int y = val(b);
        L[y][x] = 0;
    }

    matexp(n-1);
    long long sol = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<m; ++j) {
            sol += ret[i][j];
        }
    }
    printf("%d\n", int(sol%mod));

    return 0;
}
