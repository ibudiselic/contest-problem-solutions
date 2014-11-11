//# trees, lamps, flips, paths, dp, greedy
//# => Pretty standard tree dp... supposedly, greedily picking paths with the largest number of edges that need to be flipped is also correct. It is easy to see that no edge needs more than one path passing through it.
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

using pii = pair<int, int>;
vector<vector<pii>> G;
int n;
string init, imp;

int dp[51][51][51][51];
int go(int u, int p, int start, int cnt) {
    if (cnt > n) return 123456;
    if (start<(int)G[u].size() && G[u][start].first==p) {
        ++start;
    }

    int &ret = dp[u][p][start][cnt];
    if (ret != -1) {
        return ret;
    }

    if (start == (int)G[u].size()) {
        ret = 0;
    } else {
        int v = G[u][start].first;
        int eidx = G[u][start].second;
        bool mustFlip = (imp[eidx]=='1')&&(init[eidx]=='0');
        bool canFlip = (imp[eidx]=='0')||(init[eidx]=='0');
        ret = 123456;
        for (int cont=0; cont<=cnt; ++cont) {
            for (int extra=0; extra<=2; ++extra) {
                int have = cont+extra;
                if ((have&1)==0 && mustFlip) continue;
                if ((have&1) && !canFlip) continue;
                ret = min(ret, extra + go(v, u, 0, have) + go(u, p, start+1, cnt-cont+extra));
            }
        }
    }
    return ret;
}
class TurnOnLamps {
public:
    int minimize(vector <int> roads, string initState, string isImportant) {
        init = initState;
        imp = isImportant;
        n = roads.size() + 1;
        G.assign(n, vector<pii>());
        for (int i=1; i<n; ++i) {
            int a = roads[i-1];
            int b = i;
            G[a].push_back(pii(b, i-1));
            G[b].push_back(pii(a, i-1));
        }

        memset(dp, 0xff, sizeof dp);
        return go(0, n, 0, 0);
    }
};
