//# tiles, chessboard, maxflow
//# => The key idea to make maxflow work here is to fix the role of the white squares for a tile as either input or output. Specifically, even row white cells are used as input and odd row ones are used as output. The input cell is then connected to the black cell which is connected to the output cell.
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

const int MAXN = 50;
int I[MAXN][MAXN];
int O[MAXN][MAXN];

class TheTilesDivOne {
public:
    int find(vector <string> board) {
        int m = board.size();
        int n = board[0].size();

        FlowNetwork F;
        int source = F.add_source();
        int sink = F.add_sink();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == '.') {
                    I[i][j] = F.add_node();
                    O[i][j] = F.add_node();
                    F.add_edge(I[i][j], O[i][j], 1);
                    if ((i+j)&1) { // white
                        if (i&1) {
                            F.add_edge(O[i][j], sink, 1);
                        } else {
                            F.add_edge(source, I[i][j], 1);
                        }
                    }
                }
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j]!='.' || ((i+j)&1)) continue;
                for (int di=-1; di<=1; di+=2) {
                    int r1 = i + di;
                    int c1 = j;
                    if (r1<0 || r1>=m || board[r1][c1]!='.') continue;
                    for (int dj=-1; dj<=1; dj+=2) {
                        int r2 = i;
                        int c2 = j + dj;
                        if (c2<0 || c2>=n || board[r2][c2]!='.') continue;
                        if ((i&1) == 0) {
                            swap(r1, r2);
                            swap(c1, c2);
                        }
                        F.add_edge(O[r1][c1], I[i][j], 1);
                        F.add_edge(O[i][j], I[r2][c2], 1);
                    }
                }
            }
        }

        return F.max_flow();
    }
};
