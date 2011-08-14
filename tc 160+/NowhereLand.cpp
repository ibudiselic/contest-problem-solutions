#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

enum {
    SOURCE, SINK
};
typedef int flow_type;
const flow_type inf_flow = 1234567890;

struct Edge {
    int to;
    flow_type cap, flow;
    Edge *rev;
    Edge(int to_, flow_type cap_, flow_type flow_): to(to_), cap(cap_), flow(flow_), rev(NULL) {}
};
    
struct Graph {
    vector< vector<Edge*> > adj;
    Graph(int n) { adj.assign(n, vector<Edge*>()); }
    ~Graph() { for (int i=0; i<(int)adj.size(); ++i) for (int j=0; j<(int)adj[i].size(); ++j) delete adj[i][j]; }
    
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

bool have[50][50];
bool can[50][50];
class NowhereLand {
	public:
	int placeGuards(vector <string> cities, int k, vector <string> guards, vector <string> agencies) {
        memset(have, 0, sizeof have);
        memset(can, 0, sizeof can);
        for (int i=0; i<(int)guards.size(); ++i) {
            {
                int x;
                istringstream is(guards[i]);
                while (is >> x) {
                    have[x][i] = true;
                }
            }
            {
                int x;
                istringstream is(agencies[i]);
                while (is >> x) {
                    can[x][i] = true;
                }
            }
        }
		int sol = 0;
        while (k--) {
            Graph G(cities.size() + 2);
            for (int i=0; i<(int)cities.size(); ++i) {
                if (have[k][i]) {
                    G.add_edge(SOURCE, i+2, inf_flow);
                } else if (!can[k][i]) {
                    G.add_edge(i+2, SINK, inf_flow);
                }
                for (int j=0; j<(int)cities[0].size(); ++j) {
                    if (cities[i][j] == '1') {
                        G.add_edge(i+2, j+2, 1);
                    }
                }
            }
            sol += G.max_flow();
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "0111",
  "1000",
  "1000",
  "1000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = { "0", "", "", "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "0", "0", "", "0" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, placeGuards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = { "011",
  "101",
  "110"  }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = { "0", "", "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "0", "", "" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(1, Arg4, placeGuards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = { "011",
  "101",
  "110"  }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = { "", "", "" }	; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "0", "0", "0" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, placeGuards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = { "010100",
  "101100",
  "010011",
  "110010",
  "001100",
  "001000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = { "1 2", "", "1", "", "0", "0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "0 1 2", "0 1", "0 1 2", "1 2", "0", "0" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 7; verify_case(3, Arg4, placeGuards(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NowhereLand ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
