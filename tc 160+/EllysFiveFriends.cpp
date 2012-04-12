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
#include <map>

using namespace std;

const int mod = 1000000007;
bool done(const vector<int> &v) {
    for (int i=4; i>=0; --i) {
        if (v[i] != 0) {
            return false;
        }
    }
    return true;
}
int ndivs[10001];
bool impossible(const vector<int> &v) {
    for (int i=0; i<5; ++i) {
        int prev = i - 1;
        if (prev < 0) prev = 4;
        int next = i + 1;
        if (next > 4) next = 0;
        if (ndivs[v[prev]] + ndivs[v[next]] < ndivs[v[i]]) {
            return true;
        }
    }
    return false;
}
int dp[14348907];
int go(vector<int> &v) {
    int state = 0;
    for (int i=0; i<5; ++i) {
        int repr = 0;
        int t = v[i];
        while (t > 0) {
            repr += 1 + (t&1);
            t >>= 1;
        }
        assert(repr < 27);
        state = state*27 + repr;
    }
    if (dp[state] != -1) {
        return dp[state];
    }
    int ret = 0;
    if (done(v)) {
        ret = 1;
    } else if (impossible(v)) {
        ret = 0;
    } else {
        for (int i=0; i<5; ++i) {
            int j = (i+1)%5;
            int cur = v[i];
            int next = v[j];
            if (next == 0) {
                ++i;
                continue;
            }
            if (cur == 0) {
                continue;
            }
            if ((cur&1) && (next&1)) {
                --v[i];
                --v[j];
                ret += go(v);
                if (ret >= mod) {
                    ret -= mod;
                }
                ++v[i];
                ++v[j];
            }
            v[i] /= 2;
            v[j] /= 2;
            ret += go(v);
            if (ret >= mod) {
                ret -= mod;
            }
            v[i] = cur;
            v[j] = next;
        }
    }
    dp[state] = ret;
    return ret;
}
class EllysFiveFriends {
public:
    int getZero(vector <int> numbers) {
        ndivs[0] = 0;
        ndivs[1] = 1;
        for (int i=2; i<=10000; ++i) {
            ndivs[i] = ndivs[i/2] + 1;
        }
        memset(dp, 0xff, sizeof dp);
        return go(numbers);
    }
};
