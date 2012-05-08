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

class RandomColoringDiv2 {
public:
    int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
        int sol = 0;
        for (int i=max(0, startR-d2); i<=min(maxR-1, startR+d2); ++i) {
            for (int j=max(0, startG-d2); j<=min(maxG-1, startG+d2); ++j) {
                for (int k=max(0, startB-d2); k<=min(maxB-1, startB+d2); ++k) {
                    if (abs(startR-i)>=d1 || abs(startG-j)>=d1 || abs(startB-k)>=d1) {
                        ++sol;
                    }
                }
            }
        }
        return sol;
    }
};
