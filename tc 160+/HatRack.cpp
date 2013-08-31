#include <algorithm>
#include <cassert>
#include <cctype>
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

vector< vector<int> > T;
int L[51];
int comp_l(int u, int p) {
    int ret = L[u];
    for (int i=0; i<(int)T[u].size(); ++i) {
        int v = T[u][i];
        if (v != p) {
            L[v] = L[u]+1;
            ret = max(ret, comp_l(v, u));
        }
    }
    return ret;
}

int dp[51][3];
enum {
    EMPTY, INCOMPLETE, COMPLETE
};

int maxlevel;
int go(int u, int p, int kind) {
    int &ret = dp[u][kind];
    if (ret != -1) {
        return ret;
    }
    int ccnt = 0;
    for (int i=0; i<(int)T[u].size(); ++i) {
        if (T[u][i] != p) {
            ++ccnt;
        }
    }
    if (ccnt > 2) {
        ret = 0;
    } else if (L[u] == maxlevel) {
        ret = 1;
    } else if (L[u] == maxlevel-1) {
        if (kind == EMPTY) {
            ret = (ccnt==0);
        } else if (kind == INCOMPLETE) {
            ret = (ccnt==1);
        } else {
            ret = 2*(ccnt==2);
        }
    } else if (ccnt < 2) {
        ret = 0;
    } else {
        int c1=-1, c2=-1;
        ret = 0;
        for (int i=0; i<int(T[u].size()); ++i) {
            if (T[u][i] != p) {
                if (c1 == -1) {
                    c1 = T[u][i];
                } else {
                    c2 = T[u][i];
                }
            }
        }
        assert(c1!=-1 && c2!=-1);
        if (kind == EMPTY) {
            ret = 2*go(c1, u, EMPTY)*go(c2, u, EMPTY);
        } else if (kind == INCOMPLETE) {
            for (int order=0; order<2; ++order) {
                ret += go(c1, u, INCOMPLETE)*go(c2, u, EMPTY);
                ret += go(c1, u, COMPLETE)*go(c2, u, INCOMPLETE);
                ret += go(c1, u, COMPLETE)*go(c2, u, EMPTY);
                swap(c1, c2);
            }
        } else {
            for (int order=0; order<2; ++order) {
                ret += go(c1, u, COMPLETE)*go(c2, u, COMPLETE);
                swap(c1, c2);
            }
        }
    }

    return ret;
}
class HatRack {
public:
    long long countWays(vector <int> knob1, vector <int> knob2) {
        int n = knob1.size() + 1;
        T.assign(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            T[knob1[i]-1].push_back(knob2[i]-1);
            T[knob2[i]-1].push_back(knob1[i]-1);
        }

        long long sol = 0;
        for (int root=0; root<n; ++root) {
            L[root] = 0;
            maxlevel = comp_l(root, -1);
            memset(dp, 0xff, sizeof dp);
            sol += go(root, -1, INCOMPLETE) + go(root, -1, COMPLETE);
        }
        return sol;
    }
};
