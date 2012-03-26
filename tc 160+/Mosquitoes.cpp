#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int calc(const vector<int> &x, const vector<int> &v, int R, long long num, long long denom) {
    int ret = 0;
    int n = x.size();
    for (int i=0; i<n; ++i) {
        int l = 0;
        int r = 0;
        for (int j=0; j<n; ++j) {
            long long dist = (x[i]*denom+num*v[i] - (x[j]*denom+num*v[j]));
            if (-2*R*denom<=dist && dist<=0) ++l;
            if (0<=dist && dist<=2*R*denom) ++r;
        }
        ret = max(ret, max(l, r));
    }
    return ret;
}
int sgn(int x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}
class Mosquitoes {
public:
    int getMaximum(vector <int> x, vector <int> v, int R) {
        int n = x.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (x[i] > x[j]) {
                    swap(x[i], x[j]);
                    swap(v[i], v[j]);
                }
            }
        }
        
        int sol = calc(x, v, R, 0, 1);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (v[i] > v[j]) {
                    sol = max(sol, calc(x, v, R, 2*R+x[j]-x[i], v[i]-v[j]));
                }
                if (sgn(-2*R+x[j]-x[i]) == sgn(v[i]-v[j])) {
                    sol = max(sol, calc(x, v, R, -2*R+x[j]-x[i], v[i]-v[j]));
                }
            }
        }
        
        return sol;
    }
};
