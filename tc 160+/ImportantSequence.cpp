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

const long long inf = 123456789123456LL;
class ImportantSequence {
public:
    int getCount(vector <int> B, string operators) {
        long long must_inc_by = 0;
        long long can_inc_by = inf;
        long long x = 1;
        int n = B.size();
        bool inc_to_inc = true; // increase A[0] to increase A[i+1]?
        for (int i=0; i<n; ++i) {
            if (operators[i] == '+') {
                inc_to_inc = !inc_to_inc;
                x = B[i] - x;
            } else {
                x = x - B[i];
            }
            if (x > 0) {
                if (!inc_to_inc) {
                    can_inc_by = min(can_inc_by, x-1);
                }
            } else {
                if (inc_to_inc) {
                    must_inc_by = max(must_inc_by, -x+1);
                } else {
                    return 0;
                }
            }
        }
        long long lo = 1 + must_inc_by;
        long long hi = 1 + can_inc_by;
        if (lo > hi) {
            return 0;
        }
        if (hi >= inf) {
            return -1;
        }
        return int(hi-lo+1);
    }
};
