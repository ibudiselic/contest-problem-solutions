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

bool not_dead[50];
bool reachable[50];
class GogoXMarisaKirisima {
public:
    int solve(vector <string> G) {
        int n = G.size();
        if (n == 2) {
            return G[0][1]=='Y' ? G[1][0]=='Y' ? 2 : 1 : 0;
        }
        vector<int> alive;
        alive.push_back(n-1);
        int head = 0;
        memset(not_dead, 0, sizeof not_dead);
        not_dead[n-1] = true;
        while (head < (int)alive.size()) {
            int u = alive[head++];
            for (int v=0; v<n; ++v) {
                if (G[v][u]=='Y' && !not_dead[v]) {
                    not_dead[v] = true;
                    alive.push_back(v);
                }
            }
        }
        memset(reachable, 0, sizeof reachable);
        alive.clear();
        alive.push_back(0);
        reachable[0] = true;
        head = 0;
        while (head < (int)alive.size()) {
            int u = alive[head++];
            for (int v=0; v<n; ++v) {
                if (G[u][v]=='Y' && !reachable[v]) {
                    reachable[v] = true;
                    alive.push_back(v);
                }
            }
        }
        
        if (!not_dead[0]) {
            return 0;
        }
        assert(reachable[n-1]);
        
        int nalive = 0;
        int nchoices = 0;
        for (int i=0; i<n; ++i) {
            if (reachable[i] && not_dead[i]) {
                ++nalive;
                for (int j=0; j<n; ++j) {
                    if (G[i][j]=='Y' && reachable[j] && not_dead[j]) {
                        ++nchoices;
                    }
                }
            }
        }
        
        return nchoices - nalive + 2;
    }
};
