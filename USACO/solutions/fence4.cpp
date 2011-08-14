/*
ID: ivan.bu1
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <cmath>

using namespace std;

int n;
struct point {
    long long x, y;
    point(long long x_=0, long long y_=0): x(x_), y(y_) {}
};
bool operator==(const point &a, const point &b) {
    return a.x==b.x && a.y==b.y;
}
bool operator!=(const point &a, const point &b) {
    return a.x!=b.x || a.y!=b.y;
}
point operator-(const point &a, const point &b) {
    return point(a.x-b.x, a.y-b.y);
}

bool eq(double a, double b) {
    return fabs(a-b) < 1e-9;
}
point observer;
vector<point> P;
bool visible[101];
long long sqr(long long x) {
    return x*x;
}
long long dist2(const point &a, const point &b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}
double dist2(const point &a, double x, double y) {
    return (a.x-x)*(a.x-x) + (a.y-y)*(a.y-y);
}
int sgn0(long long num) {
    return num<0 ? -1 : num==0 ? 0 : 1;
}
int ccw(const point &u, const point &v) {
    return sgn0(u.x*v.y - u.y*v.x);
}
int ccw(const point &c, const point &a, const point &b) {
    return ccw(b-a, c-a);
}
bool strictly_between(const point &c, const point &a, const point &b) {
    assert(ccw(c, a, b) == 0);
    return c!=a && c!=b && dist2(a, c)<dist2(a, b) && dist2(b, c)<dist2(a, b);
}
bool intersects(const point &a, const point &b, const point &c, const point &d) {
    int t1 = ccw(c, a, b);
    int t2 = ccw(d, a, b);
    int t3 = ccw(a, c, d);
    int t4 = ccw(b, c, d);
    
    if (t1==0 && strictly_between(c, a, b)
        ||
        t2==0 && strictly_between(d, a, b)
        ||
        t3==0 && strictly_between(a, c, d)
        ||
        t4==0 && strictly_between(b, c, d)) {
        return true;
    }
    
    return t1*t2==-1 && t3*t4==-1;
}
bool intersects(int i, int j) {
    return intersects(P[i], P[i+1], P[j], P[j+1]);
}
bool intersects() {
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (intersects(i, j)) {
                return true;
            }
        }
    }
    return false;
}

void shoot(long long x, long long y) {
    int hits = -1;
    double hit_dist = 1e32;
    point scope(x, y);
    if (x==observer.x && y==observer.y) {
        return;
    }
    for (int i=0; i<n; ++i) {
        int t1 = ccw(P[i], observer, scope);
        int t2 = ccw(P[i+1], observer, scope);
        if (t1==0 && t2==0) { // parallel
            continue;
        }
        
        // if we are hitting a point, we must make sure that
        // we don't take anything "behind" this point
        // anything behind the point that we might want to hit
        // will be hit by a "better" scope - for example one that
        // lies between this point that we are hitting and
        // another point
        // therefore, we don't need to check does this point actually
        // blcok the ray or not - just assume it does
        if (t1 == 0) {
            double d2 = dist2(observer, P[i]);
            if (d2 < hit_dist) {
                hits = -1;
                hit_dist = d2;
            }
            continue;
        }
        if (t2 == 0) {
            long long d2 = dist2(observer, P[i+1]);
            if (d2 < hit_dist) {
                hits = -1;
                hit_dist = d2;
            }
            continue;
        }
        
        if (t1*t2 == -1) {
            long long x1 = P[i].x, x2 = P[i+1].x, y1 = P[i].y, y2 = P[i+1].y;
            double ix, iy;
            if (observer.x == scope.x) {
                ix = observer.x;
                assert(x1 != x2); // already checked if parallel
                iy = (y2-y1)/double(x2-x1)*(ix-x1)+y1;
            } else if (observer.y == scope.y) {
                iy = observer.y;
                assert(y1 != y2);
                ix = (x2-x1)/double(y2-y1)*(iy-y1)+x1;
            } else if (x1 == x2) {
                ix = x1;
                iy = double(scope.y-observer.y)/(scope.x-observer.x)*(ix-observer.x)+observer.y;
            } else if (y1 == y2) {
                iy = y1;
                ix = double(scope.x-observer.x)/(scope.y-observer.y)*(iy-observer.y)+observer.x;
            } else {
                double k1 = double(y2-y1)/(x2-x1);
                double k2 = double(scope.y-observer.y)/(scope.x-observer.x);
                ix = (observer.y-y1-k2*observer.x+k1*x1)/(k1-k2);
                iy = k1*(ix-x1)+y1;
            }
            double d2 = dist2(observer, ix, iy);
            if (eq(sqrt(dist2(scope, ix, iy)), sqrt(d2) + sqrt(dist2(scope, observer)))) {
                continue;
            }
            if (d2 < hit_dist) {
                hits = i;
                hit_dist = d2;
            }
        }
    }

    if (hits != -1) {
        visible[hits] = 1;
    }
}
int main() {
	ifstream fin("fence4.in");
    fin >> n;
    fin >> observer.x >> observer.y;
    observer.x *= 2;
    observer.y *= 2;
    int x, y;
    for (int i=0; i<n; ++i) {
        fin >> x >> y;
        P.push_back(point(2*x, 2*y));
    }
    fin.close();
    P.push_back(P[0]);

    ofstream fout("fence4.out");
    if (intersects()) {
        fout << "NOFENCE\n";
    } else {
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                shoot((P[i].x+P[j].x)/2, (P[i].y+P[j].y)/2);
            }
        }
        for (int i=0; i<n; ++i) {
            P[i].x /= 2;
            P[i].y /= 2;
        }
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            cnt += visible[i];
        }
        fout << cnt << '\n';
        for (int i=0; i<n-2; ++i) {
            if (visible[i]) {
                fout << P[i].x << ' ' << P[i].y << ' ' << P[i+1].x << ' ' << P[i+1].y << '\n';
            }
        }
        if (visible[n-1]) {
            fout << P[0].x << ' ' << P[0].y << ' ' << P[n-1].x << ' ' << P[n-1].y << '\n';
        }
        if (visible[n-2]) {
            fout << P[n-2].x << ' ' << P[n-2].y << ' ' << P[n-1].x << ' ' << P[n-1].y << '\n';
        }
    }
    fout.close();

	return 0;
}
