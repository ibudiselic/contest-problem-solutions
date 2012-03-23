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

int dp[52][51];
string S;
int go(int at, int prevlen) {
    int &ret = dp[at][prevlen];
    if (ret != -1) {
        return ret;
    }
    if (at == (int)S.size()) {
        return (ret = 0);
    }
    const string prev = S.substr(at-prevlen, prevlen);
    ret = -123;
    for (int len=1; at+len<=(int)S.size(); ++len) {
        const string tmp = S.substr(at, len);
        if (tmp+prev < prev+tmp) {
            continue;
        }
        ret = max(ret, 1 + go(at+len, len));
    }
    return ret;
}
class MagicNaming {
public:
    int maxReindeers(string magicName) {
        S = string(1, 'a'-1) + magicName;
        memset(dp, 0xff, sizeof dp);
        return go(1, 1);
    }
};
