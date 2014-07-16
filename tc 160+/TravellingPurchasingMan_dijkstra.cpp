//# shortest paths, dp, bitmasks
//# => See main solution.
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
#include <sstream>

using namespace std;

const int INF = 987654321;
int G[55][55];
int bc[1<<16];
int A[55], B[55], duration[55];

struct state {
    int at, mask, t;
};
bool operator<(const state &a, const state &b) {
    return a.t > b.t;
}
int best[55][1<<16];

class TravellingPurchasingMan {
public:
    int maxStores(int n, vector <string> interestingStores, vector <string> roads) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = INF;
            }
            G[i][i] = 0;
        }
        for (int i=0; i<(int)roads.size(); ++i) {
            istringstream is(roads[i]);
            int a, b, w;
            is >> a >> b >> w;
            G[a][b] = G[b][a] = w;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }

        int numinteresting = interestingStores.size();
        for (int mask=1; mask<(1<<numinteresting); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }
        for (int i=0; i<numinteresting; ++i) {
            istringstream is(interestingStores[i]);
            is >> A[i] >> B[i] >> duration[i];
        }

        for (int i=0; i<n; ++i) {
            for (int mask=0; mask<(1<<numinteresting); ++mask) {
                best[i][mask] = INF;
            }
        }
        priority_queue<state> PQ;
        PQ.push(state{n-1, 0, 0});
        best[n-1][0] = 0;
        int sol = 0;
        while (!PQ.empty()) {
            state cur = PQ.top();
            PQ.pop();
            for (int i=0; i<numinteresting; ++i) {
                if (cur.mask & (1<<i)) continue;
                int newmask = cur.mask | (1<<i);
                if (G[cur.at][i]==INF || cur.t+G[cur.at][i]>B[i]) continue;
                int endtime = max(A[i], cur.t+G[cur.at][i]) + duration[i];
                if (endtime >= best[i][newmask]) continue;
                best[i][newmask] = endtime;
                sol = max(sol, bc[newmask]);
                PQ.push(state{i, newmask, endtime});
            }
        }

        return sol;
    }
};
