//# traffic, tree, dp
//# => Notice that it is always optimal to use the first car to go from the leftmost leaf to the rightmost leaf through the root. This leads to a simple recurrence.
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

const int mod = 1000000007;
inline int modadd(int a, int b) {
    a += b;
    return a >= mod ? a-mod : a;
}
const int MAXHEIGHT = 1000000+2;
int dp[MAXHEIGHT];
class TrafficCongestion {
public:
    int theMinCars(int treeHeight) {
        if (treeHeight == 0) return 1;
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2; i<=treeHeight; ++i) {
            dp[i] = modadd(dp[i-2], dp[i-2]);
            dp[i] = modadd(dp[i], 1);
            dp[i] = modadd(dp[i], dp[i-1]);
        }
        return modadd(dp[treeHeight], mod-dp[treeHeight-1]);
    }
};
