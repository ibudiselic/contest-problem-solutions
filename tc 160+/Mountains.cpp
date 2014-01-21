//# dp, mountains, counting
//# => turns out the fairly trivial dp works as the number of states is actually much lower than it seems because of the simple shape of the mountains... basically process the mountains in reverse order keeping the current state of the picture (it's sufficient to just store the highest point of any mountain and mountains on the picture don't need to be destinguished)... then pick any possible column for the mountain's peak and see if it could be there + recurse on the earlier mountains
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

using namespace std;

vector<int> H;
vector<string> V;
int n, W;
const int mod = 1000000009;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}

typedef pair<int, vector<int> > state_t;
map<state_t, int> dp;
int go(int at, vector<int> &cur) {
    const state_t key(at, cur);
    if (dp.count(key)) {
        return dp[key];
    }
    vector<int> restore(W);
    int &ret = dp[key];
    if (at == n) {
        ret = 1;
    } else {
        ret = 0;
        for (int i=0; i<W; ++i) {
            bool ok = true;
            for (int j=0; j<W; ++j) {
                int h = max(0, H[at] - abs(i-j));
                if ((cur[j]>=h && V[at][j]=='X') || (cur[j]<h && V[at][j]=='-')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int j=max(0, i-H[at]+1); j<min(W, i+H[at]); ++j) {
                restore[j] = cur[j];
                int h = H[at] - abs(i-j);
                cur[j] = max(cur[j], h);
            }
            ret = modadd(ret, go(at+1, cur));
            for (int j=max(0, i-H[at]+1); j<min(W, i+H[at]); ++j) {
                cur[j] = restore[j];
            }
        }
    }
    return ret;
}
class Mountains {
public:
    int countPlacements(vector <int> heights, vector <string> visibility) {
        n = heights.size();
        H = heights;
        V = visibility;
        reverse(H.begin(), H.end());
        reverse(V.begin(), V.end());
        W = V[0].size();
        vector<int> cur(W, 0);
        dp.clear();
        return go(0, cur);
    }
};
