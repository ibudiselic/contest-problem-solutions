//# triangle, geometry, ccw, precomputation, recursion
//# => Precompute if any vector can be part of the solution triangle. Then recursively enumerate all candidate triangles and count them.
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

struct point {
    int x, y;
};
point operator-(const point &a, const point &b) {
    return {a.x-b.x, a.y-b.y};
}
vector<point> blacks, pts;
long long ccw(const point &a, const point &b) {
    return (long long)a.x*b.y - (long long)a.y*b.x;
}
bool all_right(int a, int b) {
    point p = pts[b] - pts[a];
    for (int i=0; i<(int)blacks.size(); ++i) {
        if (ccw(p, blacks[i]-pts[a]) > 0) {
            return false;
        }
    }
    return true;
}
bool ok[1205][1205];
int C;
int go(int at, int need, int last, int first) {
    if (need == 0) {
        return ok[last][first];
    } else if (at >= (int)pts.size()) {
        return 0;
    } else {
        int ret = 0;
        if (last == -1) {
            ret = go((at/C+1)*C, need-1, at, at);
            ret += go(at+1, need, -1, -1);
        } else {
            if (ok[last][at]) {
                ret += go((at/C+1)*C, need-1, at, first);
            }
            ret += go(at+1, need, last, first);
        }
        return ret;
    }
}
class EnclosingTriangleColorful {
public:
    int getNumber(int m, vector <int> x, vector <int> y) {
        blacks.clear();
        pts.clear();
        for (int i=0; i<(int)x.size(); ++i) {
            blacks.push_back({x[i], y[i]});
        }
        for (int i=1; i<m; ++i) pts.push_back({0, i});
        for (int i=1; i<m; ++i) pts.push_back({i, m});
        for (int i=1; i<m; ++i) pts.push_back({m, m-i});
        for (int i=1; i<m; ++i) pts.push_back({m-i, 0});

        for (int i=0; i<(int)pts.size(); ++i) {
            for (int j=i+1; j<(int)pts.size(); ++j) {
                ok[i][j] = all_right(i, j);
                ok[j][i] = all_right(j, i);
            }
        }
        C = m-1;
        return go(0, 3, -1, -1);
    }
};
