#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> W, S;
int L;
inline double len(double a, double b) {
    return sqrt(a*a + b*b);
}
const int NITER = 100;
double calc12(double goal) {
    double lo = 0.0;
    double hi = goal;
    for (int iter=0; iter<NITER; ++iter) {
        double m1 = lo + (hi-lo)/3;
        double m2 = m1 + (hi-lo)/3;
        if (len(m1, W[0])/S[0]+len(goal-m1, W[1])/S[1] < len(m2, W[0])/S[0]+len(goal-m2, W[1])/S[1]) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    return len(lo, W[0])/S[0] + len(goal-lo, W[1])/S[1];
}
double calc(double goal) {
    double lo = 0.0;
    double hi = goal;
    for (int iter=0; iter<NITER; ++iter) {
        double m1 = lo + (hi-lo)/3;
        double m2 = m1 + (hi-lo)/3;
        if (calc12(m1)+len(goal-m1, W[2])/S[2] < calc12(m2)+len(goal-m2, W[2])/S[2]) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    return calc12(lo) + len(goal-lo, W[2])/S[2];
}
class EllysThreeRivers {
public:
    double getMin(int length, int walk, vector <int> width, vector <int> swim) {
        L = length;
        W = width;
        S = swim;
        double lo = 0.0;
        double hi = L;
        for (int iter=0; iter<NITER; ++iter) {
            double m1 = lo + (hi-lo)/3;
            double m2 = m1 + (hi-lo)/3;
            if (calc(m1)+(L-m1)/walk < calc(m2)+(L-m2)/walk) {
                hi = m2;
            } else {
                lo = m1;
            }
        }

        return calc(lo)+(L-lo)/walk;
    }
};
