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

long long calc(long long dig, long long lim) {
    long long chunk = dig*2;
    return (lim+1)/chunk*dig + max(0ll, (lim+1)%chunk - dig);
}
class EllysXors {
public:
    long long getXor(long long L, long long R) {
        long long dig = 1;
        long long sol = 0;
        while (dig <= R) {
            if ((calc(dig, R) - calc(dig, L-1)) & 1) {
                sol |= dig;
            }
            dig <<= 1;
        }
        return sol;
    }
};
