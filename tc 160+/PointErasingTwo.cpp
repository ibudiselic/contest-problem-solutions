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

class PointErasingTwo {
public:
    int getMaximum(vector <int> y) {
        int n = y.size();
        int sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+2; j<n; ++j) {
                int cand = 0;
                int ylo = min(y[i], y[j]);
                int yhi = max(y[i], y[j]);
                for (int k=i+1; k<j; ++k) {
                    if (ylo<y[k] && y[k]<yhi) {
                        ++cand;
                    }
                }
                sol = max(sol, cand);
            }
        }
        return sol;
    }
};
