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

struct edge_t {
    int a, b, cap, rev_ind;
};
const int inf = 1234567980;
struct FlowNetwork {
    int sink, source;
    vector< vector<edge_t> > edges;

    int add_node() {
        edges.push_back(vector<edge_t>());
        return int(edges.size())-1;
    }
    int add_sink() {
        return sink = add_node();
    }
    int add_source() {
        return source = add_node();
    }
    void add_edge(int a, int b, int cap) {
        edge_t e = (edge_t){a, b, cap, int(edges[b].size())};
        edge_t er = (edge_t){b, a, 0, int(edges[a].size())};
        edges[a].push_back(e);
        edges[b].push_back(er);
    }

    bool can_augment(vector<edge_t*> &P, vector<int> &vis, int pass) {
        queue<int> Q;
        Q.push(source);
        vis[source] = pass;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<(int)edges[u].size(); ++i) {
                edge_t *e = &edges[u][i];
                if (e->cap>0 && vis[e->b]!=pass) {
                    vis[e->b] = pass;
                    Q.push(e->b);
                    P[e->b] = e;
                    if (e->b == sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int maxflow() {
        vector<edge_t*> P(edges.size(), 0);
        vector<int> vis(edges.size(), 0);
        int flow = 0;
        int pass = 1;
        while (can_augment(P, vis, pass++)) {
            int u = sink;
            int add = inf;
            while (u != source) {
                edge_t *e = P[u];
                add = min(add, e->cap);
                u = e->a;
            }
            u = sink;
            while (u != source) {
                edge_t *e = P[u];
                e->cap -= add;
                edges[e->b][e->rev_ind].cap += add;
                u = e->a;
            }
            flow += add;
        }
        return flow;
    }
};

bool ok(vector<string> &bridges, int an, int bn, int a1, int a2, int b1, int b2) {
    FlowNetwork F;
    int source = F.add_source();
    int sink = F.add_sink();
    int n = bridges.size();
    vector<int> nodes;
    for (int i=0; i<n; ++i) {
        nodes.push_back(F.add_node());
    }
    F.add_edge(source, nodes[a1], 2*an);
    F.add_edge(source, nodes[b1], 2*bn);
    F.add_edge(nodes[a2], sink, 2*an);
    F.add_edge(nodes[b2], sink, 2*bn);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (bridges[i][j] == 'N') {
                F.add_edge(nodes[i], nodes[j], inf);
            } else if (bridges[i][j] == 'O') {
                F.add_edge(nodes[i], nodes[j], 2);
            }
        }
    }
    return F.maxflow() == 2*(an+bn);
}
class OldBridges {
public:
    string isPossible(vector <string> bridges, int a1, int a2, int an, int b1, int b2, int bn) {
        return ok(bridges, an, bn, a1, a2, b1, b2) && ok(bridges, an, bn, a1, a2, b2, b1) ? "Yes" : "No";
    }
};
