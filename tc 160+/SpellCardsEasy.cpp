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

vector<int> L, D;
const int inf = 987654321;
int dp[55][55];
int go(int at, int need) {
    if ((int)L.size()-at < need) {
        return -inf;
    }
    int &ret = dp[at][need];
    if (ret != -1) {
        return ret;
    }
    if (at >= (int)L.size()) {
        ret = (need==0 ? 0 : -inf);
    } else {
        ret = go(at+1, max(0, need-1));
        ret = max(ret, go(at+1, need + L[at] - 1) + D[at]);
    }
    return ret;
}
class SpellCardsEasy {
public:
    int maxDamage(vector <int> level, vector <int> damage) {
        L = level;
        D = damage;
        memset(dp, 0xff, sizeof dp);
        return go(0, 0);
    }
};
