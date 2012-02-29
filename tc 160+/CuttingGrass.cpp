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

struct blade {
    int init, grow;
    blade(int init_, int grow_): init(init_), grow(grow_) {}
};
struct by_grow {
    bool operator()(const blade &a, const blade &b) {
        if (a.grow != b.grow) {
            return a.grow < b.grow;
        } else {
            return a.init > b.init;
        }
    }
};

int by;
int T;
vector<blade> G;
bool done[51][51];
int dp[51][51];
int go(int at, int t) {
    if (done[at][t]) {
        return dp[at][t];
    }
    done[at][t] = 1;
    int &ret = dp[at][t];
    if (t==T || at==(int)G.size()) {
        ret = 0;
    } else {
        ret = max(G[at].init+(t+1)*G[at].grow + go(at+1, t+1),
                  go(at+1, t));
    }
    return ret;
}
class CuttingGrass {
public:
    int theMin(vector<int> init, vector<int> grow, int H) {
        const int n = init.size();
        G.clear();
        for (int i=0; i<n; ++i) {
            G.push_back(blade(init[i], grow[i]));
        }
        sort(G.begin(), G.end(), by_grow());
        
        by = 0;
        int cur = 0;
        for (int i=0; i<n; ++i) {
            cur += G[i].init;
            by += G[i].grow;
        }
        for (T=0; T<=n; ++T) {
            memset(done, 0, sizeof done);
            if (cur+T*by - go(0, 0) <= H) {
                return T;
            }
        }
        
        return -1;
    }
};
