#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const long long mod = 1000000007;
void mul(long long (*A)[4], long long (*B)[4], long long (*C)[4]) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            C[i][j] = 0;
            for (int k=0; k<4; ++k) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%mod;
            }
        }
    }
}
long long A[4][4], B[4][4], C[4][4], D[4][4], tmp[4][4];
inline long long modval(long long x) {
    return (x%mod+mod)%mod;
}
void fastexp(long long n) {
    memset(B, 0, sizeof B);
    for (int i=0; i<4; ++i) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            memcpy(tmp, B, sizeof tmp);
            mul(tmp, A, B);
        }
        n /= 2;
        memcpy(tmp, A, sizeof tmp);
        mul(tmp, tmp, A);
    }
    memcpy(A, B, sizeof A);
}
class SplittingFoxes {
public:
    int sum(long long n, long long S, long long L, long long R) {
        A[0][0] = modval(S-L-R); A[0][1] = 0; A[0][2] = S; A[0][3] = 0;
        A[1][0] = 0; A[1][1] = S; A[1][2] = modval(R-L); A[1][3] = S;
        A[2][0] = 0; A[2][1] = modval(L-R); A[2][2] = S; A[2][3] = 0;
        A[3][0] = 0; A[3][1] = 0; A[3][2] = 0; A[3][3] = modval(S+L+R);

        fastexp(n);
        return int(A[0][3]);
    }
};
