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
#include <cmath>

using namespace std;

class MagicBlizzard {
public:
    double expectation(vector <int> range, vector <int> amount) {
        int n = range.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (range[i] > range[j]) {
                    swap(range[i], range[j]);
                    swap(amount[i], amount[j]);
                }
            }
        }
        double sol = 0.0;
        for (int r=0; r<=range.back(); ++r) {
            int cells = (r==0 ? 1 : r*8);
            double E = 0.0;
            double Var = 0.0;
            int i = lower_bound(range.begin(), range.end(), r) - range.begin();
            while (i < n) {
                double p = 1.0/(2*range[i]+1)/(2*range[i]+1);
                E += amount[i]*p;
                Var += amount[i]*p*(1-p);
                ++i;
            }
            sol += cells * (Var + E*E);
        }
        return sol;
    }
};
