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

int dp[55];
class SpellCards {
public:
    int maxDamage(vector <int> level, vector <int> damage) {
        memset(dp, 0, sizeof dp);
        int n = level.size();
        for (int i=0; i<n; ++i) {
            for (int j=n; j>=level[i]; --j) {
                dp[j] = max(dp[j], dp[j-level[i]] + damage[i]);
            }
        }
        return *max_element(dp, dp+n+1);
    }
};
