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

using namespace std;

struct frac_cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first*b.second < a.second*b.first;
    }
};
vector<string> P;

typedef int flow_type;
const flow_type inf_flow = 1234567890;
const int inf = inf_flow;

struct Edge {
    int to;
    flow_type cap, flow;
    Edge *rev;
    Edge(int to_, flow_type cap_, flow_type flow_): to(to_), cap(cap_), flow(flow_), rev(NULL) {}
};
    
struct Graph {
    vector< vector<Edge*> > adj;
    ~Graph() { for (int i=0; i<(int)adj.size(); ++i) for (int j=0; j<(int)adj[i].size(); ++j) delete adj[i][j]; }
    
    int add_source() {
        SOURCE = add_node();
        return SOURCE;
    }
    int add_sink() {
        SINK = add_node();
        return SINK;
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
    int SOURCE, SINK;
    bool can_augment(vector<Edge *> &);
};

bool Graph::can_augment(vector<Edge *> &P) {
    queue<int> Q;
    for (int i=0; i<(int)P.size(); ++i) {
        P[i] = NULL;
    }
    Q.push(SOURCE);
    
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        
        for (int i=0; i<(int)adj[x].size(); ++i) {
            Edge *e = adj[x][i];
            if (e->cap-e->flow>0 && P[e->to]==NULL) {
                P[e->to] = e;
                if (e->to == SINK) {
                    return true;
                }
                Q.push(e->to);
            }
        }
    }
    
    return false;
}
flow_type Graph::max_flow() {
    flow_type ret = 0;
    vector<Edge*> P(adj.size());
    while (can_augment(P)) {
        flow_type flow = inf_flow;
        for (int upd=0; upd<2; ++upd) {
            int t = SINK;
            while (t != SOURCE) {
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

// can we get efficiency larger than a/b?
bool can(const pair<int, int> &cand) {
    int a = cand.first;
    int b = cand.second;
    int n = P.size();
    Graph F;
    int source = F.add_source();
    int sink = F.add_sink();
    vector<int> rabbits;
    for (int i=0; i<n; ++i) {
        rabbits.push_back(F.add_node());
        F.add_edge(rabbits.back(), sink, 199*a);
    }
    int total = 0;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int pair_node = F.add_node();
            int val = b*(P[i][j]-'0') + 2*a;
            F.add_edge(source, pair_node, val);
            total += val;
            F.add_edge(pair_node, rabbits[i], inf);
            F.add_edge(pair_node, rabbits[j], inf);
        }
    }

    int val = F.max_flow();
    return val < total;
}
class RabbitWorking {
public:
    double getMaximum(vector <string> profit) {
        P = profit;
        int n = P.size();
        if (n == 1) {
            return 0.0;
        }

        vector<pair<int, int> > cands;
        for (int a=0; a<=9*n*(n-1)/2; ++a) {
            for (int b=1; b<=n; ++b) {
                cands.push_back(make_pair(a, b*(200-b)));
            }
        }
        sort(cands.begin(), cands.end(), frac_cmp());

        int lo = 0;
        int hi = int(cands.size()) - 1;
        while (lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            if (can(cands[mid])) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        ++lo; // lo was the largest a/b that answered that we can get a higher efficiency so we take the next one
        return double(cands[lo].first)/cands[lo].second;
    }
};
