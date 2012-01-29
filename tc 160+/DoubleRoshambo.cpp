#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

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

bool beats(char a, char b) {
    if (a == 'R') {
        return b=='S';
    } else if (a == 'P') {
        return b=='R';
    } else {
        assert(a == 'S');
        return b=='P';
    }
}
int score(const string &a, const string &b) {
    if (beats(a[1], b[1])) {
        if (beats(a[0], b[0])) {
            return 2;
        } else if (a[0] == b[0]) {
            return 1;
        }
    }
    return 0;
}
class DoubleRoshambo {
	public:
	int maxScore(vector <string> A, vector <string> E) {
		flow_network G;
        int source = G.add_source();
        int sink = G.add_sink();
        vector<int> a, e;
        for (int i=0; i<(int)A.size(); ++i) {
            a.push_back(G.add_node());
            G.add_edge(source, a.back(), 1, 0);
        }
        for (int i=0; i<(int)E.size(); ++i) {
            e.push_back(G.add_node());
            G.add_edge(e.back(), sink, 1, 0);
        }
        
        for (int i=0; i<(int)a.size(); ++i) {
            for (int j=0; j<(int)e.size(); ++j) {
                G.add_edge(a[i], e[j], 1, 2-score(A[i], E[j]));
            }
        }
        
        return (int)A.size()*2 - G.min_cost_max_flow().first;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"SR", "PP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PR", "RS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PP", "PP", "PP", "PP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RR", "PR", "SS", "SP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, maxScore(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DoubleRoshambo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
