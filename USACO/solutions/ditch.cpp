/*
ID: ivan.bu1
PROG: ditch
LANG: C++
*/
#include <cassert>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>

using namespace std;

struct edge_t {
    int from, to;
    int rev_ind;
    long long cap;
    
    edge_t(int from_, int to_, long long cap_): from(from_), to(to_), cap(cap_) {}
};
struct FlowNetwork {
    FlowNetwork(int n): edges(n, vector<edge_t>()), source(0), sink(n-1) {}
    
    void add_edge(int from, int to, long long cap) {
        cerr << from << ' ' << to << ' ' << cap << '\n';
        edges[from].push_back(edge_t(from, to, cap));
        edges[to].push_back(edge_t(to, from, 0));
        edges[from].back().rev_ind = (int)edges[to].size() - 1;
        edges[to].back().rev_ind = (int)edges[from].size() - 1;
    }
    
    bool can_augment(vector<edge_t *> &P) {
        P.assign(edges.size(), 0);
        queue<int> Q;
        Q.push(source);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<(int)edges[u].size(); ++i) {
                edge_t *e = &edges[u][i];
                if (e->cap>0 && P[e->to]==0) {
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
    
    long long max_flow() {
        long long res = 0;
        vector<edge_t *> P;
        while (can_augment(P)) {
            edge_t *e = P[sink];
            assert(e != 0);
            long long by = 1234567891234LL;
            while (e!=0 && e->to!=source) {
                by = min(by, e->cap);
                e = P[e->from];
            }
            e = P[sink];
            while (e!=0 && e->to!=source) {
                e->cap -= by;
                edges[e->to][e->rev_ind].cap += by;
                e = P[e->from];
            }
            res += by;
        }
        return res;
    }

    vector< vector<edge_t> > edges;
    int source, sink;
};

int main() {
	ifstream fin("ditch.in");
    int N, M;
    fin >> N >> M;
    FlowNetwork F(M);
    for (int i=0; i<N; ++i) {
        int s, e, c;
        fin >> s >> e >> c;
        F.add_edge(s-1, e-1, c);
    }
    fin.close();
    
    ofstream fout("ditch.out");
    fout << F.max_flow() << '\n';
    fout.close();

	return 0;
}
