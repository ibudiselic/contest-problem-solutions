//# painting, matrix, horizontal, vertical, min-cut, maxflow
//# => This is obviously a min-cut problem, but finding the right network is nontrivial... It turns out the correct approach is to assign nodes to horizontal and vertical edges of the board and empty squares and connect one to the source and one to the sink and then connect adjacent nodes to that. See the editorial/code for details.
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

typedef int flow_type;
const flow_type inf_flow = 1234567890;
const int inf = inf_flow;

struct Edge {
    int to;
    flow_type cap, flow;
    Edge *rev;
    Edge(int to_, flow_type cap_, flow_type flow_): to(to_), cap(cap_), flow(flow_), rev(NULL) {}
};
    
struct FlowNetwork {
    vector< vector<Edge*> > adj;
    ~FlowNetwork() { for (int i=0; i<(int)adj.size(); ++i) for (int j=0; j<(int)adj[i].size(); ++j) delete adj[i][j]; }
    
    int add_source() {
        source = add_node();
        return source;
    }
    int add_sink() {
        sink = add_node();
        return sink;
    }
    
    int add_node() {
        adj.push_back(vector<Edge*>());
        return int(adj.size()) - 1;
    }
    void add_edge(int from, int to, flow_type cap) {
        Edge *u = new Edge(to, cap, 0);
        Edge *v = new Edge(from, 0, 0);
        u->rev = v;
        v->rev = u;
        adj[from].push_back(u);
        adj[to].push_back(v);
    }
    
    flow_type max_flow();
    
    private:
    int source, sink;
    bool can_augment(vector<Edge *> &);
};

bool FlowNetwork::can_augment(vector<Edge *> &P) {
    queue<int> Q;
    for (int i=0; i<(int)P.size(); ++i) {
        P[i] = NULL;
    }
    Q.push(source);
    
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        
        for (int i=0; i<(int)adj[x].size(); ++i) {
            Edge *e = adj[x][i];
            if (e->cap-e->flow>0 && P[e->to]==NULL) {
                P[e->to] = e;
                if (e->to == sink) {
                    return true;
                }
                Q.push(e->to);
            }
        }
    }
    
    return false;
}
flow_type FlowNetwork::max_flow() {
    flow_type ret = 0;
    vector<Edge*> P(adj.size());
    while (can_augment(P)) {
        flow_type flow = inf_flow;
        for (int upd=0; upd<2; ++upd) {
            int t = sink;
            while (t != source) {
                Edge *e = P[t];
                assert(e->to == t);
                if (!upd) {
                    flow = min(flow, e->cap - e->flow);
                } else {
                    e->flow += flow;
                    e->rev->flow -= flow;
                }
                t = e->rev->to;
            }
        }
        ret += flow;
    }

    return ret;
}

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int node[50][50];
class BoardPainting {
public:
    int minimalSteps(vector <string> target) {
        int m = target.size();
        int n = target[0].size();
        #define VALID(i, j) (0<=(i) && (i)<m && 0<=(j) && (j)<n && target[i][j]=='#')

        FlowNetwork F;
        int source = F.add_source();
        int sink = F.add_sink();

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (target[i][j] == '#') {
                    node[i][j] = F.add_node();
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (target[i][j] != '#') continue;
                for (int d=0; d<4; ++d) {
                    int r = i + di[d];
                    int c = j + dj[d];
                    if (VALID(r, c)) {
                        F.add_edge(node[i][j], node[r][c], 1);
                    }
                }
            }
        }

        for (int i=0; i<m; ++i) {
            int opts[] = {0, n-1};
            for (int j=0; j<2; ++j) {
                if (target[i][opts[j]] == '#') {
                    int v = F.add_node();
                    F.add_edge(source, v, 1);
                    F.add_edge(v, node[i][opts[j]], 1);
                }
            }
        }

        for (int j=0; j<n; ++j) {
            int opts[] = {0, m-1};
            for (int i=0; i<2; ++i) {
                if (target[opts[i]][j] == '#') {
                    int h = F.add_node();
                    F.add_edge(h, sink, 1);
                    F.add_edge(node[opts[i]][j], h, 1);
                }
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (target[i][j] != '#') {
                    for (int d=0; d<4; ++d) {
                        int r = i + di[d];
                        int c = j + dj[d];
                        if (VALID(r, c)) {
                            if (d&1) {
                                int v = F.add_node();
                                F.add_edge(source, v, 1);
                                F.add_edge(v, node[r][c], 1);
                            } else {
                                int h = F.add_node();
                                F.add_edge(h, sink, 1);
                                F.add_edge(node[r][c], h, 1);
                            }
                        }
                    }
                }
            }
        }

        return F.max_flow()/2;
    }
};
