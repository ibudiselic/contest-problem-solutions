//# mincost maxflow, railroad, curves
//# => A checkerboard is a bipartite graph. To get all curves, split each cell into two nodes in the flow network, one representing the horizontal connection and one representing the vertical connection and make appropriate edges to the corresponding horizontal/vertical nodes of the neighboring cells. To allow straight connections in a cell, make it possible to go from the horizontal to the vertical part of a cell (and the other way around) by adding edges in both directions with cost 1 if we want a curve in this cell and cost 0 otherwise. Finally, check if the maxflow is equal to the number of nodes (otherwise it's impossible to actually connect all of them) and just return the mincost.
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

using namespace std;

struct edge_t {
    int from, to, cap, flow, cost, rev_idx;
    int avail() { return cap - flow; }
};
struct mcmf_t {
    int cost, flow;
    mcmf_t(): cost(0), flow(0) {}
};
edge_t dummy;
const int inf = 987654321;
struct FlowNetwork {
    vector<vector<edge_t>> edges;
    FlowNetwork(int n): edges(n) {}
    void add_edge(int from, int to, int cap, int cost) {
        edges[from].emplace_back((edge_t){from, to, cap, 0, cost, int(edges[to].size())});
        edges[to].emplace_back((edge_t){to, from, 0, 0, -cost, int(edges[from].size())-1});
    }
    mcmf_t mcmf(int source, int sink) {
        mcmf_t res;
        vector<edge_t*> via(edges.size(), nullptr);
        while (can_augment(source, sink, via)) {
            int flow = inf;
            for (int u=sink; u!=source; u=via[u]->from) {
                flow = min(flow, via[u]->avail());
            }
            for (int u=sink; u!=source; u=via[u]->from) {
                via[u]->flow += flow;
                edges[u][via[u]->rev_idx].flow -= flow;
                res.cost += flow*via[u]->cost;
            }
            res.flow += flow;
        }
        return res;
    }
    bool can_augment(int source, int sink, vector<edge_t*> &via) {
        fill(begin(via), end(via), nullptr);
        via[source] = &dummy;
        vector<int> dist(via.size(), inf);
        vector<char> in_queue(via.size(), 0);
        queue<int> active;
        active.push(source);
        dist[source] = 0;
        while (!active.empty()) {
            int u = active.front(); active.pop();
            in_queue[u] = 0;
            for (auto &e : edges[u]) {
                if (e.avail()>0 && dist[e.to]>dist[e.from]+e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    via[e.to] = &e;
                    if (!in_queue[e.to]) {
                        active.push(e.to);
                        in_queue[e.to] = 1;
                    }
                }
            }
        }
        return dist[sink] < inf;
    }
};
class CurvyonRails {
public:
    int getmin(vector <string> field) {
        int R = field.size();
        int C = field[0].size();
        vector<vector<int>> node(R, vector<int>(C, -1));
        int m = 0;
        int n = 0;
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                if (field[i][j] != 'w') {
                    if ((i+j)&1) {
                        node[i][j] = n++;
                    } else {
                        node[i][j] = m++;
                    }
                }
            }
        }
        if (n != m) {
            return -1;
        }

        int numnodes = 2*n+2*m+2;
        int sink = numnodes - 1;
        int source = sink - 1;
        FlowNetwork F(numnodes);
        for (int i=0; i<m; ++i) {
            F.add_edge(source, 2*i, 1, 0);
            F.add_edge(source, 2*i+1, 1, 0);
        }
        for (int i=0; i<n; ++i) {
            F.add_edge(2*m+2*i, sink, 1, 0);
            F.add_edge(2*m+2*i+1, sink, 1, 0);
        }
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                if (field[i][j]!='w' && ((i+j)&1)==0) {
                    for (int di=-1; di<2; di+=2) {
                        int r = i+di;
                        if (r<0 || r>=R || node[r][j]==-1) continue;
                        F.add_edge(2*node[i][j], 2*m+2*node[r][j], 1, 0);
                    }
                    for (int dj=-1; dj<2; dj+=2) {
                        int c = j+dj;
                        if (c<0 || c>=C || node[i][c]==-1) continue;
                        F.add_edge(2*node[i][j]+1, 2*m+2*node[i][c]+1, 1, 0);
                    }
                }
            }
        }

        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                if (node[i][j] != -1) {
                    if ((i+j)&1) {
                        F.add_edge(2*m+2*node[i][j], 2*m+2*node[i][j]+1, 1, field[i][j]=='C');
                        F.add_edge(2*m+2*node[i][j]+1, 2*m+2*node[i][j], 1, field[i][j]=='C');
                    } else {
                        F.add_edge(2*node[i][j], 2*node[i][j]+1, 1, field[i][j]=='C');
                        F.add_edge(2*node[i][j]+1, 2*node[i][j], 1, field[i][j]=='C');
                    }
                }
            }
        }

        mcmf_t res = F.mcmf(source, sink);
        if (res.flow != m+n) {
            return -1;
        } else {
            return res.cost;
        }
    }
};
