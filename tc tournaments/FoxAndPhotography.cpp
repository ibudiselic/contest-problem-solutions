#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> F, B;
int dp[16][1<<16];
const int inf = 12345678;
int go(int at, int used) {
    if (at == (int)F.size()) {
        return 0;
    }
    int &ret = dp[at][used];
    if (ret != -1) {
        return ret;
    }
    ret = inf;
    int swaps = 0;
    for (int i=0; i<(int)F.size(); ++i) {
        if (!(used & (1<<i))) {
            if (F[i] < B[at]) {
                ret = min(ret, swaps + go(at+1, used | (1<<i)));
            }
            ++swaps;
        }
    }
    return ret;
}
class FoxAndPhotography {
public:
    int getMinimumSwaps(vector <int> heightsFront, vector <int> heightsBack) {
        F = heightsFront;
        B = heightsBack;
        memset(dp, 0xff, sizeof dp);
        int t = go(0, 0);
        return t==inf ? -1 : t;
    }
};
