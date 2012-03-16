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

vector<int> C;
vector<int> vis;
bool dfs(int u) {
    vis[u] = true;
    for (int i=0; i<(int)C.size(); ++i) {
        if (u+C[i]<0 || u+C[i]>=(int)vis.size()) {
           continue;
        }
        if (u+C[i]==0 || (!vis[u+C[i]] && dfs(u+C[i]))) {
            return true;
        }
    }
    return false;
}
bool ok(int len) {
    vis.assign(len+1, 0);
    return !dfs(0);
}
class LongestSequence {
public:
    int maxLength(vector <int> C_) {
        C = C_;
        int lo = 0;
        int hi = 1;
        while (ok(hi)) {
            if (hi > 10000) {
                return -1;
            }
            lo = hi;
            hi *= 2;
        }
        while (lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            if (ok(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
