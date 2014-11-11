//# traffic, tree, dp
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

long long dp[123];
class TrafficCongestionDivTwo {
public:
    long long theMinCars(int H) {
        dp[0] = 1;
        dp[1] = 1;
        long long tot = 1;
        for (int h=2; h<=H; ++h) {
            dp[h] = 1 + 2*tot;
            tot += dp[h-1];
        }
        return dp[H];
    }
};
