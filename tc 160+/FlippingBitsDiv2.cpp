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

int solve(const string &s, int M) {
    int n = s.size();
    int flipped = 0;
    int nflipped = 0;
    for (int k=0; k*M<n; ++k) {
        int cnt = 0;
        for (int i=0; i<M; ++i) {
            if (s[k*M+i] == '1') {
                ++cnt;
            }
        }
        int new_flipped = cnt + min(flipped, nflipped+1);
        int new_nflipped = M-cnt + min(nflipped, flipped+1);
        flipped = new_flipped;
        nflipped = new_nflipped;
    }

    return min(nflipped, flipped+1);
}
class FlippingBitsDiv2 {
public:
    int getmin(vector <string> S_, int M) {
        string s = accumulate(S_.begin(), S_.end(), string());
        int n = s.size();
        int sol = n;
        for (int split=1; split*M<=n; ++split) {
            int cand = solve(s.substr(0, split*M), M);
            if (split*M < n) {
                string rest = s.substr(split*M);
                reverse(rest.begin(), rest.end());
                cand += solve(rest, M);
            }
            sol = min(sol, cand);
        }
        return sol;
    }
};
