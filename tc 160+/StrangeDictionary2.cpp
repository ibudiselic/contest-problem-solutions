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

using namespace std;

int next_mask[1<<16][50];
int L, n;
int want;
int done[1<<16];
double dp[1<<16];
double go(int mask) {
    if (done[mask]) {
        return dp[mask];
    }
    done[mask] = 1;
    double &ret = dp[mask];
    
    if (mask == (1<<want)) {
        ret = 1.0;
    } else {
        ret = 0.0;
        if (mask & (1<<want)) {
            int nchoices = 0;
            for (int i=0; i<L; ++i) {
                if (next_mask[mask][i] != mask) {
                    ret += go(next_mask[mask][i]);
                    ++nchoices;
                }
            }
            if (nchoices) {
                ret /= nchoices;
            }
        }
    }

    return ret;
}
double calc(int k) {
    memset(done, 0, sizeof done);
    want = k;
    return go((1<<n)-1);
}
class StrangeDictionary2 {
public:
    vector <double> getProbabilities(vector <string> words) {
        L = words[0].size();
        n = words.size();

        for (int i=0; i<(1<<n); ++i) {
            for (int j=0; j<L; ++j) {
                int cur_min = 'z' + 1;
                int cur_next = 0;
                for (int k=0; k<n; ++k) {
                    if (i & (1<<k)) {
                        if (words[k][j] < cur_min) {
                            cur_min = words[k][j];
                            cur_next = (1<<k);
                        } else if (words[k][j] == cur_min) {
                            cur_next |= (1<<k);
                        }
                    }
                }
                next_mask[i][j] = cur_next;
            }
        }

        vector<double> sol;
        for (int i=0; i<n; ++i) {
            sol.push_back(calc(i));
        }
        return sol;
    }
};
