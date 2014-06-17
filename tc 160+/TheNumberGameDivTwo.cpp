//# game, impartial game, divisors, dp, easy dp
//# => trivial
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

int dp[1001];
int go(int n) {
    int &ret = dp[n];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i=2; i<n; ++i) {
        if (n%i==0 && !go(n-i)) {
            ret = 1;
            break;
        }
    }
    return ret;
}
class TheNumberGameDivTwo {
public:
    string find(int n) {
        memset(dp, 0xff, sizeof dp);
        return go(n) ? "John" : "Brus";
    }
};
