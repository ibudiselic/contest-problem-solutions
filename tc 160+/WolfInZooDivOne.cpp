//# wolves, dp, intervals
//# => Whenever we put a wolf somewhere, remember the rightmost point we need to jump to with no wolves if we put another wolf before that point (that rightmost point is the right endpoint of some interval that contains the wolf we're just placing).
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

vector<int> process(const vector<string> &v) {
    string s = accumulate(begin(v), end(v), string());
    istringstream is(s);
    vector<int> ret;
    for (int x; is>>x; ) ret.push_back(x);
    return ret;
}
const int MAXN = 300+5;
int pos_to[MAXN];
int n;
int dp[MAXN][MAXN];

const int mod = 1000000007;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
int go(int at, int to) {
    to = max(to, at+1);
    int &ret = dp[at][to];
    if (ret != -1) {
        return ret;
    }
    if (at == n) {
        ret = 1;
    } else {
        ret = modadd(go(at+1, to), go(to, pos_to[at]));
    }
    return ret;
}
class WolfInZooDivOne {
public:
    int count(int N, vector <string> L, vector <string> R) {
        vector<int> left = process(L);
        vector<int> right = process(R);
        
        n = N;
        int numint = left.size();
        for (int i=0; i<n; ++i) {
            pos_to[i] = -1;
            for (int j=0; j<numint; ++j) {
                if (left[j]<=i && i<=right[j]) {
                    pos_to[i] = max(pos_to[i], right[j] + 1);
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        return go(0, 0);
    }
};
