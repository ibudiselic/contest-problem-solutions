//# geometry, dp, circle, combinatorics, bitmasks
//# => determine sets (bitmasks) of penguins on each side of each line and the set of colors on each side of each possible line... those lines that don't "split" a color are valid i.e. usable in polygons... then solve ways[i][j] by fixing the lowest coordinate of any polygon, then fixedL[i][j] by picking the first line of that polygon... all these are dp subproblems (3 parallel dp-s are in play here)
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

const double PI = acos(-1.0);
const int MAXN = 225;
const double EPS = 1e-9;
long long pengmask[MAXN][MAXN];
long long colormask[MAXN][MAXN];
bool ok[MAXN][MAXN];
typedef pair<double, double> point;
inline point operator-(const point &a, const point &b) {
    return point(a.first-b.first, a.second-b.second);
}
inline double cross(const point &a, const point &b) {
    return a.first*b.second - a.second*b.first;
}
inline int sgn(double x) {
    if (x >= EPS) return 1;
    if (x <= -EPS) return -1;
    return 0;
}
inline int ccw(const point &c, const point &a, const point &b) {
    return sgn(cross(b-a, c-a));
}

int P;
vector<point> fence;

void uniq(string &s) {
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
}
vector<int> make_numcolor(string color) {
    vector<int> numcolor;
    string old = color;
    uniq(color);
    for (int i=0; i<(int)old.size(); ++i) {
        numcolor.push_back(lower_bound(color.begin(), color.end(), old[i]) - color.begin());
    }
    return numcolor;
}

const int mod = 100007;
inline int modadd(int a, int b) {
    a += b;
    return (a>=mod ? a-mod : a);
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
int startline[MAXN][MAXN][2]; // l, r, have a penguin
int fixedL[MAXN][MAXN]; // l, r, must start with l, finish somewhere up to r
int ways[MAXN][MAXN]; // l, r, make fances in any possible way
class FencingPenguins {
public:
    int countWays(int numPosts, int radius, vector <int> x, vector <int> y, string color) {
        vector<int> numcolor = make_numcolor(color);
        fence.clear();
        P = numPosts;
        for (int i=0; i<P; ++i) {
            double phi = i*2*PI/P;
            fence.push_back(point(radius*cos(phi), radius*sin(phi)));
        }
        for (int i=0; i<P; ++i) {
            for (int j=0; j<P; ++j) {
                if (i == j) continue;
                pengmask[i][j] = colormask[i][j] = 0;
                for (int k=0; k<(int)x.size(); ++k) {
                    if (ccw(point(x[k], y[k]), fence[i], fence[j]) == -1) {
                        pengmask[i][j] |= 1ll<<k;
                        colormask[i][j] |= 1ll<<numcolor[k];
                    }
                }
            }
        }
        if (pengmask[P-1][0]) {
            return 0;
        }

        for (int i=0; i<P; ++i) {
            for (int j=i+1; j<P; ++j) {
                if (colormask[i][j] & colormask[j][i]) {
                    ok[i][j] = ok[j][i] = 0;
                } else {
                    ok[i][j] = ok[j][i] = 1;
                }
            }
        }

        memset(ways, 0, sizeof ways);
        memset(fixedL, 0, sizeof fixedL);
        memset(startline, 0, sizeof startline);
        for (int i=0; i+1<P; ++i) {
            if (!pengmask[i][i+1]) {
                assert(ok[i][i+1]);
                startline[i][i+1][1] = fixedL[i][i+1] = ways[i][i+1] = 1;
            } else {
                return 0;
            }
        }
        for (int i=0; i<P; ++i) {
            fixedL[i][i] = ways[i][i] = 1;
        }
        
        for (int diff=2; diff<P; ++diff) {
            for (int l=0; l+diff<P; ++l) {
                int r = l + diff;
                for (int have=0; have<2; ++have) {
                    int &ret = startline[l][r][have];
                    if (have) { // can end the polygon with l->r
                        if (!pengmask[l][r]) {
                            assert(ok[l][r]);
                            ret = modadd(ret, 1);
                        } else if (r-1>l+1 && ok[l][r]) { // if r-1==l+1, then there's just one extra point so can't enclose the penguin
                            if (r-1 > l+1) {
                                long long midmask = pengmask[l][r] & pengmask[r-1][l+1];
                                if (midmask == 0) {
                                    ret = modadd(ret, ways[l+1][r-1]);
                                }
                            }
                        }
                    }
                    for (int m=l+1; m<r; ++m) {
                        if (!ok[l][m]) continue;
                        int triangle_has = !!(pengmask[m][l] & pengmask[r][m] & pengmask[l][r]);
                        int w = 0;
                        if (pengmask[l][m] == 0) {
                            w = 1;
                        } else if (m-l-1 < 3) {
                            continue; // can't make polygon to cover them...
                        } else {
                            long long midmask = pengmask[l][m] & pengmask[m-1][l+1];
                            if (midmask != 0) {
                                continue;
                            } else {
                                w = ways[l+1][m-1];
                            }
                        }
                        ret = modadd(ret, modmul(w, startline[m][r][have||triangle_has]));
                    }
                }

                if (pengmask[l][r] == 0) {
                    fixedL[l][r] = ways[l][r] = 1;
                } else {
                    if (ok[l][r]) {
                        fixedL[l][r] = startline[l][r][0]; // set m = r
                    }
                    if (ok[l][r-1] && (pengmask[r-1][l] & pengmask[l][r])==0) {
                        fixedL[l][r] = modadd(fixedL[l][r], startline[l][r-1][0]);
                    }
                    for (int m=l+2; m+1<r; ++m) {
                        if (!ok[l][m]) continue;
                        int triangle_has = !!(pengmask[m][l] & pengmask[r][m+1] & pengmask[l][r]);
                        if (triangle_has) continue;
                        fixedL[l][r] = modadd(fixedL[l][r], modmul(startline[l][m][0], ways[m+1][r]));
                    }

                    ways[l][r] = fixedL[l][r]; // set m = l
                    for (int m=l+1; m+1<r; ++m) {
                        if (pengmask[l][r] & pengmask[r][m]) break;
                        ways[l][r] = modadd(ways[l][r], fixedL[m][r]);
                    }
                }
            }
        }

        return ways[0][P-1];
    }
};
