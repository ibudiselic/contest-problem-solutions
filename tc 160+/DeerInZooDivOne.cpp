//# deer, antlers, trees, isomorprhism, tree isomporphism, min-cost max-flow, mcmf, bipartite, maximum weight bipartite matching, dp
//# => Choose an edge to delete. This partitions the tree into two trees. Try all pairs of candidate roots and compute the size of the largest isomorphic tree rooted at those nodes. To do that, recursively compute the sizes for each child assignment and then find the maximum weight bipartite matching of the children (done with mcmf in the code, should learn kuhn-munkres...
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

typedef int flow_t;
typedef int cost_t;
const cost_t INF = 987654321;
struct edge_t {
    int from, to, rev_ind;
    flow_t capacity, flow;
    cost_t cost;
    edge_t(int from_, int to_, flow_t capacity_, cost_t cost_, int rev_ind_):
        from(from_), to(to_), rev_ind(rev_ind_), capacity(capacity_), flow(0), cost(cost_) {}
};

class flow_network {
    public:
    int source, sink;
    vector< vector<edge_t> > edges;
    
    int add_node() { edges.push_back(vector<edge_t>()); return (int)edges.size()-1; }
    int add_source() { return source = add_node(); }
    int add_sink() { return sink = add_node(); }
    
    void add_edge(int from, int to, flow_t capacity, cost_t cost) {
        edges[from].push_back(edge_t(from, to, capacity, cost, edges[to].size()));
        edges[to].push_back(edge_t(to, from, 0, -cost, edges[from].size()-1));
    }
    
    pair<cost_t, flow_t> min_cost_max_flow() {
        assert(source != -1);
        assert(sink != -1);
        cost_t cost = 0;
        flow_t flow = 0;
        
        vector<edge_t*> F(edges.size(), 0);
        while (can_augment(F)) {
            flow_t avail_flow = INF;
            int u = sink;
            while (u != source) {
                edge_t *e = F[u];
                avail_flow = min(avail_flow, e->capacity-e->flow);
                u = e->from;
            }
            cost_t path_cost = 0;
            u = sink;
            while (u != source) {
                edge_t *e = F[u];
                e->flow += avail_flow;
                edges[e->to][e->rev_ind].flow -= avail_flow;
                path_cost += avail_flow * e->cost;
                u = e->from;
            }
            flow += avail_flow;
            cost += path_cost;
        }
        
        return make_pair(cost, flow);
    }
    
    private:
    bool can_augment(vector<edge_t*> &F) {
        vector<cost_t> dist(F.size(), INF);
        vector<int> in_queue(F.size(), 0);
        queue<int> active;
        active.push(source);
        dist[source] = 0;
        while (!active.empty()) {
            int u = active.front(); active.pop();
            in_queue[u] = 0;
            vector<edge_t> &E = edges[u];
            for (int i=0; i<(int)E.size(); ++i) {
                edge_t &e = E[i];
                if (e.capacity-e.flow>0 && dist[e.to]>dist[e.from]+e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    F[e.to] = &e;
                    if (!in_queue[e.to]) {
                        active.push(e.to);
                        in_queue[e.to] = 1;
                    }
                }
            }
        }
        return dist[sink] < INF;
    }
};

struct edge {
    int a, b;
    int vertex(int side) const {
        return side==0 ? a : b;
    }
    int side(int u) const {
        return u==a ? 0 : 1;
    }
    int other(int u) const {
        return u==a ? b : a;
    }
};

vector<edge> E;
vector<vector<int>> G;

bool done[55][2];
void dfs(int e, int side, vector<int> &A) {
    int u = E[e].vertex(side);
    A.push_back(u);
    done[e][side] = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int f = G[u][i];
        if (f != e) {
            int fside = 1 - E[f].side(u);
            if (!done[f][fside]) {
                dfs(f, fside, A);
            }
        }
    }
}

int maxsz[55][2][55][2];
int go(int e, int eside, int f, int fside) {
    int &ret = maxsz[e][eside][f][fside];
    if (ret != -1) {
        return ret;
    }
    int u = E[e].vertex(eside);
    int v = E[f].vertex(fside);
    
    flow_network F;
    int source = F.add_source();
    int sink = F.add_sink();

    vector<int> fnodes;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int ee = G[u][i];
        if (ee == e) continue;
        int eeside = 1 - E[ee].side(u);
        int node = F.add_node();
        F.add_edge(source, node, 1, 0);
        for (int j=0; j<(int)G[v].size(); ++j) {
            int ff = G[v][j];
            if (j <= (int)fnodes.size()) {
                fnodes.push_back(F.add_node());
                F.add_edge(fnodes.back(), sink, 1, 0);
            }
            if (ff == f) continue;
            int ffside = 1 - E[ff].side(v);
            F.add_edge(node, fnodes[j], 1, -go(ee, eeside, ff, ffside));
        }
    }
    
    ret = 1 - F.min_cost_max_flow().first;
    return ret;
}
int calc(const vector<int> &left, const vector<int> &right) {
    memset(maxsz, 0xff, sizeof maxsz);
    int ret = 0;
    for (int i=0; i<(int)left.size(); ++i) {
        E.back() = edge{left[i], -1};
        for (int j=0; j<(int)right.size(); ++j) {
            E[E.size()-2] = edge{right[j], -1};
            maxsz[E.size()-1][0][E.size()-2][0] = -1;
            ret = max(ret, go(E.size()-1, 0, E.size()-2, 0));
        }
    }
    return ret;
}
class DeerInZooDivOne {
public:
    int getmax(vector <int> a, vector <int> b) {
        E.clear();
        for (int i=0; i<(int)a.size(); ++i) {
            E.push_back(edge{a[i], b[i]});
        }
        E.push_back(edge{0, 0});
        E.push_back(edge{0, 0});

        int sol = 0;
        for (int brkpt=0; brkpt<(int)a.size(); ++brkpt) {
            G.assign(a.size()+1, vector<int>());
            for (int i=0; i<(int)a.size(); ++i) {
                if (i == brkpt) continue;
                G[a[i]].push_back(i);
                G[b[i]].push_back(i);
            }

            memset(done, 0, sizeof done);
            vector<int> left, right;
            dfs(brkpt, 0, left);
            dfs(brkpt, 1, right);
            sol = max(sol, calc(left, right));
        }

        return sol;
    }
};
