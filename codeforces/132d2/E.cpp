#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long calc(int sz, int rpt, long long X) {
    long long segment = X >> ((rpt-1)*sz);
    if (segment < (1ll<<(sz-1))) { // leading zero
        return 0;
    }
    segment = min(segment, (1ll<<sz)-1);
    long long ret = segment - (1ll<<(sz-1));
    long long maxval = segment;
    for (int i=1; i<rpt; ++i) {
        maxval = (maxval << sz) | segment;
    }
    return ret + (maxval <= X);
}
long long calc(long long X) {
    long long ret = 0;
    for (int sz=1; sz<31; ++sz) {
        for (int rpt=2; sz*rpt<61; ++rpt) {
            bool ok = true;
            int prime_cnt = 0;
            int tmp = rpt;
            for (int d=2; d*d<=tmp; ++d) {
                if (tmp%d == 0) {
                    ++prime_cnt;
                    tmp /= d;
                    if (tmp%d == 0) {
                        ok = false;
                        break;
                    }
                }
            }
            prime_cnt += (tmp > 1);
            if (!ok) {
                continue;
            }
            
            ret += ((prime_cnt&1) ? 1 : -1) * calc(sz, rpt, X);
        }
    }
    return ret;
}
int main() {
    long long l, r;
    scanf("%I64d %I64d", &l, &r);
    printf("%I64d\n", calc(r) - calc(l-1));
    return 0;
}
