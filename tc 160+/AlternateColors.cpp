//# case
//# => trivial
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

string R = "RED";
string G = "GREEN";
string B = "BLUE";
string res[] = {R, G, B};
string two(long long a, long long b, long long k, string sA, string sB) {
    long long step = min(a, b);
    if (2*step >= k) {
        return (k&1) ? sA : sB;
    } else if (step == a) {
        return sB;
    } else {
        return sA;
    }
}
string gb(long long a, long long b, long long k) {
    return two(a, b, k, G, B);
}
string rb(long long a, long long b, long long k) {
    return two(a, b, k, R, B);
}
string rg(long long a, long long b, long long k) {
    return two(a, b, k, R, G);
}
class AlternateColors {
public:
    string getColor(long long r, long long g, long long b, long long k) {
        long long step = min(r, min(g, b));
        if (3*step >= k) {
            return res[(k-1)%3];
        } else {
            if (step == r) {
                if (step == g) {
                    return B;
                } else if (step == b) {
                    return G;
                } else {
                    return gb(g-step, b-step, k-3*step);
                }
            } else {
                if (step == g) {
                    if (step == b) {
                        return R;
                    } else {
                        return rb(r-step, b-step, k-3*step);
                    }
                } else {
                    assert(step == b);
                    return rg(r-step, g-step, k-3*step);
                }
            }
        }
    }
};
