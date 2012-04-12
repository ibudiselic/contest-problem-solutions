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
#include <numeric>

using namespace std;

string S, T;
int n;
int dp[2500][26][26];
int go(int i, int s, int t) {
    if (i == n) {
        return 0;
    }
    int &ret = dp[i][s][t];
    if (ret != -1) {
        return ret;
    }
    ret = (s!=t) + go(i+1, S[i+1]-'a', T[i+1]-'a');
    if (i+1 < n) {
        ret = min(ret, 1 + (S[i+1]-'a'!=t) + go(i+1, s, T[i+1]-'a'));
        ret = min(ret, 1 + (s!=T[i+1]-'a') + go(i+1, S[i+1]-'a', t));
    }
    return ret;
}
class EllysString {
public:
    int theMin(vector <string> s, vector <string> t) {
        S = accumulate(s.begin(), s.end(), string());
        T = accumulate(t.begin(), t.end(), string());
        n = S.size();
        S += 'a';
        T += 'a';

        memset(dp, 0xff, sizeof dp);
        return go(0, S[0]-'a', T[0]-'a');
    }
};
