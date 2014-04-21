//# geometry, circles, rings, reachability
//# => The key insight is that if some circle is reachable from another reachable circle, then any point on the intersection between the two circles is reachable. Use this to update continually until new circles are becoming reachable (only "relax" each "edge" once). See the editrial for details.
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

struct circle {
    int x, y, r;
};
bool operator<(const circle &a, const circle &b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.r < b.r;
}
double D[55][55];
inline double sqr(double x) {return x*x;}
double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
double A[55], B[55];
bool updated[55][55];
inline bool intersects(double x1, double y1, double x2, double y2) {
    return !(x2>y1 || x1>y2);
}
class CandyOnDisk {
public:
    string ableToAchieve(vector <int> x, vector <int> y, vector <int> r, int sx, int sy, int tx, int ty) {
        if (sx==tx && sy==ty) {
            return "YES";
        }
        vector<circle> V;
        for (int i=0; i<(int)x.size(); ++i) {
            V.push_back((circle){x[i], y[i], r[i]});
        }
        sort(begin(V), end(V));

        vector<circle> P(1, V.back());
        for (int i=(int)V.size()-2; i>=0; --i) {
            if (V[i].x!=V[i+1].x || V[i].y!=V[i+1].y) {
                P.push_back(V[i]);
            }
        }

        int n = P.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                D[i][j] = D[j][i] = dist(P[i].x, P[i].y, P[j].x, P[j].y);
            }
        }
        vector<char> reachable(n);
        for (int i=0; i<n; ++i) {
            double d = dist(P[i].x, P[i].y, sx, sy);
            if (d < P[i].r) {
                reachable[i] = 1;
                A[i] = B[i] = d;
            } else {
                A[i] = 1e10;
                B[i] = -1e10;
            }
        }

        memset(updated, 0, sizeof updated);
        while (1) {
            bool change = false;
            for (int i=0; i<n; ++i) {
                if (!reachable[i]) continue;
                for (int j=0; j<n; ++j) {
                    if (i==j || updated[i][j]) continue;
                    double a = max(0.0, D[i][j]-P[j].r);
                    double b = D[i][j]+P[j].r;
                    if (intersects(A[i], B[i], a, b)) {
                        updated[i][j] = 1;
                        reachable[j] = 1;
                        change = true;
                        A[i] = min(A[i], a);
                        B[i] = max(B[i], min(double(P[i].r), b));
                        A[j] = min(A[j], max(0.0, D[i][j]-P[i].r));
                        B[j] = max(B[j], min(double(P[j].r), D[i][j]+P[i].r));
                    }
                }
            }
            if (!change) {
                break;
            }
        }
        for (int i=0; i<n; ++i) {
            if (reachable[i]) {
                double d = dist(P[i].x, P[i].y, tx, ty);
                if (A[i]<d && d<B[i]) {
                    return "YES";
                }
            }
        }
        return "NO";
    }
};
