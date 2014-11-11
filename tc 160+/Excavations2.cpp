//# dp, medium dp, excavations, depth, digging, artefacts
//# => See the div1 version, the logic is similar except that in the div2 version there are no depths.
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

long long dp[2][55][2];
class Excavations2 {
public:
    long long count(vector <int> kind_, vector <int> found_, int K) {
        vector<int> found(55);
        for (auto f : found_) found[f] = 1;
        vector<int> kind;
        for (int k : kind_) if (found[k]) kind.push_back(k);
        sort(begin(kind), end(kind));
        kind.push_back(55);
        int n = kind.size();

        memset(dp, 0, sizeof dp);
        dp[(n+1)&1][0][1] = 1;
        for (int i=n-2; i>=0; --i) {
            int cur = i&1;
            int prev = 1-cur;
            for (int k=0; k<=K; ++k) {
                if (kind[i] != kind[i+1]) {
                    dp[cur][k][0] = dp[prev][k][1];
                    if (k > 0) dp[cur][k][1] = dp[prev][k-1][1];
                    else dp[cur][k][1] = 0;
                } else {
                    dp[cur][k][0] = dp[prev][k][0];
                    dp[cur][k][1] = dp[prev][k][1];
                    if (k > 0) dp[cur][k][1] += dp[prev][k-1][0] + dp[prev][k-1][1];
                }
            }
        }
        return dp[0][K][1];
    }
};
