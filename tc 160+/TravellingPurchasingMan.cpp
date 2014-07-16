//# shortest paths, bitmasks, dp, dijkstra
//# => Compute shortest paths between all nodes. We never need to move anywhere if we're not going to buy there so that makes it easy to represent the state with (where, used_mask). Follow up with dijkstra or dp (the graph is a DAG).
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
int best[1<<16][55];

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
                best[mask][i] = INF;
            }
        }
        best[0][n-1] = 0;
        int sol = 0;
        for (int mask=0; mask<(1<<numinteresting); ++mask) {
            for (int at=0; at<n; ++at) {
                if (best[mask][at] < INF) {
                    sol = max(sol, bc[mask]);
                    for (int next=0; next<numinteresting; ++next) {
                        if (G[at][next]<INF && (mask&(1<<next))==0) {
                            int ntime = best[mask][at] + G[at][next];
                            if (ntime > B[next]) continue;
                            best[mask|(1<<next)][next] = min(best[mask|(1<<next)][next], max(ntime, A[next])+duration[next]);
                        }
                    }
                }
            }
        }

        return sol;
    }
};
