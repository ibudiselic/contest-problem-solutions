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

bool ok(long long k, long long p, long long R, long long G, long long B) {
    return k<=R/p && R+G+B-3*k*p>=k;
}
class FoxPaintingBalls {
public:
    long long theMax(long long R, long long G, long long B, int N) {
        if (N == 1) {
            return R+G+B;
        }
        long long X = N/3;
        long long Y = max(0ll, (N-1ll)/3);
        long long Z = max(0ll, (N-2ll)/3);
        long long A = (X+1)*X/2 + (Y+2)*(Y+1)/2 + Z*(Z+1)/2;
        long long BB = (X+1)*X/2 + (Z+2)*(Z+1)/2 + Y*(Y+1)/2;

        vector<long long> v;
        v.push_back(R);
        v.push_back(G);
        v.push_back(B);
        sort(v.begin(), v.end());
        if (A == BB) {
            return v[0]/A;
        } else {
            assert(A-1 == BB);
            long long lo = 0;
            long long hi = 1;
            while (ok(hi, BB, v[0], v[1], v[2])) {
                lo = hi;
                hi *= 2;
            }
            while (lo+1 < hi) {
                long long mid = lo + (hi-lo)/2;
                if (ok(mid, BB, v[0], v[1], v[2])) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            return lo;
        }
    }
};
