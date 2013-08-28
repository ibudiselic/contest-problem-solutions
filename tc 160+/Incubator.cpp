#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool G[50][50];
bool cG[50][50];
bool loop[50];
int C[50];
void tarjan_(int i, int n, int &dfscnt, vector<int> &idx, vector<int> &low, vector<int> &stack, vector<char> &in_stack, vector< vector<int> > &comps) {
    idx[i] = low[i] = dfscnt++;
    stack.push_back(i);
    in_stack[i] = 1;
    for (int j=0; j<n; ++j) {
        if (G[i][j]) {
            if (idx[j] == -1) {
                tarjan_(j, n, dfscnt, idx, low, stack, in_stack, comps);
            }
            if (in_stack[j]) {
                low[i] = min(low[i], low[j]);
            }
        }
    }

    if (low[i] == idx[i]) {
        vector<int> comp;
        while (1) {
            int x = stack.back();
            C[x] = int(comps.size());
            stack.pop_back();
            in_stack[x] = 0;
            comp.push_back(x);
            if (x == i) {
                break;
            }
        }
        comps.push_back(comp);
    }
}
void tarjan(int n, vector<vector<int> > &comps) {
    vector<int> idx(n, -1);
    vector<int> low(n, -1);
    vector<int> stack;
    vector<char> in_stack(n, 0);
    int dfscnt = 0;
    for (int i=0; i<n; ++i) {
        if (idx[i] == -1) {
            tarjan_(i, n, dfscnt, idx, low, stack, in_stack, comps);
        }
    }
}

int match[50], rmatch[50], vis[50];
int can_match(int u, const vector<int> &active, int token) {
    vis[u] = token;
    for (int i=0; i<(int)active.size(); ++i) {
        int v = active[i];
        if (cG[u][v] && (rmatch[v]==-1 || (vis[rmatch[v]]!=token && can_match(rmatch[v], active, token)))) {
            match[u] = v;
            rmatch[v] = u;
            return 1;
        }
    }
    return 0;
}
int maxmatch(const vector<int> &active) {
    fill(match, match+50, -1);
    fill(rmatch, rmatch+50, -1);
    fill(vis, vis+50, -1);

    int sz = 0;
    for (int j=0; j<(int)active.size(); ++j) {
        int i = active[j];
        if (match[i] == -1) {
            sz += can_match(i, active, i);
        }
    }
    return sz;
}
class Incubator {
public:
    int maxMagicalGirls(vector <string> love) {
        memset(G, 0, sizeof G);
        int n = love.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (love[i][j]=='Y');
            }
            loop[i] = (love[i][i]=='Y');
        }

        vector< vector<int> > comps;
        tarjan(n, comps);

        memset(cG, 0, sizeof cG);
        int nc = comps.size();
        for (int i=0; i<nc; ++i) {
            for (int j=0; j<nc; ++j) {
                if (i == j) continue;
                for (int a=0; a<(int)comps[i].size(); ++a) {
                    for (int b=0; b<(int)comps[j].size(); ++b) {
                        if (G[comps[i][a]][comps[j][b]]) {
                            cG[i][j] = 1;
                        }
                    }
                }
            }
        }
        for (int k=0; k<nc; ++k) {
            for (int i=0; i<nc; ++i) {
                for (int j=0; j<nc; ++j) {
                    cG[i][j] |= cG[i][k]&&cG[k][j];
                }
            }
        }
        vector<int> active;
        for (int i=0; i<nc; ++i) {
            if (comps[i].size()==1 && !loop[comps[i][0]]) {
                active.push_back(i);
            }
        }

        return int(active.size()) - maxmatch(active);
    }
};
