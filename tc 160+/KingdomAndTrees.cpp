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

bool can(int D, const vector<int> &H) {
    int last = 0;
    for (int i=0; i<(int)H.size(); ++i) {
        int lo = max(1, H[i]-D);
        int hi = H[i] + D;
        if (hi <= last) {
            return false;
        }
        last = max(last+1, lo);
    }
    return true;
}
class KingdomAndTrees {
public:
    int minLevel(vector <int> heights) {
        int lo = 0;
        int hi = 1000000000;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (can(mid, heights)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
