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

using namespace std;

class FlippingBitsDiv1 {
public:
    int getmin(vector <string> S_, int M) {
        string s = accumulate(S_.begin(), S_.end(), string());
        int n = s.size();
        int sol = n;
        int ngroups = (n+M-1)/M;
        if (M <= ngroups) {
            for (int stripevals=0; stripevals<(1<<M); ++stripevals) {
                int flipped = 0;
                int nflipped = 0;
                for (int k=0; k<ngroups; ++k) {
                    int change = 0;
                    int nchange = 0;
                    for (int i=0; i<M && k*M+i<n; ++i) {
                        int want = (stripevals>>i)&1;
                        if (s[k*M+i]-'0' != want) {
                            ++change;
                        } else {
                            ++nchange;
                        }
                    }

                    int new_flipped = nchange + min(flipped, nflipped+1);
                    int new_nflipped = change + min(nflipped, flipped+1);
                    flipped = new_flipped;
                    nflipped = new_nflipped;
                }
                sol = min(sol, min(nflipped, flipped+1));
            }
        } else {
            for (int pattern=0; pattern<(1<<ngroups); ++pattern) {
                int pattern_cost = 0;
                int last = -1;
                vector< vector<int> > cnt(M, vector<int>(2, 0));
                for (int k=0; k<ngroups; ++k) {
                    int flipped = (pattern>>k)&1;
                    if (flipped != last) {
                        ++pattern_cost;
                        last = flipped;
                    }
                    for (int i=0; i<M && k*M+i<n; ++i) {
                        int bit = s[k*M+i]-'0';
                        if (flipped) bit = 1-bit;
                        ++cnt[i][bit];
                    }
                }
                pattern_cost += last;
                for (int i=0; i<M; ++i) {
                    pattern_cost += min(cnt[i][0], cnt[i][1]);
                }
                sol = min(sol, pattern_cost-1);
            }
        }
        return sol;
    }
};
