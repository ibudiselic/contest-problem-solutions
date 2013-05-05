#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

long long dp[650];
const long long mod = 1000000009;
class FleaCircus {
public:
    int countArrangements(vector <string> I_) {
        string input = accumulate(I_.begin(), I_.end(), string());
        istringstream is(input);
        vector<int> V;
        copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(V));

        int n = V.size();
        vector<int> done(n, 0);
        vector<int> len_cnt(n+1, 0);
        for (int i=0; i<n; ++i) {
            if (!done[i]) {
                int u = i;
                int len = 0;
                while (!done[u]) {
                    done[u] = 1;
                    ++len;
                    u = V[u];
                }
                ++len_cnt[len];
            }
        }

        vector<int> group_sz[2] = {};
        group_sz[0].push_back(4);
        group_sz[1].push_back(1);
        group_sz[1].push_back(2);
        group_sz[1].push_back(4);

        long long sol = 1;
        for (int len=1; len<=n; ++len) {
            int C = len_cnt[len];
            if (C == 0) {
                continue;
            }
            dp[0] = 1;
            for (int i=1; i<=C; ++i) {
                dp[i] = 0;
                for (int j=0; j<(int)group_sz[len&1].size(); ++j) {
                    int sz = group_sz[len&1][j];
                    if (sz > i) {
                        break;
                    }
                    long long ways = 1;
                    for (int k=1; k<sz; ++k) {
                        ways = ways*len*(i-k)%mod;
                    }
                    dp[i] = (dp[i] + ways*dp[i-sz])%mod;
                }
            }
            sol = sol*dp[C]%mod;
        }

        return int(sol);
    }
};
