#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000009;
int calcsum(long long N, long long j, long long k) { // sum for d in [j+1, k] of floor(N/d)
    if (j+1 > k) {
        return 0;
    }
    long long ret = 0;
    for (long long d=N/k+1; d<=N/j; ++d) {
        ret = (ret + N/d)%mod;
    }
    ret += k*(N/k) - j*(N/j);
    return int((ret%mod + mod)%mod);
}
class MinskyMystery {
public:
    int computeAnswer(long long N) {
        if (N < 2) {
            return -1;
        }
        long long sol = 1;
        long long d = 2;
        while (d*d <= N) {
            if (N%d == 0) {
                return (sol + N/d*(3*d+1) + 1) % mod;
            } else {
                sol = (sol + 4*N + 2 + N/d) % mod;
                ++d;
            }
        }
        return (sol + (N-d)%mod*(4*N%mod + 2) + calcsum(N, d-1, N-1) + 3*N + 2)%mod;
    }
};
