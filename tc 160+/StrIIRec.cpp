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

int L[20];
int nL;
int N;

int cnt_invs(int c, int used) {
    int ret = 0;
    for (int i=c+1; i<N; ++i) {
        if (used & (1<<i)) {
            ++ret;
        }
    }
    return ret;
}

int dp[1<<20][2];
int max_invs(int i, int used, bool any) {
    int &ret = dp[used][any];
    if (ret != -1) {
        return ret;
    }
    if (i == N) {
        return 0;
    }

    if (i >= nL) {
        any = true;
    }
    ret = 0;
    for (int c=(any ? 0 : L[i]); c<N; ++c) {
        if (used & (1<<c)) {
            continue;
        }
        ret = max(ret, cnt_invs(c, used) + max_invs(i+1, used|(1<<c), any||(c>L[i])));
    }
    return ret;
}
class StrIIRec {
public:
    string recovstr(int n, int minInv, string minStr) {
        for (int i=0; i<(int)minStr.size(); ++i) {
            L[i] = minStr[i] - 'a';
        }
        nL = minStr.size();
        N = n;

        memset(dp, 0xff, sizeof dp);
        string sol(n, ' ');
        int invs = 0;
        int used = 0;
        bool any = false;
        for (int i=0; i<n; ++i) {
            if (i == nL) {
                any = true;
            }
            for (int c=(any ? 0 : L[i]); c<n; ++c) {
                if (used & (1<<c)) {
                    continue;
                }
                if (invs + cnt_invs(c, used) + max_invs(i+1, used|(1<<c), any||(c>L[i])) >= minInv) {
                    if (!any) {
                        any |= (c>L[i]);
                    }
                    invs += cnt_invs(c, used);
                    used |= 1<<c;
                    sol[i] = char('a'+c);
                    goto FOUND;
                }
            }
            return "";
            FOUND: ;
        }

        return sol;
    }
};
