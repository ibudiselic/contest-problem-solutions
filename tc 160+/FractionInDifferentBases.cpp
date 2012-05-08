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

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
class FractionInDifferentBases {
public:
    long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
        if (P == 0) {
            return 0;
        }
        Q /= gcd(P, Q);
        long long x = 1;
        for (long long d=2; d*d<=Q; ++d) {
            if (Q%d == 0) {
                x *= d;
                while (Q%d == 0) {
                    Q /= d;
                }
            }
        }
        x *= Q;
        return (B-A+1) - (B/x - (A-1)/x);
    }
};
