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
#include <set>
#include <map>

using namespace std;

int dp[2][1<<15];
class RelativelyPrimeSubset {
public:
    int findSize(vector <int> S) {
        int sol = 0;
        set<int> P;
        vector<int> nums;
        vector< vector<int> > decomps;
        for (int i=0; i<(int)S.size(); ++i) {
            if (S[i] == 1) {
                ++sol;
                continue;
            }
            vector<int> p;
            int x = S[i];
            for (int d=2; d*d<=x; ++d) {
                if (x%d == 0) {
                    p.push_back(d);
                    do {
                        x /= d;
                    } while (x%d == 0);
                }
            }
            if (x > 1) {
                if (x > 50) {
                    ++sol;
                    continue;
                }
                p.push_back(x);
            }

            nums.push_back(S[i]);
            decomps.push_back(p);
            for (int j=0; j<(int)p.size(); ++j) {
                P.insert(p[j]);
            }
        }
        map<int, int> primes;
        int np = 0;
        for (set<int>::const_iterator it=P.begin(); it!=P.end(); ++it) {
            primes[*it] = np++;
        }

        for (int i=0; i<(int)nums.size(); ++i) {
            int mask = 0;
            for (int j=0; j<(int)decomps[i].size(); ++j) {
                mask |= 1<<primes[decomps[i][j]];
            }
            nums[i] = mask;
        }

        memset(dp[1], 0, sizeof dp[1]);
        for (int i=0; i<(int)nums.size(); ++i) {
            for (int mask=0; mask<(1<<15); ++mask) {
                dp[i&1][mask] = dp[(i+1)&1][mask];
                if ((mask&nums[i]) == nums[i]) {
                    dp[i&1][mask] = max(dp[i&1][mask], 1+dp[(i+1)&1][mask^nums[i]]);
                }
            }
        }
        int best = 0;
        for (int mask=0; mask<(1<<15); ++mask) {
            best = max(best, dp[(nums.size()+1)&1][mask]);
        }
        return sol + best;
    }
};
