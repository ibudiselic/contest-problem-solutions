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

const int inf = 1234567890;
int P[50];
bool used[50];
int dfs(int u) {
    used[u] = true;
    int ret = 1;
    if (!used[P[u]]) {
        ret += dfs(P[u]);
    }
    return ret;
}
int calc(int n) {
    memset(used, 0, sizeof used);
    int ret = 0;
    for (int i=0; i<n; ++i) {
        if (!used[i]) {
            ret += dfs(i) - 1;
        }
    }
    return ret;
}
class MonochromePuzzle {
public:
    int getMinimum(vector <string> G) {
        int n = G.size();
        for (int i=0; i<n; ++i) {
            int deg = count(G[i].begin(), G[i].end(), '#');
            if (deg != 3) {
                return -1;
            }
        }
        int sol = inf;
        for (P[0]=0; P[0]<n; ++P[0]) {
            for (P[1]=0; P[1]<n; ++P[1]) {
                if (P[0]==P[1] || G[P[0]][P[1]]!='#') continue;
                for (P[n-1]=0; P[n-1]<n; ++P[n-1]) {
                    if (P[n-1]==P[0] || P[n-1]==P[1] || G[P[0]][P[n-1]]!='#') continue;
                    
                    memset(used, 0, sizeof used);
                    used[P[0]] = used[P[1]] = used[P[n-1]] = true;
                    
                    int next = 2;
                    int u = 1;
                    int v = n-1;
                    while (next != n/2) {
                        int cand;
                        for (cand=0; cand<n; ++cand) {
                            if (!used[cand] && G[P[u]][cand]=='#' && (next<n/2 && G[P[v]][cand]!='#' || next>n/2 && G[P[v]][cand]=='#')) {
                                break;
                            }
                        }
                        if (cand == n) {
                            break;
                        }
                        used[cand] = true;
                        P[next] = cand;
                        if (next < n/2) {
                            next = n - next;
                            swap(u, v);
                        } else {
                            next = n - next + 1;
                            u = next - 1;
                            v = n - u;
                        }
                    }
                    if (next != n/2) {
                        continue;
                    }
                    for (int i=0; i<n; ++i) {
                        if (!used[i] && G[P[n-1]][i]=='#' && G[P[u]][i]=='#' && G[P[v]][i]=='#') {
                            P[n/2] = i;
                            sol = min(sol, calc(n));
                            break;
                        }
                    }
                }
            }
        }
        
        return sol==inf ? -1 : sol;
    }
};
