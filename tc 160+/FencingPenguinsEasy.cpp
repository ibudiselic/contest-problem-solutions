//# geometry, dp
//# => compute good segments (those that don't have any penguins on to their right) then pretty simple dp by trying all possible starting segments
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

typedef pair<double, double> point;

int R;
int P;
const int MAXP = 225;
vector<point> fence, pengs;
int n;
const double EPS = 1e-9;
bool done[MAXP];
double dp[MAXP];
int start;
const double inf = 1e32;
bool ok[MAXP][MAXP];
inline point operator-(const point &a, const point &b) {
    return point(a.first-b.first, a.second-b.second);
}
inline double cross(const point &a, const point &b) {
    return a.first*b.second - a.second*b.first;
}
inline double ccw(const point &c, const point &a, const point &b) {
    return cross(b-a, c-a);
}
double go(int at) {
    double &ret = dp[at];
    if (done[at]) return ret;
    done[at] = 1;
    ret = inf;
    for (int next=at+1; next<P; ++next) {
        if (!ok[at][next]) {
            break;
        }
        double add = cross(fence[next]-fence[at], fence[start]-fence[next]);
        if (ok[next][start]) {
            ret = min(ret, add);
        } else {
            ret = min(ret, add + go(next));
        }
    }
    return ret;
}
class FencingPenguinsEasy {
public:
    double calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y) {
        R = radius;
        P = numPosts;
        const double pi = acos(-1.0);
        fence.clear();
        for (int i=0; i<P; ++i) {
            double phi = i*2*pi/P;
            fence.push_back(point(R*cos(phi), R*sin(phi)));
        }
        n = x.size();
        pengs.clear();
        for (int i=0; i<n; ++i) {
            pengs.push_back(point(x[i], y[i]));
        }
        for (int i=0; i<P; ++i) {
            for (int j=0; j<P; ++j) {
                if (i != j) {
                    ok[i][j] = true;
                    for (int k=0; k<n; ++k) {
                        if (ccw(pengs[k], fence[i], fence[j]) <= -EPS) {
                            ok[i][j] = false;
                            break;
                        }
                    }
                }
            }
        }

        double sol = inf;
        for (start=0; start<P; ++start) {
            memset(done, 0, sizeof done);
            for (int first=start+1; first<P; ++first) {
                if (!ok[start][first]) {
                    break;
                }
                sol = min(sol, go(start));
            }
        }
        return sol > 1e30 ? -1.0 : sol/2;
    }
};
