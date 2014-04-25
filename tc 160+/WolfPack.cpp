//# wolves, grid, coordinate systems, transformation, important
//# => Notice that if we transfer the problem into the x
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
const int MAXM = 100000+5;
int F[MAXM];
int invF[MAXM];
int modinv[MAXM];
int choose(int n, int k) {
    if (k > n) return 0;
    int ret = modmul(F[n], invF[n-k]);
    return modmul(ret, invF[k]);
}
int solve(vector<int> &v, int m) {
    sort(v.begin(), v.end());
    int ret = 0;
    int diff = 1;
    for (int pos=v.back()-m; pos<=v[0]+m; pos+=diff) {
        int add = 1;
        for (int i=0; i<(int)v.size(); ++i) {
            int d = abs(pos-v[i]);
            assert(d <= m);
            if ((m-d)&1) {
                add = 0;
                break;
            } else {
                diff = 2; // parity (the ones in between will not work)
                add = modmul(add, choose(m, (m-d)/2));
            }
        }
        ret = modadd(ret, add);
    }
    return ret;
}
class WolfPack {
public:
    int calc(vector <int> x, vector <int> y, int m) {
        modinv[1] = 1;
        for (int i=2; i<=m; ++i) {
            int j = mod%i;
            assert(j > 0);
            modinv[i] = modmul(mod-mod/i, modinv[j]);
        }
        F[0] = invF[0] = 1;
        for (int i=1; i<=m; ++i) {
            F[i] = modmul(F[i-1], i);
            invF[i] = modmul(invF[i-1], modinv[i]);
        }

        int n = x.size();
        vector<int> v(n);
        for (int i=0; i<n; ++i) {
            v[i] = x[i]+y[i];
        }
        int sol = solve(v, m);
        for (int i=0; i<n; ++i) {
            v[i] = x[i]-y[i];
        }
        return modmul(sol, solve(v, m));
    }
};
