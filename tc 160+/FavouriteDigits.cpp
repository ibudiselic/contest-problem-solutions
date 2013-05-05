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

string S;
int D1, D2;
int dp[20][16][16][2][2];
int get_dig(int i, int c1, int c2, bool any, bool zero) {
    int &ret = dp[i][c1][c2][any][zero];
    if (ret != -1) {
        return ret;
    }
    if (i == (int)S.size()) {
        ret = (c1==0 && c2==0) ? 0 : -2;
        return ret;
    }
    for (ret=(any?0:S[i]-'0'); ret<10; ++ret) {
        int nc1 = c1;
        int nc2 = c2;
        if (!zero || D1!=0) nc1 = max(0, nc1-(ret==D1));
        if (!zero || D2!=0) nc2 = max(0, nc2-(ret==D2));
        int next = get_dig(i+1, nc1, nc2, any||(ret>S[i]-'0'), zero&&(ret==0));
        if (next != -2) {
            return ret;
        }
    }

    ret = -2;
    return ret;
}
class FavouriteDigits {
public:
    long long findNext(long long N, int digit1, int count1, int digit2, int count2) {
        {
            ostringstream os;
            os << N;
            S = os.str();
            if (S.size() < 16) {
                S = string(16-S.size(), '0') + S;
            }
        }
        D1 = digit1;
        D2 = digit2;
        bool any = false;
        long long sol = 0;
        memset(dp, 0xff, sizeof dp);
        for (int i=0; i<16; ++i) {
            int d = get_dig(i, count1, count2, any, sol==0);
            if (sol>0 || D1!=0) count1 = max(0, count1-(d==D1));
            if (sol>0 || D2!=0) count2 = max(0, count2-(d==D2));
            any = any || (d>S[i]-'0');
            sol = sol*10 + d;
        }

        return sol;
    }
};
