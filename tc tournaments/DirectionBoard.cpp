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
#include <utility>
#include <set>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

struct edge_t {
    int from, to, res_cap, cost, rev_idx;
    edge_t(int from_, int to_, int cap_, int cost_): from(from_), to(to_), res_cap(cap_), cost(cost_) {}
};
const int inf = 987654321;
class FlowNetwork {
    public:
    int add_source() { return source = add_vertex(); }
    int add_sink() { return sink = add_vertex(); }
    int add_vertex() {
        edges.push_back(vector<edge_t>());
        return int(edges.size()) - 1;
    }
    void add_edge(int from, int to, int cap, int cost) {
        edges[from].push_back(edge_t(from, to, cap, cost));
        edges[to].push_back(edge_t(to, from, 0, -cost));
        edges[from].back().rev_idx = edges[to].size() - 1;
        edges[to].back().rev_idx = edges[from].size() - 1;
    }
    void batch_add(int cnt) {
        while (cnt--) {
            add_vertex();
        }
    }
    pair<int, int> mcmf() {
        vector<edge_t*> P(edges.size(), 0);
        int cost = 0;
        int flow = 0;
        while (can_augment(P)) {
            int u = sink;
            int increment = inf;
            while (u != source) {
                edge_t *e = P[u];
                increment = min(increment, e->res_cap);
                u = e->from;
            }
            u = sink;
            while (u != source) {
                edge_t *e = P[u];
                e->res_cap -= increment;
                cost += increment * e->cost;
                edges[e->to][e->rev_idx].res_cap += increment;
                u = e->from;
            }
            flow += increment;
        }
        return make_pair(cost, flow);
    }
    private:
    bool can_augment(vector<edge_t*> &P) {
        fill(P.begin(), P.end(), static_cast<edge_t*>(0));
        vector<int> best(edges.size(), inf);
        set<int> active;
        active.insert(source);
        best[source] = 0;
        while (active.size() > 0) {
            set<int> next_active;
            for (set<int>::const_iterator it=active.begin(); it!=active.end(); ++it) {
                int u = *it;
                for (int i=0; i<(int)edges[u].size(); ++i) {
                    edge_t *e = &edges[u][i];
                    int v = e->to;
                    if (e->res_cap>0 && best[u]+e->cost<best[v]) {
                        best[v] = best[u] + e->cost;
                        next_active.insert(v);
                        P[v] = e;
                    }
                }
            }
            active.swap(next_active);
        }
        return P[sink] != 0;
    }
    int source, sink;
    vector< vector<edge_t> > edges;
};

class DirectionBoard {
public:
    int getMinimum(vector <string> board) {
        string dirs = "URDL";

        FlowNetwork G;
        int source = G.add_source();
        int sink = G.add_sink();

        int m = board.size();
        int n = board[0].size();
        G.batch_add(2*m*n);
#define IN(i,j) (2*((i)*n+(j))+2)
#define OUT(i,j) (2*((i)*n+(j))+3)
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                G.add_edge(source, IN(i, j), 1, 0);
                G.add_edge(OUT(i, j), sink, 1, 0);
                for (int d=0; d<4; ++d) {
                    int r = i + di[d];
                    int c = j + dj[d];
                    if (r < 0) r = m-1;
                    if (r == m) r = 0;
                    if (c < 0) c = n-1;
                    if (c == n) c = 0;
                    G.add_edge(IN(i, j), OUT(r, c), 1, board[i][j]!=dirs[d]);
                }
            }
        }

        return G.mcmf().first;
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string board[]            = {"RRRD", "URDD", "UULD", "ULLL"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"RRRD", "URLL", "LRRR"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"RRD", "URD", "ULL"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"ULRLRD", "UDDLRR"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"UDLRLDLD", "DLDLLDLR", "LLLLLDLD", "UUURRRDD"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"UDUDUUDUDUDUDUR", "LLLLDUUDRDLUDRU", "DLLDLDURDURUDDL", "UDUDUUDUDUDUDUR", "LLLLDUUDRDLUDRU", "DLLDLDURDURUDDL", "UDUDUUDUDUDUDUR", "LLLLDUUUDDLUDRU", "DLLDLDURDURUDDL", "UDUDUUDUDUDUDUR", "LLLLDUUDRDLUDRU", "DLLDLDURDURUDDL", "UDUDUUDUDUDUDUR", "LLLLDUUDRDLUDRU", "RRRDLDURDURUDDR"} ;
			int expected__            = 73;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
