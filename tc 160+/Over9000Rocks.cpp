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

bool can[15000001];
class Over9000Rocks {
public:
    int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
        int n = lowerBound.size();
        memset(can, 0, sizeof can);
        for (int mask=0; mask<(1<<n); ++mask) {
            int lo = 0;
            int hi = 0;
            for (int i=0; i<n; ++i) {
                if (mask & (1<<i)) {
                    lo += lowerBound[i];
                    hi += upperBound[i];
                }
            }
            for (int i=lo; i<=hi; ++i) {
                can[i] = true;
            }
        }
        
        return count(can+9001, can+15000001, true);
    }
};
