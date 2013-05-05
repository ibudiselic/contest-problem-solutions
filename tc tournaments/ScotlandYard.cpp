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
#include <set>
#include <queue>

using namespace std;

void gen(const vector<string> &A, vector<long long> &B) {
    for (int i=0; i<(int)A.size(); ++i) {
        long long mask = 0;
        for (int j=0; j<(int)A[i].size(); ++j) {
            if (A[i][j] == 'Y') {
                mask |= (1ll << j);
            }
        }
        B.push_back(mask);
    }
}

int node(int i, int j, int n) {
    assert(j > i);
    return n + i*n + j;
}

void gen_edges(int u, int n, long long mask, vector< set<int> > &G) {
    for (int i=0; i<n; ++i) {
        if (mask & (1ll<<i)) {
            for (int j=i+1; j<n; ++j) {
                if (mask & (1ll<<j)) {
                    G[u].insert(node(i, j, n));
                }
            }

            if ((mask & (mask-1)) == 0) {
                G[u].insert(i);
                break;
            }
        }
    }
}
void gen_edges(int i, int j, vector< set<int> > &G, const vector<long long> &A) {
    int n = A.size();
    gen_edges(node(i, j, n), n, A[i]|A[j], G);
}

void gen_edges(int i, vector< set<int> > &G, const vector<long long> &A) {
    gen_edges(i, int(A.size()), A[i], G);
}

void gen_edges(int i, vector< set<int> > &G, const vector<long long> &A, const vector<long long> &B, const vector<long long> &C) {
    gen_edges(i, G, A);
    gen_edges(i, G, B);
    gen_edges(i, G, C);
}

void gen_edges(int i, int j, vector< set<int> > &G, const vector<long long> &A, const vector<long long> &B, const vector<long long> &C) {
    gen_edges(i, j, G, A);
    gen_edges(i, j, G, B);
    gen_edges(i, j, G, C);
}

int vis_status[60*60];
bool ambiguous_cycle(int u, const vector< vector<int> > &G, int n) {
    if (vis_status[u] == 1) {
        return true;
    }
    if (vis_status[u] == 2) {
        return false;
    }
    vis_status[u] = 1;
    for (int j=0; j<(int)G[u].size(); ++j) {
        if (G[u][j]>=n && ambiguous_cycle(G[u][j], G, n)) {
            return true;
        }
    }
    vis_status[u] = 2;
    return false;
}

int solve(const vector< vector<int> > &G, int n) {
    memset(vis_status, 0, sizeof vis_status);
    for (int i=n; i<(int)G.size(); ++i) {
        if (vis_status[i]==0 && ambiguous_cycle(i, G, n)) {
            return -1;
        }
    }
    vector<int> indeg(G.size());
    for (int i=n; i<(int)G.size(); ++i) {
        for (int j=0; j<(int)G[i].size(); ++j) {
            if (G[i][j] >= n) {
                ++indeg[G[i][j]];
            }
        }
    }
    queue<int> Q;
    for (int i=n; i<(int)G.size(); ++i) {
        if (indeg[i] == 0) {
            Q.push(i);
        }
    }
    vector<int> tsort;
    while (Q.size() > 0) {
        int u = Q.front();
        Q.pop();
        tsort.push_back(u);
        for (int i=0; i<(int)G[u].size(); ++i) {
            if (G[u][i] >= n) {
                if (--indeg[G[u][i]] == 0) {
                    Q.push(G[u][i]);
                }
            }
        }
    }
    assert(tsort.size() == G.size()-n); // topsort exists since there are no cycles

    vector<int> longest(G.size(), 0);
    for (int i=0; i<(int)tsort.size(); ++i) {
        int u = tsort[i];
        for (int j=0; j<(int)G[u].size(); ++j) {
            if (G[u][j] >= n) {
                longest[G[u][j]] = max(longest[G[u][j]], longest[u] + 1);
            }
        }
    }
    int ret = 0;
    for (int i=n; i<(int)G.size(); ++i) {
        int cand = longest[i];
        for (int j=0; j<(int)G[i].size(); ++j) {
            if (G[i][j] < n) {
                ++cand; // can make one more step, but will get cought next
                break;
            }
        }
        ret = max(ret, cand);
    }
    return ret;
}

class ScotlandYard {
public:
    int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro) {
        int n = taxi.size();
        vector<long long> T, B, M;
        gen(taxi, T);
        gen(bus, B);
        gen(metro, M);

        vector< set<int> > G_tmp(n*(n+1));
        for (int i=0; i<n; ++i) {
            gen_edges(i, G_tmp, T, B, M);
            for (int j=i+1; j<n; ++j) {
                gen_edges(i, j, G_tmp, T, B, M);
            }
        }

        vector< vector<int> > G;
        for (int i=0; i<(int)G_tmp.size(); ++i) {
            G.push_back(vector<int>(G_tmp[i].begin(), G_tmp[i].end()));
        }

        return solve(G, n);
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
			string taxi[]             = {"NYN", "NNY", "NNN"};
			string bus[]              = {"NNN", "NNN", "NNN"};
			string metro[]            = {"NNN", "NNN", "NNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string taxi[]             = {"NYY", "NNN", "NNN"};
			string bus[]              = {"NNN", "NNN", "NNN"};
			string metro[]            = {"NNN", "NNN", "NNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string taxi[]             = {"NYYY", "YNYY", "YYNY", "YYYN"};
			string bus[]              = {"NNNN", "NNNN", "NNNN", "NNNN"};
			string metro[]            = {"NNNN", "NNNN", "NNNN", "NNNN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string taxi[]             = {"NNY", "NNY", "NNN"};
			string bus[]              = {"NYN", "NNY", "NNN"};
			string metro[]            = {"NNN", "NNN", "YNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string taxi[]             = {"NNN", "YNY", "NNN"};
			string bus[]              = {"NNN", "YNN", "YNN"};
			string metro[]            = {"NNN", "NNN", "YYN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string taxi[]             = {"NNNNYNNNYY", "NNYNNYYYYY", "NNNNNNNNNN", "YYNNYYNNNY", "NNYNNNNNNN", "YNYNYNNNYN", "NNYNYNNNYN", "NNNNNNYNNN", "NNNNNNNNNN", "NNNNNNYNNN"};
			string bus[]              = {"NNYNNNYNNY", "YNYNNYYNYY", "NNNNNNNNNN", "YNYNNYNYNY", "NNYNNNNNYN", "YNYNYNYNYN", "NNYNNNNNNY", "YNYNNNNNNN", "NNNNNNNNNN", "NNYNYNNNNN"};
			string metro[]            = {"NNNNNNNYNN", "YNYNNNNNYN", "NNNNNNNNNN", "NYNNYNNNYY", "NNYNNNNNNN", "YNYNNNNNYY", "NNNNYNNNYN", "NNYNNNYNNN", "NNNNNNNNNY", "NNYNYNNNNN"};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string taxi[]             = ;
			string bus[]              = ;
			string metro[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string taxi[]             = ;
			string bus[]              = ;
			string metro[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string taxi[]             = ;
			string bus[]              = ;
			string metro[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScotlandYard().maxMoves(vector <string>(taxi, taxi + (sizeof taxi / sizeof taxi[0])), vector <string>(bus, bus + (sizeof bus / sizeof bus[0])), vector <string>(metro, metro + (sizeof metro / sizeof metro[0])));
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
