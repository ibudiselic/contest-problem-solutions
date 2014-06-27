//# wolves, dp, intervals
//# => Remember where the last wolf was placed and then check if we can skip another position with no wolves without braking any of the intervals.
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
#include <sstream>

using namespace std;

vector<int> ints(vector<string> &vs) {
    string s = accumulate(begin(vs), end(vs), string());
    istringstream is(s);
    vector<int> v;
    for (int x; is>>x;) v.push_back(x);
    return v;
}

const int mod = 1000000007;

vector<int> L, R;
vector<vector<int>> E;

int dp[305][305];
int n;
int go(int at, int last) {
    int &ret = dp[at][last+1];
    if (ret != -1) {
        return ret;
    }
    if (at == n) {
        ret = 1;
    } else {
        ret = go(at+1, at);
        bool can_skip = true;
        for (int i=0; i<(int)E[at].size(); ++i) {
            if (last < L[E[at][i]]) {
                can_skip = false;
                break;
            }
        }
        if (can_skip) {
            ret += go(at+1, last);
            if (ret >= mod) ret -= mod;
        }
    }
    return ret;
}
class WolfInZooDivTwo {
public:
    int count(int N, vector <string> L_, vector <string> R_) {
        n = N;
        L = ints(L_);
        R = ints(R_);
        int m = L.size();
        E.assign(N, vector<int>());
        for (int i=0; i<m; ++i) {
            E[R[i]].push_back(i);
        }
        memset(dp, 0xff, sizeof dp);
        return go(0, -1);
    }
};
