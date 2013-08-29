#include <algorithm>
#include <cassert>
#include <cctype>
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

const int inf = 987654321;
int dp[51][4];
class Stamp {
public:
    int getMinimumCost(string C_, int stampCost, int pushCost) {
        int sol = inf;
        int n = C_.size();
        vector<int> C(n);
        for (int i=0; i<(int)C_.size(); ++i) {
            switch (C_[i]) {
                case 'R': C[i] = 0; break;
                case 'G': C[i] = 1; break;
                case 'B': C[i] = 2; break;
                case '*': C[i] = 3; break;
            }
        }
        for (int L=1; L<=n; ++L) {
            for (int i=0; i<=n; ++i) {
                for (int j=0; j<4; ++j) {
                    dp[i][j] = inf;
                }
            }
            dp[0][0] = L*stampCost;
            for (int i=0; i<n; ++i) {
                for (int last=0; last<3; ++last) {
                    if (dp[i][last] >= sol) {
                        continue;
                    }
                    for (int next=0; next<3; ++next) {
                        for (int r=i; r<min(i+L, n); ++r) {
                            if (C[r]!=3 && C[r]!=next) {
                                break;
                            }
                            if (r-L+1>=0 && last==next) {
                                dp[r+1][next] = min(dp[r+1][next], dp[i][last] + pushCost);
                            }
                            if (r == i+L-1) {
                                dp[r+1][next] = min(dp[r+1][next], dp[i][last] + pushCost);
                            }
                        }
                    }
                }
            }
            for (int i=0; i<3; ++i) {
                sol = min(sol, dp[n][i]);
            }
        }
        return sol;
    }
};
