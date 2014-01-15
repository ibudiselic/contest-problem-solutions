//# matrix exponentiation, dp
//# => notice that doing n+1 steps is the same as doing 1 step etc. so compute number of ways to move by some amount using the first n steps, then use matrix exp. to raise that to days/n and then do the final days%n steps... instead of doing real matrix exp (too slow), notice that the rows of the matrices are the same but rotated one step so you only need the first row and A[i][j] = A[0][(j-i) mod n]
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

const int mod = 1000000007;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
int n;
const int MAXN = 350;
void matmul(int *A, int *B, int *C) {
    for (int j=0; j<n; ++j) {
        C[j] = 0;
        for (int k=0; k<n; ++k) {
            C[j] = modadd(C[j], modmul(A[k], B[((j-k)%n+n)%n]));
        }
    }
}
int ways[MAXN+1][MAXN+1];
int A[MAXN];
int ret[MAXN];
int tmp[MAXN];
int tmp2[MAXN];
void fastexp(int *mat, long long k) {
    memset(ret, 0, sizeof ret);
    ret[0] = 1;
    bool inmat = true;
    while (k > 0) {
        if (k&1) {
            memcpy(tmp, ret, sizeof ret);
            if (inmat) {
                matmul(tmp, mat, ret);
            } else {
                matmul(tmp, tmp2, ret);
            }
        }
        k /= 2;
        if (inmat) {
            memcpy(tmp, mat, sizeof tmp);
            matmul(tmp, mat, tmp2);
        } else {
            memcpy(tmp, tmp2, sizeof tmp);
            matmul(tmp, tmp2, mat);
        }
        inmat = !inmat;
    }
}
class PenguinEmperor {
public:
    int countJourneys(int n, long long days) {
        ::n = n;
        memset(ways, 0, sizeof ways);
        ways[0][0] = 1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (ways[i][j] > 0) {
                    int old = -1;
                    for (int sgn=-1; sgn<=1; sgn+=2) {
                        int next = ((j+sgn*(i+1))%n+n)%n;
                        if (next != old) {
                            old = next;
                            ways[i+1][next] = modadd(ways[i+1][next], ways[i][j]);
                        }
                    }
                }
            }
        }
        /*
        for (int i=0; i<=n; ++i) {
            for (int j=0; j<n; ++j) {
                cerr << ways[i][j] << ' ';
            }
            cerr << '\n';
        }
        cerr << '\n';
        */
        for (int j=0; j<n; ++j) {
           A[j] = ways[n][j];
        }
        /*
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cerr << A[i][j] << ' ';
            }
            cerr << '\n';
        }
        */
        fastexp(A, days/n);

        int remdays = int(days%n);
        int sol = 0;
        for (int inter=0; inter<n; ++inter) {
            int steps = (n-inter)%n;
            sol = modadd(sol, modmul(ret[inter], ways[remdays][steps]));
        }

        return sol;
    }
};
