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

vector<int> C;
int X, Y;
int S;
int dp[51][1001];
const int inf = 123456789;
int ymax(int at, int xcnt) {
    int &ret = dp[at][xcnt];
    if (ret != -1) {
        return ret;
    }
    if (at == (int)C.size()) {
        return (ret = (xcnt==S ? 0 : -inf));
    }
    ret = -inf;
    int k = 0;
    while (k*X<=C[at] && xcnt+k<=S) {
        ret = max(ret, min((C[at]-k*X)/Y, S-k) + ymax(at+1, xcnt+k));
        ++k;
    }
    return ret;
}
bool can(int steps) {
    S = steps;
    memset(dp, 0xff, sizeof dp);
    return ymax(0, 0) >= S;
}
class ColorfulCookie {
public:
    int getMaximum(vector <int> cookies, int P1, int P2) {
        C = cookies;
        X = P1;
        Y = P2;
        int lo = 0;
        int hi = 1000;
        while (lo < hi) {
            int steps = lo + (hi-lo+1)/2;
            if (can(steps)) {
                lo = steps;
            } else {
                hi = steps - 1;
            }
        }
        
        return lo * (X + Y);
    }
};
