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
#include <numeric>

using namespace std;

map<int, int> T;
int L, R;
int n;
long long pick_mask[50];

int cnt_sets[50];
int bc(long long x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
long long go(int at, int cnt, long long mask) {
    if (mask == 0) {
        return 0;
    }
    if (at == n) {
        if (cnt == 0) return 0;
        ++cnt_sets[cnt];
        return ((cnt&1) ? +1 : -1)*(1ll<<bc(mask));
    }
    long long ret = go(at+1, cnt, mask);
    if (pick_mask[at] != -1) {
        ret += go(at+1, cnt+1, mask&pick_mask[at]);
    }
    return ret;
}

long long C[37][37];
class MapGuessing {
public:
    long long countPatterns(string goal, vector <string> code_) {
        n = goal.size();
        L = R = 0;
        T.clear();
        int at = 0;

        memset(pick_mask, 0, sizeof pick_mask);
        string code = accumulate(code_.begin(), code_.end(), string());
        for (int j=0; j<(int)code.size(); ++j) {
            switch (code[j]) {
                case '<': --at; break;
                case '>': ++at; break;
                case '0': T[at] = 0; break;
                case '1': T[at] = 1; break;
                default: assert(0);
            }
            L = min(L, at);
            R = max(R, at);
            for (int i=0; i<n; ++i) {
                if (i+L<0 || i+R>=n) {
                    pick_mask[i] = -1;
                    continue;
                }
                long long mask = 0;
                for (map<int, int>::const_iterator it=T.begin(); it!=T.end(); ++it) {
                    assert(i + it->first >= 0);
                    assert(i + it->first < n);
                    if (goal[i+it->first]-'0' != it->second) {
                        mask = -1;
                        break;
                    }
                    mask |= 1ll << (i+it->first);
                }
                if (mask != -1) {
                    pick_mask[i] = mask;
                }
            }
        }

        memset(cnt_sets, 0, sizeof cnt_sets);
        long long sol = go(0, 0, (1ll<<n)-1);

        C[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }

        int active = 0;
        for (int i=0; i<n; ++i) {
            if (pick_mask[i] != -1) {
                ++active;
            }
        }
        for (int i=1; i<=active; ++i) {
            sol += ((i&1) ? +1 : -1) * (C[active][i]-cnt_sets[i]);
        }

        return sol;
    }
};
