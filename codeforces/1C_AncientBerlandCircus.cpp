#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

double x[3], y[3];
double d[3];
const double eps = 1e-5;
const double pi = acos(-1.0);
inline double sqr(double t) { return t*t; }
int main() {
    for (int i=0; i<3; ++i) {
        scanf("%lf %lf", x+i, y+i);
    }
    for (int i=0; i<3; ++i) {
        for (int j=i+1; j<3; ++j) {
            d[3-i-j] = sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
        }
    }
    
    int cnt_eps = 0;
    for (int i=0; i<3; ++i) {
        cnt_eps += (d[i] < eps);
    }
    
    double sol = 1e32;
    if (cnt_eps == 3) {
        sol = 0.0;
    } else if (cnt_eps > 0) {
        double D = 0.0;
        for (int i=0; i<3; ++i) {
            D = max(D, d[i]);
        }
        const double R = D/2;
        sol = R*R*pi;
    } else {
        double ang[3];
        double sum = 0.0;
        double prod = 2.0;
        for (int i=0; i<3; ++i) {
            sum += sqr(d[i]);
            prod *= d[i];
        }
        for (int i=0; i<3; ++i) {
            ang[i] = acos((sum-2*sqr(d[i]))/(prod/d[i]));
        }
        
        int n = 3;
        while (true) {
            double alpha = pi/n;
            bool ok = true;
            for (int i=0; i<3; ++i) {
                if (fabs(ang[i] - int(ang[i]/alpha + 0.5)*alpha) > eps) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                const double s = (d[0]+d[1]+d[2])/2.0; // (a+b+c)/2
                const double D = prod/4.0/sqrt(s*(s-d[0])*(s-d[1])*(s-d[2])); // abc/2A
                const double R = D/2.0;
                sol = n * R*R*sin(2.0*alpha)/2.0;
                break;
            }
            ++n;
        }
    }

    printf("%.12f\n", sol);
    
    return 0;
}
