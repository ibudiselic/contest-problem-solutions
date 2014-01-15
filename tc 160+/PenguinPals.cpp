//# dp, simple dp
//# => state space is basically "smallest area to enclose penguins in the part of the circle to the right of the vector l->r
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string C;
int n;
int dp[55][55];
int go(int l, int r) {
    assert(l>=0 && r>=0);
    assert(l<n && r<n);
    int &ret = dp[l][r];
    if (ret != -1) {
        return ret;
    }
    if (l >= r) {
        ret = 0;
    } else {
        ret = go(l+1, r);
        ret = max(ret, go(l, r-1));
        if (C[l] == C[r]) {
            ret = max(ret, 1 + go(l+1, r-1));
        }
        for (int mid=l+1; mid<r; ++mid) {
            if (C[l] == C[mid]) {
                ret = max(ret, 1 + go(l+1, mid-1) + go(mid+1, r));
            }
        }
    }
    return ret;
}
class PenguinPals {
public:
    int findMaximumMatching(string colors) {
        C = colors;
        n = C.size();
        int sol = 0;
        for (int i=0; i<n; ++i) {
            memset(dp, 0xff, sizeof dp);
            sol = max(sol, go(0, n-1));
            C = C[n-1] + C.substr(0, n-1);
        }
        return sol;
    }
};
