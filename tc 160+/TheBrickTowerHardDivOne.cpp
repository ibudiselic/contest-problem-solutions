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

int C, K;
int nstates;
int pattern[4], recoded[4];
int P[101][5]; // c0, c1, c2, c3, match
int revP[4][4][4][4][8];
void gen(int at) {
    if (at < 4) {
        int choices = 0;
        for (int i=0; i<at; ++i) {
            choices = max(choices, pattern[i]+1);
        }
        choices = min(choices, C-1);
        for (int c=0; c<=choices; ++c) {
            pattern[at] = c;
            gen(at+1);
        }
    } else {
        int match = 0;
        if (pattern[0] == pattern[1]) ++match;
        if (pattern[0] == pattern[2]) ++match;
        if (pattern[1] == pattern[3]) ++match;
        if (pattern[2] == pattern[3]) ++match;
        for (int i=match; i<=K; ++i) {
            for (int j=0; j<4; ++j) {
                P[nstates][j] = pattern[j];
            }
            P[nstates][4] = i;
            revP[pattern[0]][pattern[1]][pattern[2]][pattern[3]][i] = nstates;
            ++nstates;
        }
    }
}

const int mod = 1234567891;
inline int modmul(long long a, long long b) {
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
    return int(a);
}
inline void modadd(int &a, int b) {
    long long tmp = (long long)a + b;
    if (tmp >= mod) {
        tmp -= mod;
    }
    a = int(tmp);
}
void matmul(int (*A)[102], int (*B)[102], int (*C)[102], int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            long long tmp = 0;
            for (int k=0; k<n; ++k) {
                tmp += modmul(A[i][k], B[k][j]);
            }
            C[i][j] = modmul(tmp, 1);
        }
    }
}
int A[102][102], ret[102][102], B[102][102];
void transitions(int at, int base, int match, int ways) {
    if (match > K) {
        return;
    }
    if (at < 4) {
        int choices = 0;
        for (int i=0; i<at; ++i) {
            choices = max(choices, pattern[i]+1);
        }
        for (int i=0; i<4; ++i) {
            choices = max(choices, P[base][i]+1);
        }
        choices = min(choices, C-1);
        for (int c=0; c<=choices; ++c) {
            pattern[at] = c;
            int nmatch = match + (c==P[base][at]);
            if (at==1 && pattern[0]==c) ++nmatch;
            if (at==2 && pattern[0]==c) ++nmatch;
            if (at==3) nmatch += int(pattern[1]==c) + int(pattern[2]==c);
            transitions(at+1, base, nmatch, c<choices ? ways : modmul(ways, C-choices));
        }
    } else {
        bool done[4] = {0};
        for (int iter=0; iter<4; ++iter) {
            int val = -1;
            for (int i=0; i<4; ++i) {
                if (!done[i]) {
                    val = pattern[i];
                    break;
                }
            }
            for (int i=0; i<4; ++i) {
                if (pattern[i] == val) {
                    recoded[i] = iter;
                    done[i] = true;
                }
            }
        }

        int next = revP[recoded[0]][recoded[1]][recoded[2]][recoded[3]][match];
        assert(next < nstates);
        modadd(A[base][next], ways);
    }
}
class TheBrickTowerHardDivOne {
public:
    int find(int C, int K, long long H) {
        ::C = C;
        ::K = K;
        nstates = 1;
        for (int i=0; i<4; ++i) {
            P[0][i] = -1;
        }
        P[0][4] = 0;
        memset(revP, 0x3f, sizeof revP);
        gen(0);
        memset(A, 0, sizeof A);
        for (int base=0; base<nstates; ++base) {
            transitions(0, base, P[base][4], 1);
        }

        int n = nstates + 1;
        for (int i=0; i<n; ++i) {
            A[i][n-1] = 1;
        }
        memset(ret, 0, sizeof ret);
        for (int i=0; i<n; ++i) {
            ret[i][i] = 1;
        }
        ++H;
        while (H > 0) {
            if (H&1) {
                memcpy(B, ret, sizeof B);
                matmul(B, A, ret, n);
            }
            memcpy(B, A, sizeof B);
            matmul(B, B, A, n);
            H /= 2;
        }
        int sol = ret[0][n-1];
        modadd(sol, mod-1); // 0-height tower
        return sol;
    }
};
