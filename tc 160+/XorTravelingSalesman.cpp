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
#include <utility>

using namespace std;

bool done[50][2048];
class XorTravelingSalesman {
public:
    int maxProfit(vector <int> V, vector <string> G) {
        int n = V.size();
        queue<pair<int, int> > Q;
        Q.push(make_pair(0, V[0]));
        int sol = V[0];
        done[0][V[0]] = 1;
        while (!Q.empty()) {
            const pair<int, int> tmp = Q.front();
            Q.pop();
            int u = tmp.first;
            int val = tmp.second;
            sol = max(sol, val);
            for (int v=0; v<n; ++v) {
                if (G[u][v] == 'Y') {
                    int nval = val^V[v];
                    if (!done[v][nval]) {
                        done[v][nval] = 1;
                        Q.push(make_pair(v, nval));
                    }
                }
            }
        }
        return sol;
    }
};
