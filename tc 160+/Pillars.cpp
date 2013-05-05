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
#include <cmath>

using namespace std;

class Pillars {
public:
    double getExpectedLength(int w, int X, int Y) {
        double num = 0.0;
        long long denom = 0;
        if (X < Y) {
            swap(X, Y);
        }
        for (int val=0; val<X; ++val) {
            long long cnt;
            if (val == 0) {
                cnt = Y;
            } else {
                cnt = max(0, min(X-val, Y)) + max(0, Y-val);
            }
            num += cnt*sqrt(w*w + double(val)*val);
            denom += cnt;
        }
        return num/denom;
    }
};
