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

bool G[50][50];
bool vis[50];
int n;
bool dfs(int u, int v) {
    vis[u] = 1;
    if (u == v) {
        return true;
    }
    for (int i=0; i<n; ++i) {
        if (!vis[i] && G[u][i] && dfs(i, v)) {
            return true;
        }
    }
    return false;
}
bool can(int u, int v) {
    memset(vis, 0, sizeof vis);
    return dfs(u, v);
}
bool good[50];
class GogoXReimuHakurai {
public:
    int solve(vector <string> choices) {
        n = choices.size();
        if (n == 2) {
            return choices[0][1]=='Y' ? 1 : 0;
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (choices[i][j] == 'Y');
            }
        }
        
        int a = 0;
        int b = 0;
        for (int i=n-1; i>=0; --i) {
            good[i] = can(0, i) && can(i, n-1);
            if (good[i]) {
                ++a;
                for (int j=i+1; j<n; ++j) {
                    if (good[j] && G[i][j]) {
                        ++b;
                    }
                }
            }
        }
        
        if (!good[0] || !good[n-1]) {
            return 0;
        }
        return b - a + 2;
    }
};
