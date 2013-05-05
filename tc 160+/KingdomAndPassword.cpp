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

vector<int> R;
string P;
long long inf = 12345678912345678LL;
long long p10[16];
bool done[17][1<<16][2];
long long dp[17][1<<16][2];
int take[17][1<<16][2];
long long above(int at, int used, bool diff) {
    long long &ret = dp[at][used][diff];
    if (done[at][used][diff]) {
        return ret;
    }
    done[at][used][diff] = 1;
    if (at == (int)P.size()) {
        return (ret = 0);
    }
    ret = inf;
    bool tried[10] = {0};
    tried[R[at]] = 1;
    int at_dig = P[at] - '0';
    for (int i=0; i<(int)R.size(); ++i) {
        if (used & (1<<i)) continue;
        int dig = P[i] - '0';
        if (!tried[dig] && (diff || dig>=at_dig)) {
            tried[dig] = 1;
            long long cand = (dig-at_dig)*p10[at] + above(at+1, used|(1<<i), diff||(dig>at_dig));
            if (cand < ret) {
                ret = cand;
                take[at][used][diff] = i;
            }
        }
    }
    return ret;
}
long long below(int at, int used, bool diff) {
    long long &ret = dp[at][used][diff];
    if (done[at][used][diff]) {
        return ret;
    }
    done[at][used][diff] = 1;
    if (at == (int)P.size()) {
        return (ret = 0);
    }
    ret = -inf;
    bool tried[10] = {0};
    tried[R[at]] = 1;
    int at_dig = P[at] - '0';
    for (int i=0; i<(int)R.size(); ++i) {
        if (used & (1<<i)) continue;
        int dig = P[i] - '0';
        if (!tried[dig] && (diff || dig<=at_dig)) {
            tried[dig] = 1;
            long long cand = (dig-at_dig)*p10[at] + below(at+1, used|(1<<i), diff||(dig<at_dig));
            if (cand > ret) {
                ret = cand;
                take[at][used][diff] = i;
            }
        }
    }
    return ret;
}
long long reconstruct() {
    int used = 0;
    bool diff = false;
    long long ret = 0;
    for (int i=0; i<(int)P.size(); ++i) {
        int t = take[i][used][diff];
        ret = 10*ret + (P[t]-'0');
        if (!diff && P[t]!=P[i]) {
            diff = 1;
        }
        used |= 1<<t;
    }
    return ret;
}
class KingdomAndPassword {
public:
    long long newPassword(long long P, vector <int> R) {
        ::R = R;
        ostringstream os;
        os << P;
        ::P = os.str();
        p10[::P.size()-1] = 1;
        for (int i=(int)::P.size()-2; i>=0; --i) {
            p10[i] = p10[i+1]*10;
        }

        memset(done, 0, sizeof done);
        long long cand1 = -1;
        if (above(0, 0, 0) < inf) {
            cand1 = reconstruct();
        }
        memset(done, 0, sizeof done);
        long long cand2 = -1;
        if (below(0, 0, 0) > -inf) {
            cand2 = reconstruct();
        }
        if (cand1==-1 && cand2==-1) {
            return -1;
        } else if (cand1 == -1) {
            return cand2;
        } else if (cand2 == -1) {
            return cand1;
        } else {
            return cand1-P < P-cand2 ? cand1 : cand2;
        }
    }
};
