//# dp, integer division, megafactorial, factorial
//# => represent megafactorial as the exponents in its unique prime factorization and dp on that...
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

typedef pair<int, int> pii;
typedef vector<pii> factors_t;
const int mod = 1000000009;
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
void add(const factors_t &a, const factors_t &b, factors_t &c) {
    c.clear();
    int i = 0;
    int j = 0;
    while (i<(int)a.size() && j<(int)b.size()) {
        if (a[i].first < b[j].first) {
            c.push_back(a[i++]);
        } else if (a[i].first > b[j].first) {
            c.push_back(b[j++]);
        } else {
            c.push_back(pii(a[i].first, modadd(a[i].second, b[j].second)));
            ++i;
            ++j;
        }
    }
    copy(a.begin()+i, a.end(), back_inserter(c));
    copy(b.begin()+j, b.end(), back_inserter(c));
}
void compute_factors(int n, factors_t &f) {
    f.clear();
    int d = 2;
    while (d*d <= n) {
        if (n%d == 0) {
            int cnt = 0;
            do {
                ++cnt;
                n /= d;
            } while (n%d == 0);
            f.push_back(pii(d, cnt));
        }
        ++d;
    }
    if (n > 1) {
        f.push_back(pii(n, 1));
    }
}
int numdivs(const factors_t &f) {
    int ret = 1;
    for (factors_t::const_iterator it=f.begin(); it!=f.end(); ++it) {
        ret = modmul(ret, modadd(it->second, 1));
    }
    return ret;
}
class MegaFactorialDiv2 {
public:
    int countDivisors(int N, int K) {
        vector<vector<factors_t> > factors(2, vector<factors_t>(N+1));
        for (int n=2; n<=N; ++n) {
            compute_factors(n, factors[0][n]);
        }
        for (int k=1; k<=K; ++k) {
            int cur = k&1;
            int prev = 1-cur;
            for (int n=1; n<=N; ++n) {
                add(factors[prev][n], factors[cur][n-1], factors[cur][n]);
            }
        }

        return numdivs(factors[K&1][N]);
    }
};
