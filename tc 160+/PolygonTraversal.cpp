//# polygon, dynamic programming, bitmasks
//# => Notice that a new segment will intersect one of the old segments iff there is at least one used point on either side of the segment.
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

int n;
int first, last;
int origmask;
vector<int> P;
bool inter(int a, int b, int x, int y) {
    bool ret = false;
    if (x==a || x==b || y==a || y==b) {
        ret = false;
    } else {
        for (int iter=0; iter<2; ++iter) {
            if (a<y && y<b && (x<a || x>b)) {
                ret = true;
            }
            swap(x, y);
        }
    }
    return ret;
}
bool ok(int a, int b, int mask) {
    if (a > b) swap(a, b);
    for (int i=0; i+1<(int)P.size(); ++i) {
        if (inter(a, b, P[i], P[i+1])) {
            return true;
        }
    }
    mask ^= origmask;
    for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
            if (inter(a, b, last, i)) {
                return true;
            }
        }
    }
    return false;
}
long long dp[18][1<<18];
long long go(int at, int mask, int taken) {
    long long &ret = dp[at][mask];
    if (ret != -1) {
        return ret;
    }
    assert(mask & (1<<at));
    if (taken == n) {
        ret = (ok(at, first, mask) ? 1 : 0);
    } else {
        ret = 0;
        for (int next=0; next<n; ++next) {
            if (!(mask & (1<<next)) && ok(at, next, mask)) {
                ret += go(next, mask|(1<<next), taken+1);
            }
        }
    }
    return ret;
}
class PolygonTraversal {
public:
    long long count(int N, vector <int> points) {
        n = N;
        for (int i=0; i<(int)points.size(); ++i) {
            --points[i];
        }
        first = points[0];
        last = points.back();
        P = points;
        memset(dp, 0xff, sizeof dp);
        int mask = 0;
        for (int i=0; i<(int)points.size(); ++i) {
            mask |= (1<<points[i]);
        }
        origmask = mask;
        return go(last, mask, int(points.size()));
    }
};
