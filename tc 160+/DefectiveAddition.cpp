//# bitmasks, xor
//# => consider the smallest 'move' (decide the first bit of the number for the largest card)
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

const long long mod = 1000000007;
inline long long modmul(long long a, long long b) {
    a *= b;
    return a>=mod ? a%mod : a;
}
inline long long modadd(long long a, long long b) {
    a += b;
    return a>=mod ? a-mod : a;
}
long long solve(vector<int> C, long long target) {
    int n = C.size();
    assert(n > 0);
    long long ret = 0;
    while (1) {
        int maxpos = max_element(C.begin(), C.end()) - C.begin();
        if (maxpos+1 < (int)C.size()) {
            swap(C[maxpos], C.back());
        }
        long long maxval = C.back();
        if (maxval == 0) {
            return ret + (target==0 ? 1 : 0);
        }
        int bitval = 1;
        while (2*bitval <= maxval) {
           bitval *= 2;
        }
        if (2*bitval <= target) {
            return ret;
        }
        // pick 0 to start b[n-1]
        long long even = 1;
        long long odd = 0;
        for (int i=0; i+1<n; ++i) {
            if (C[i] & bitval) {
                long long e=even, o=odd;
                even = modadd(modmul(e, bitval), modmul(o, C[i]-bitval+1));
                odd = modadd(modmul(o, bitval), modmul(e, C[i]-bitval+1));
            } else {
                even = modmul(even, C[i]+1);
                odd = modmul(odd, C[i]+1);
            }
        }
        if (target & bitval) {
            ret = modadd(ret, odd);
        } else {
            ret = modadd(ret, even);
        }

        // pick 1 to start b[n-1]
        C.back() -= bitval;
        target ^= bitval;
    }

    return ret;
}
class DefectiveAddition {
public:
    int count(vector <int> cards, int n) {
        return int(solve(cards, n));
    }
};
