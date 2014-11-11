//# language, courses, graph, steiner tree, directed mst, dp, hard dp, dijkstra
//# => The graph leads from the lvl9 language levels down to the lvl0 levels that are connected to one goal node. This is basically a reverse of the graph given by the courses - each course would define an arc from its prerequisite to its result, and each language level has arcs to the next lower language level (because we get the lower levels as well). The problem is equivalent to directed MST on that graph, but can be solved more simply on the reversed graph using dp. Put "tokens" at the lvl9 nodes. Compute the lowest cost to get some tokens (mask) into a graph node. There are two ways for that cost to arise - either two subsets of mask met at the node or they met somewhere else and got here by traversing the graph. The second case is handled by dijkstra. The complexity is O(n*3^n) but can probably be reduced to O(n*2^n*log(10*n)) by only considering one-bit subsets when joining...
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

const int MAXNODES = 100 + 10;
const int INF = 123456789;
int dist[1<<10][MAXNODES];
inline int node(int lang, int lvl) {
    return lang*10 + lvl;
}

struct Edge {
    int to, cost;
};
vector<vector<Edge>> G;

struct State {
    int node, dist;
};
bool operator<(const State &a, const State &b) {
    return a.dist > b.dist;
}
class FoxTheLinguist {
public:
    int minimalHours(int n, vector <string> courseInfo) {
        G.assign(n*10+1, vector<Edge>());
        string courses = accumulate(begin(courseInfo), end(courseInfo), string());

        string s;
        for (istringstream is(courses); is>>s;) {
            char a, b;
            int lvla, lvlb, cost;
            sscanf(s.c_str(), "%c%d->%c%d:%d", &a, &lvla, &b, &lvlb, &cost);
            a = char(a - 'A');
            b = char(b - 'A');
            G[node(b, lvlb)].push_back({node(a, lvla), cost});
        }

        int goal = n*10;
        for (int c=0; c<n; ++c) {
            G[node(c, 0)].push_back({goal, 0});
            for (int i=9; i>0; --i) {
                G[node(c, i-1)].push_back({node(c, i), 0});
            }
        }

        for (int mask=0; mask<(1<<n); ++mask) {
            for (int i=0; i<=goal; ++i) {
                dist[mask][i] = INF;
            }
        }

        for (int i=0; i<n; ++i) {
            dist[1<<i][node(i, 9)] = 0;
        }
        for (int mask=1; mask<(1<<n); ++mask) {
            priority_queue<State> PQ;
            int *D = dist[mask];
            for (int i=0; i<=goal; ++i) {
                for (int sub=mask&(mask-1); sub; sub=mask&(sub-1)) {
                    D[i] = min(D[i], dist[sub][i] + dist[mask^sub][i]);
                }
                if (D[i] < INF) {
                    PQ.push({i, D[i]});
                }
            }

            while (!PQ.empty()) {
                State cur = PQ.top();
                PQ.pop();

                if (cur.dist > D[cur.node]) continue;

                int u = cur.node;
                for (int i=0; i<(int)G[u].size(); ++i) {
                    int v = G[u][i].to;
                    int cost = G[u][i].cost;
                    if (D[u]+cost < D[v]) {
                        D[v] = D[u]+cost;
                        PQ.push({v, D[v]});
                    }
                }
            }
        }

        int sol = dist[(1<<n)-1][goal];
        return sol==INF ? -1 : sol;
    }
};
