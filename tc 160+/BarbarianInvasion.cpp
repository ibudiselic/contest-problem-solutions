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
typedef long long flow_type;
const flow_type inf_flow = 1234567891234567LL;

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

int M, N;
inline int in(int i, int j) {
    return 2 + i*N + j;
}
inline int out(int i, int j) {
    return in(i, j) + M*N;
}
class BarbarianInvasion {
	public:
	int minimalDetachment(vector <string> countryMap, vector <int> detachmentSize) {
		M = countryMap.size();
        N = countryMap[0].size();
        Graph G(2 + 2*M*N);

        long long inf = 123456789123456LL;
        long long cmd = 10000000000LL;
        
        for (int i=0; i<M; ++i) {
            G.add_edge(SOURCE, in(i, 0), inf);
            G.add_edge(SOURCE, in(i, N-1), inf);
        }
        for (int j=0; j<N; ++j) {
            G.add_edge(SOURCE, in(0, j), inf);
            G.add_edge(SOURCE, in(M-1, j), inf);
        }
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (countryMap[i][j]!='*' && countryMap[i][j]!='-') {
                    G.add_edge(in(i, j), out(i, j), cmd + detachmentSize[countryMap[i][j]-'A']);
                } else if (countryMap[i][j] == '*') {
                    G.add_edge(in(i, j), SINK, inf);
                }
                for (int di=-1; di<2; ++di) {
                    for (int dj=-1; dj<2; ++dj) {
                        if (abs(di) + abs(dj) == 1) {
                            const int r = i + di;
                            const int c = j + dj;
                            if (r>=0 && r<M && c>=0 && c<N) {
                                G.add_edge(out(i, j), in(r, c), inf);
                            }
                        }
                    }
                }
            }
        }
        
        return G.max_flow()%cmd;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABA",
 "A*A",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalDetachment(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"CCCC",
 "-BAC",
 "-*AC",
 "--AC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(1, Arg2, minimalDetachment(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A----A",
 "-AAAA-",
 "-AA*A-",
 "-AAAA-",
 "A----A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,2,5,3,2,1,2,6,10,4,6,7,1,7,8,8,8,2,9,7,6,5,1,5,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimalDetachment(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"-A-----",
 "-BCCC*-",
 "-A-----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, minimalDetachment(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"WANNABRUTEFORCEMEHUH",
 "ASUDQWNHIOCASFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "-----*Y--AVSSFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "JUFDIFD-CHBVISBOOWE-",
 "WANNABRUTEFORCEMEHUH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {87,78,20,43,30,12,9,18,57,93,32,60,64,9,69,74,74,78,12,81,63,57,48,8,44,95}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 218; verify_case(4, Arg2, minimalDetachment(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BarbarianInvasion ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
