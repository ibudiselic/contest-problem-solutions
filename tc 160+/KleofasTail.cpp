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

long long cnt(long long n, long long k) {
    if (n < 0) return 0;
    if (k == 0) return n + 1;
    
    long long add = 2 - (k&1);
    long long ret = 0;
    while (k <= n) {
        ret += min(add, n-k+1);
        if (k > n/2) {
            break;
        }
        add *= 2;
        k *= 2;
    }
    return ret;
}
class KleofasTail {
public:
    long long countGoodSequences(long long K, long long A, long long B) {
        return cnt(B, K) - cnt(A-1, K);
    }
};
