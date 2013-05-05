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

int A[30], B[30];
int N, M;

int vis;
int proc;
bool G[6][6];
bool cyc(int u) {
    if (proc & (1<<u)) {
        return true;
    }
    if (vis & (1<<u)) {
        return false;
    }
    vis |= (1<<u);
    proc |= (1<<u);
    for (int v=0; v<N; ++v) {
        if (G[u][v] && cyc(v)) {
            return true;
        }
    }
    proc ^= (1<<u);
    return false;
}
bool is_dag(int u) {
    vis = 0;
    proc = 0;
    return !cyc(u);
}

vector<int> C;
int L, H;
char indeg[6], outdeg[6];
int flow[14][14];
int SOURCE = 0;
int SINK = 1;
int INF = 1<<30;
inline int in_node(int i) {
    return 2 + 2*i;
}
inline int out_node(int i) {
    return 2 + 2*i + 1;
}
char P[14];
bool can_augment() {
    memset(P, 0xff, sizeof P);
    queue<int> Q;
    Q.push(SOURCE);
    P[SOURCE] = -2;
    int n = 2*N + 2;
    while (Q.size() > 0) {
        int u = Q.front();
        Q.pop();
        for (int v=0; v<n; ++v) {
            if (flow[u][v]>0 && P[v]==-1) {
                P[v] = char(u);
                Q.push(v);
            }
        }
    }
    return P[SINK] != -1;
}
bool is_valid() {
    memset(indeg, 0, sizeof indeg);
    memset(outdeg, 0, sizeof outdeg);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (G[i][j]) {
                ++indeg[j];
                ++outdeg[i];
            }
        }
    }
    for (int i=0; i<N; ++i) {
        if (C[i]<indeg[i] || C[i]<outdeg[i]) {
            return false;
        }
    }

    int need = 0;
    memset(flow, 0, sizeof flow);
    for (int i=0; i<N; ++i) {
        if (indeg[i] > 0) {
            flow[SOURCE][in_node(i)] = C[i] - indeg[i];
            need += C[i] - indeg[i];
        }
        flow[out_node(i)][SINK] = C[i] - outdeg[i];
        for (int j=0; j<N; ++j) {
            if (G[i][j]) {
                flow[in_node(j)][out_node(i)] = INF;
            }
        }
    }

    int total = 0;
    while (can_augment()) {
        int v = SINK;
        int add = INF;
        do {
            int u = P[v];
            add = min(add, flow[u][v]);
            v = u;
        } while (v != SOURCE);
        v = SINK;
        do {
            int u = P[v];
            flow[u][v] -= add;
            flow[v][u] += add;
            v = u;
        } while (v != SOURCE);
        total += add;
    }
    assert(total <= need);
    return total == need;
}

int ntopsort_memo[1<<13];
int ntopsorts(int used) {
    int &ret = ntopsort_memo[used];
    if (ret != -1) {
        return ret;
    }
    if (used == (1<<N)-1) {
        return (ret = 1);
    }
    ret = 0;
    for (int i=0; i<N; ++i) {
        if (used & (1<<i)) continue;
        bool ok = true;
        for (int j=0; j<N; ++j) {
            if (!(used & (1<<j)) && G[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ret += ntopsorts(used | (1<<i));
        }
    }
    return ret;
}
int ntopsorts() {
    memset(ntopsort_memo, 0xff, sizeof ntopsort_memo);
    return ntopsorts(0);
}

int gen(int used, int layer_mask, int prev_layer) {
    if (used == (1<<N)-1) {
        if (!is_valid()) {
            return 0;
        }
        int ways = ntopsorts();
        assert(ways > 0);
        return L<=ways && ways<=H;
    } else {
        int ret = 0;
        if (layer_mask > 0) {
            ret += gen(used, 0, layer_mask);
        }
        for (int i=0; i<N; ++i) {
            if (used & (1<<i)) continue;
            if ((1<<i) < layer_mask) continue;

            if (prev_layer == 0) { // floor
                ret += gen(used|(1<<i), layer_mask|(1<<i), 0);
            }
            for (int s=prev_layer; s>0; s=(s-1)&prev_layer) {
                for (int j=0; j<N; ++j) {
                    if (s & (1<<j)) {
                        G[j][i] = 1;
                    }
                }
                ret += gen(used|(1<<i), layer_mask|(1<<i), prev_layer);
                for (int j=0; j<N; ++j) {
                    if (s & (1<<j)) {
                        G[j][i] = 0;
                    }
                }
            }
        }
        return ret;
    }
}
class CosmicBlocks {
public:
    int getNumOrders(vector <int> C, int lo, int hi) {
        L = lo;
        H = hi;
        ::C = C;
        N = C.size();
        M = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (i == j) continue;
                A[M] = i;
                B[M] = j;
                ++M;
            }
        }

        int sol = gen(0, 0, 0);
        return sol;
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
			int blockTypes[]          = {2,2,2};
			int minWays               = 1;
			int maxWays               = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int blockTypes[]          = {1,1,1,1,1,1};
			int minWays               = 720;
			int maxWays               = 720;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int blockTypes[]          = {2,2};
			int minWays               = 1;
			int maxWays               = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int blockTypes[]          = {1,2};
			int minWays               = 1;
			int maxWays               = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int blockTypes[]          = {1};
			int minWays               = 1;
			int maxWays               = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int blockTypes[]          = {1,2,4,8};
			int minWays               = 5;
			int maxWays               = 30;
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int blockTypes[]          = {1,2,3,4,5,6};
			int minWays               = 1;
			int maxWays               = 720;
			int expected__            = 4445;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int blockTypes[]          = {7500,1000,7500,1000,7500};
			int minWays               = 8;
			int maxWays               = 88;
			int expected__            = 448;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int blockTypes[]          = ;
			int minWays               = ;
			int maxWays               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int blockTypes[]          = ;
			int minWays               = ;
			int maxWays               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int blockTypes[]          = ;
			int minWays               = ;
			int maxWays               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CosmicBlocks().getNumOrders(vector <int>(blockTypes, blockTypes + (sizeof blockTypes / sizeof blockTypes[0])), minWays, maxWays);
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
