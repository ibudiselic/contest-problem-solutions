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
#include <functional>

using namespace std;

class RollingDiceDivOne {
public:
    long long mostLikely(vector <int> dice) {
        sort(dice.begin(), dice.end(), greater<int>());
        long long l = 1;
        long long r = dice[0];
        for (int i=1; i<(int)dice.size(); ++i) {
            if (dice[i] <= r-l+1) {
                l += dice[i];
                ++r;
            } else if ((dice[i]&1) == ((r-l+1)&1)) {
                r += 1 + (dice[i] - (r-l+1))/2;
                l = r;
            } else {
                l = r + 1 + (dice[i] - (r-l+1))/2;
                r = l + 1;
            }
        }
        return l;
    }
};
