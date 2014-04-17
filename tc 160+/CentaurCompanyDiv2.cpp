//# tree, dp, newtork, company
//# => Fix the highest index node in the component and just do a simple tree dp.
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

int n;
vector<vector<int>> G;
int R;
long long dp[55][55];
long long ways(int u, int p) {
    long long &ret = dp[u][p];
    if (ret != -1) {
        return ret;
    }
    ret = (u!=R);
    if (u <= R) {
        long long add = 1;
        for (int i=0; i<(int)G[u].size(); ++i) {
            int v = G[u][i];
            if (v != p) add *= ways(v, u);
        }
        ret += add;
    }
    return ret;
}
class CentaurCompanyDiv2 {
public:
    long long count(vector <int> a, vector <int> b) {
        n = a.size() + 1;
        G.assign(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            G[a[i]-1].push_back(b[i]-1);
            G[b[i]-1].push_back(a[i]-1);
        }
        long long sol = 1;
        for (R=0; R<n; ++R) {
            memset(dp, 0xff, sizeof dp);
            sol += ways(R, n);
        }
        return sol;
    }
};
