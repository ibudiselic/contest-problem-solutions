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

const int mod = 555555555;
const int MAXN = 2500;
int BC[MAXN+1][MAXN+1];
inline void modadd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
inline int modmul(long long a, long long b) {
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
    return int(a);
}

class XorBoard {
public:
    int count(int R, int C, int Rcount, int Ccount, int S) {
        BC[0][0] = 1;
        for (int n=0; n<=MAXN; ++n) {
            BC[n][0] = 1;
            for (int k=1; k<=n; ++k) {
                BC[n][k] = BC[n-1][k-1];
                modadd(BC[n][k], BC[n-1][k]);
            }
        }

        int sol = 0;
        for (int rodd=(Rcount&1); rodd<=min(R,Rcount); rodd+=2) {
            int f = modmul(BC[R][rodd], BC[(Rcount-rodd)/2+R-1][R-1]);
            for (int codd=(Ccount&1); codd<=min(C,Ccount); codd+=2) {
                if ((long long)rodd*(C-codd) + (long long)(R-rodd)*codd == S) {
                    modadd(sol, modmul(f, modmul(BC[C][codd], BC[(Ccount-codd)/2+C-1][C-1])));
                }
            }
        }
        return sol;
    }
};
