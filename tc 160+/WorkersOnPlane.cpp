#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

enum {
    GRASS, ROCKS
};
int gstart, gcnt, sstart, scnt, wstart, wcnt;
int A[30][30];
int m, n;

bool valid(int i, int j) {
    if (i<0 || j<0 || i>=m || j>=n) {
        return false;
    }
    return true;
}
inline bool isgold(int i, int j) {
    return (gstart<=A[i][j] && A[i][j]<gstart+gcnt);
}
inline bool issilver(int i, int j) {
    return (sstart<=A[i][j] && A[i][j]<sstart+scnt);
}
inline bool isworker(int i, int j) {
    return (wstart<=A[i][j] && A[i][j]<wstart+wcnt);
}

bool done[30][30];
int DG[900][900], DS[900][900];
enum {
    SOURCE, SINK
};
struct Edge {
    int to, cap, flow;
    Edge *rev;
    Edge(int to_, int cap_, int flow_): to(to_), cap(cap_), flow(flow_), rev(NULL) {}
};
    
struct Graph {
    vector< vector<Edge*> > adj;
    Graph(int n) { adj.assign(n, vector<Edge*>()); }
    ~Graph() { for (int i=0; i<(int)adj.size(); ++i) for (int j=0; j<(int)adj[i].size(); ++j) delete adj[i][j]; }
    
    void add_edge(int from, int to, int cap) {
        Edge *u = new Edge(to, cap, 0);
        Edge *v = new Edge(from, 0, 0);
        u->rev = v;
        v->rev = u;
        adj[from].push_back(u);
        adj[to].push_back(v);
    }
    
    int max_flow();
    
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
int Graph::max_flow() {
    int ret = 0;
    vector<Edge*> P(adj.size());
    while (can_augment(P)) {
        int flow = 123456789;
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
    
class WorkersOnPlane {
	public:
	int howMany(vector <string> field, int K) {
		m = field.size();
        n = field[0].size();
        gcnt = scnt = wcnt = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (field[i][j] == '.') {
                    A[i][j] = GRASS;
                } else if (field[i][j] == 'X') {
                    A[i][j] = ROCKS;
                } else if (field[i][j] == 'G') {
                    ++gcnt;
                } else if (field[i][j] == 'S') {
                    ++scnt;
                } else if (field[i][j] == 'W') {
                    ++wcnt;
                }
            }
        }
        gstart = 2;
        sstart = gstart + gcnt;
        wstart = sstart + scnt;
        
        {
        int g=0, s=0, w=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (field[i][j] == 'G') {
                    A[i][j] = gstart + g++;
                } else if (field[i][j] == 'S') {
                    A[i][j] = sstart + s++;
                } else if (field[i][j] == 'W') {
                    A[i][j] = wstart + w++;
                }
            }
        }
        assert(g==gcnt && s==scnt && w==wcnt);
        }
        
        memset(DG, 0x3f, sizeof DG);
        memset(DS, 0x3f, sizeof DS);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (isworker(i, j)) {
                    int w = A[i][j] - wstart;
                    queue< pair<int, int> > Q;
                    memset(done, 0, sizeof done);
                    done[i][j] = 1;
                    Q.push(make_pair(i, j));
                    int d = -1;
                    int lsz = 0;
                    while (!Q.empty()) {
                        if (lsz == 0) {
                            lsz = Q.size();
                            ++d;
                        }
                        int r = Q.front().first;
                        int c = Q.front().second;
                        Q.pop();
                        --lsz;
                        
                        if (isgold(r, c)) {
                            DG[w][A[r][c]-gstart] = d;
                        } else if (issilver(r, c)) {
                            DS[w][A[r][c]-sstart] = d;
                        }
                        
                        if (A[r][c]!=GRASS && (i!=r || j!=c)) {
                            continue;
                        }
                        
                        for (int dr=-1; dr<2; ++dr) {
                            for (int dc=-1; dc<2; ++dc) {
                                if (abs(dr) + abs(dc) == 1) {
                                    int rr = r + dr;
                                    int cc = c + dc;
                                    if (valid(rr, cc) && A[rr][cc]!=ROCKS && !done[rr][cc]) {
                                        done[rr][cc] = true;
                                        Q.push(make_pair(rr, cc));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        Graph G(2 + gcnt + scnt + 2*wcnt);
        for (int g=0; g<gcnt; ++g) {
            G.add_edge(SOURCE, gstart+g, 1);
        }
        for (int s=0; s<scnt; ++s) {
            G.add_edge(sstart+s, SINK, 1);
        }
        for (int w=0; w<wcnt; ++w) {
            G.add_edge(wstart+w, wstart+wcnt+w, 1);
            for (int g=0; g<gcnt; ++g) {
                if (DG[w][g] <= K) {
                    G.add_edge(gstart+g, wstart+w, 1);
                }
            }
            for (int s=0; s<scnt; ++s) {
                if (DS[w][s] <= K) {
                    G.add_edge(wstart+wcnt+w, sstart+s, 1);
                }
            }
        }
        
        return G.max_flow();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "G..X",
  "..XS",
  "W..." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "GG..",
  "....",
  "..W.",
  "..W.",
  "SS.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "GG..",
  "XX..",
  "..W.",
  "..W.",
  "SS.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"G.XXX.S",
 "G..WW.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WorkersOnPlane ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
