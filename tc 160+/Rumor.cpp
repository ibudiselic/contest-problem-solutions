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
#include <queue>

using namespace std;

int n;
bool start[16];
bool G[16][16];
const int inf = 1234567890;
bool knows[16][2], spread[16][2];
bool round_spreading[16];
int calc(int mask) {
    memset(knows, 0, sizeof knows);
    memset(spread, 0, sizeof spread);
    int need = 2*n;
    queue<int> Q;
    for (int i=0; i<n; ++i) {
        if (start[i]) {
            knows[i][0] = knows[i][1] = true;
            need -= 2;
            Q.push(i);
        }
    }
    
    int sz = 0;
    int t = 0;
    while (need>0 && Q.size()) {
        if (sz == 0) {
            sz = Q.size();
            ++t;
            memset(round_spreading, 0, sizeof round_spreading);
        }
        --sz;
        int u = Q.front();
        Q.pop();
        
        if (round_spreading[u]) {
            if (knows[u][0] && !spread[u][0] || knows[u][1] && !spread[u][1]) {
                Q.push(u);
            }
            continue;
        }
        int to_spread = -1;
        if (knows[u][0] && knows[u][1]) {
            if (spread[u][0] && !spread[u][1]) {
                to_spread = 1;
            } else if (spread[u][1] && !spread[u][0]) {
                to_spread = 0;
            } else if (!spread[u][0] && !spread[u][1]) {
                if (mask & (1<<u)) {
                    to_spread = 0;
                } else {
                    to_spread = 1;
                }
            }
        } else if (knows[u][0] && !spread[u][0]) {
            to_spread = 0;
        } else if (knows[u][1] && !spread[u][1]) {
            to_spread = 1;
        }
        //cerr << u << ' ' << to_spread << '\n';
        if (to_spread == -1) {
            continue;
        }
        round_spreading[u] = true;
        assert(knows[u][to_spread]);
        spread[u][to_spread] = true;
        
        for (int i=0; i<n; ++i) {
            if (G[u][i]) {
                if (!knows[i][to_spread]) {
                    knows[i][to_spread] = true;
                    --need;
                    Q.push(i);
                }
            }
        }
        if (knows[u][!to_spread] && !spread[u][!to_spread]) {
            Q.push(u);
        }
    }
    return need==0 ? t : inf;
}
class Rumor {
public:
    int getMinimum(string knowledge, vector <string> graph) {
        n = knowledge.size();
        for (int i=0; i<n; ++i) {
            start[i] = (knowledge[i] == 'Y');
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (graph[i][j] == 'Y');
            }
        }
        
        int sol = inf;
        for (int mask=0; mask<(1<<n); ++mask) {
            sol = min(sol, calc(mask));
        }
        return sol==inf ? -1 : sol;
    }
};
