//# integers, division, choose
//# => a better approach than the one implemented is to notice that the exponents of different primes can be decreased independently when choosing the numbers in the sequence...
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

const int mod = 1000000009;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
const int MAXFAC = 35;
int C[MAXFAC+1][MAXFAC+1];
typedef pair<int, vector<int> > p_t;
map<p_t, int> dp;
int go(int neednums, int rem, vector<int> &fcnts);
int pick(int neednums, int rem, int at, bool any, vector<int> &fcnts) {
    if (at == (int)fcnts.size()) {
        return any ? go(neednums-1, rem, fcnts) : 0;
    }
    int ret = 0;
    int old = fcnts[at];
    for (int v=0; v<=old; ++v) {
        fcnts[at] = v;
        ret = modadd(ret, pick(neednums, rem-(old-v), at+1, any||(v<old), fcnts));
    }
    fcnts[at] = old;
    return ret;
}
int go(int neednums, int rem, vector<int> &fcnts) {
    const p_t key(neednums, fcnts);
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }
    int &ret = dp[key];
    if (neednums == 0) {
        ret = 1;
    } else if (rem == 0) {
        ret = 0;
    } else {
        ret = pick(neednums, rem, 0, 0, fcnts);
    }
    return ret;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int choose(int n, int k) {
    vector<int> vals;
    for (int i=0; i<k; ++i) {
        vals.push_back(n-i);
    }
    for (int i=1; i<k; ++i) {
        int v = i+1;
        for (int i=0; v>1 && i<(int)vals.size(); ++i) {
            int d = gcd(v, vals[i]);
            v /= d;
            vals[i] /= d;
        }
        assert(v == 1);
    }
    int ret = 1;
    for (int i=0; i<(int)vals.size(); ++i) {
        ret = modmul(ret, vals[i]);
    }
    return ret;
}
class DivisibleSequence {
public:
    int count(int N, int H) {
        C[0][0] = 1;
        for (int i=1; i<=MAXFAC; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=MAXFAC; ++j) {
                C[i][j] = modadd(C[i-1][j-1], C[i-1][j]);
            }
        }

        vector<int> fcnts;
        for (int d=2; d<=N/d; ++d) {
            if (N%d == 0) {
                int cnt = 0;
                do {
                    ++cnt;
                    N /= d;
                } while (N%d == 0);
                fcnts.push_back(cnt);
            }
        }
        if (N > 1) {
            fcnts.push_back(1);
        }
        int total = accumulate(fcnts.begin(), fcnts.end(), 0);
        dp.clear();
        int sol = 0;
        for (int diffnums=0; diffnums<min(H, total+1); ++diffnums) { // other than N
            int ways = go(diffnums, total, fcnts);
            sol = modadd(sol, modmul(ways, choose(H-1, diffnums)));
        }
        return sol;
    }
};
