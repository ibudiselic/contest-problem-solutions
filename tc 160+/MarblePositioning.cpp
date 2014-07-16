//# geometry, circles, permutations, implementation
//# => Figure out center distance of two circles and try all permutations.
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

inline long double sqr(long double x) { return x*x; }
long double rdist(long double r1, long double r2) {
    return sqrt(sqr(r1+r2) - sqr(r2-r1));
}
class MarblePositioning {
public:
    double totalWidth(vector <int> radius) {
        sort(begin(radius), end(radius));
        int n = radius.size();
        long double sol = 1e32;
        vector<long double> pos(n);
        do {
            pos[0] = 0.0;
            for (int i=1; i<n; ++i) {
                pos[i] = 0.0;
                for (int j=0; j<i; ++j) {
                    pos[i] = max(pos[i], pos[j] + rdist(radius[i], radius[j]));
                }
            }
            sol = min(sol, pos.back());
        } while (next_permutation(begin(radius), end(radius)));
        return double(sol);
    }
};
