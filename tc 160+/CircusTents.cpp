#include <algorithm>
#include <cassert>
#include <cctype>
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
#include <cmath>

using namespace std;

double PI = acos(-1.0);

int n;
vector<int> x, y, r;
double rdist[51];
double Pphi[51];
double rotphi[51];
double fix(double phi) {
    if (phi < 0) {
        phi += 2*PI;
    } else if (phi > 2*PI) {
        phi -= 2*PI;
    }
    return phi;
}
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double ddist(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double direct_dist(double Qphi, int i) {
    Qphi = fix(Qphi);
    assert(Qphi<=PI/2+1e-9 || Qphi>=3*PI/2-1e-9);
    return ddist(r[0]*cos(Qphi), r[0]*sin(Qphi), rdist[i], 0.0) - r[i];
}
double pathdist(double Qphi, int i) {
    Qphi = fix(Qphi);
    if (Qphi<=PI && Qphi>Pphi[i]) {
        return (Qphi-Pphi[i])*r[0] + direct_dist(Pphi[i], i);
    } else if (Qphi>=PI && Qphi<-Pphi[i]+2*PI) {
        return (-Pphi[i]+2*PI-Qphi)*r[0] + direct_dist(-Pphi[i], i);
    } else {
        return direct_dist(Qphi, i);
    }
}
bool can(double D) {
    vector<double> degs;
    degs.push_back(0.0);
    degs.push_back(2*PI);
    for (int i=1; i<n; ++i) {
        if (pathdist(PI, i) < D) {
            return false;
        }
        double lo = 0;
        double hi = PI;
        for (int iter=0; iter<200; ++iter) {
            double mid = (lo+hi)/2;
            if (pathdist(mid, i) >= D) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        double a = fix(hi+rotphi[i]);
        double b = fix(-hi+rotphi[i]);
        degs.push_back(a);
        degs.push_back(b);
    }
    sort(degs.begin(), degs.end());
    for (int i=1; i<(int)degs.size(); ++i) {
        double phi = fix((degs[i]+degs[i-1])/2);
        bool ok = true;
        for (int j=1; j<n; ++j) {
            double pphi = fix(phi - rotphi[j]);
            if (pathdist(pphi, j) < D) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}
class CircusTents {
public:
    double findMaximumDistance(vector <int> x, vector <int> y, vector <int> r) {
        n = x.size();
        for (int i=1; i<n; ++i) {
            x[i] -= x[0];
            y[i] -= y[0];
        }
        x[0] = y[0] = 0;
        for (int i=1; i<n; ++i) {
            rdist[i] = dist(0, 0, x[i], y[i]);
            Pphi[i] = acos(r[0]/rdist[i]);
            assert(Pphi[i]>=-1e-9 && Pphi[i]<=PI/2+1e-9);
            rotphi[i] = (y[i]==0 ? (x[i]>0 ? 0.0 : PI) : atan2(y[i], x[i]));
            assert(Pphi[i]>=0 && Pphi[i]<=PI/2);
        }
        ::x = x;
        ::y = y;
        ::r = r;

        double lo = 0.0;
        double hi = 1000000.0;
        for (int iter=0; iter<200; ++iter) {
            double mid = (lo+hi)/2;
            if (can(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
