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
#include <numeric>
#include <cmath>

using namespace std;

bool can(double alpha, int K, const vector<int> &a, const vector<int> &p) {
    vector<double> v;
    for (int i=0; i<(int)a.size(); ++i) {
        v.push_back(a[i]*(p[i]-alpha));
    }
    sort(v.begin(), v.end());
    double sum = accumulate(v.begin(), v.begin()+K, 0.0);
    return sum <= -K*3600.0;
}
class FoxAndBusiness {
public:
    double minimumCost(int K, int TW, vector <int> a, vector <int> p) {
        double lo = 0.0;
        double hi = 1e20;
        for (int iter=0; iter<200; ++iter) {
            double mid = (lo+hi)/2.0;
            if (can(mid, K, a, p)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        return hi*TW;
    }
};
