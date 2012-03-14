#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int ways[1<<10][1<<10]; // from i to j
int dp[2][1<<10];
class SmallBricks31 {
public:
    int countWays(int w, int h) {
        memset(ways, 0, sizeof ways);
        for (int i=0; i<(1<<w); ++i) {
            ways[i][0] = 1;
            for (int j=0; j<w; ++j) {
                if (i & (1<<j)) {
                    for (int oldmask=0; oldmask<(1<<j); ++oldmask) {
                        if (ways[i][oldmask] > 0) {
                            add(ways[i][oldmask | (1<<j)], ways[i][oldmask]);
                            if (j+1<w && (i&(1<<(j+1)))) {
                                add(ways[i][oldmask | (1<<j) | (1<<(j+1))], ways[i][oldmask]);
                            }
                            if (j+2<w && (i&(1<<(j+2)))) {
                                add(ways[i][oldmask | (1<<j) | (1<<(j+1)) | (1<<(j+2))], ways[i][oldmask]);
                            }
                        }
                    }
                }
            }
        }
        memset(dp[1], 0, sizeof dp[1]);
        dp[1][(1<<w)-1] = 1;
        for (int i=0; i<h; ++i) {
            int cur = i&1;
            int last = 1-cur;
            memset(dp[cur], 0, sizeof dp[cur]);
            for (int oldmask=0; oldmask<(1<<w); ++oldmask) {
                for (int newmask=0; newmask<(1<<w); ++newmask) {
                    add(dp[cur][newmask], (long long)dp[last][oldmask]*ways[oldmask][newmask]%mod);
                }
            }
        }
        
        long long sol = 0;
        for (int i=0; i<(1<<w); ++i) {
            sol += dp[(h+1)&1][i];
        }
        return int(sol%mod);
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
			int w                     = 1;
			int h                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 1;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 3;
			int h                     = 2;
			int expected__            = 84;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 4;
			int h                     = 9;
			int expected__            = 132976888;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int w                     = 5;
			int h                     = 5;
			int expected__            = 11676046;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
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
