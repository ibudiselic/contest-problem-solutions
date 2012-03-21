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

string lim;
int my_abs(int x) { return x<0 ? -x : x; }
long long dp[12][12][12][2];
long long go(int dig, int fours, int sevens, bool any) {
    long long &ret = dp[dig][fours][sevens][any];
    if (ret != -1) {
        return ret;
    }
    if (dig == (int)lim.size()) {
        return (ret = my_abs(fours-sevens));
    }
    ret = 0;
    for (int d=0; d<=(any?9:lim[dig]-'0'); ++d) {
        ret += go(dig+1, fours+(d==4), sevens+(d==7), any || d<lim[dig]-'0');
    }
    return ret;
}
long long calc(int x) {
    ostringstream os;
    os << x;
    lim = os.str();
    memset(dp, 0xff, sizeof dp);
    return go(0, 0, 0, 0);
}
class SumOfLuckiness {
public:
    long long theSum(int A, int B) {
        return calc(B) - calc(A-1);
    }
};
