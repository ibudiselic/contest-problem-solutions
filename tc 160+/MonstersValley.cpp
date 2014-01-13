//# dp, simple dp
//# => compute maximum total dread that can be achieved for a price p after visiting the first i monsters
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

const int MAXN = 55;
long long dp[MAXN][2*MAXN];
inline void maximize(long long &a, long long b) {
    a = max(a, b);
}
class MonstersValley {
public:
    int minimumPrice(vector<long long> dread, vector <int> price) {
        int n = dread.size();
        memset(dp, 0xff, sizeof dp);
        dp[0][0] = 0;
        for (int i=0; i<n; ++i) {
            for (int p=0; p<=2*n; ++p) {
                if (dp[i][p] >= 0) {
                    maximize(dp[i+1][p+price[i]], dp[i][p]+dread[i]);
                    if (dp[i][p] >= dread[i]) {
                        maximize(dp[i+1][p], dp[i][p]);
                    }
                }
            }
        }

        for (int p=0; p<=2*n; ++p) {
            if (dp[n][p] >= 0) {
                return p;
            }
        }
        return -1;
    }
};
