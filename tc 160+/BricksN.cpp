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
int lenways[51];
int dp[51][51][2][2];
int H;
int go(int h, int len, int can_empty, int must_empty) {
    if (must_empty) {
        assert(can_empty);
    }
    int &ret = dp[h][len][can_empty][must_empty];
    if (ret != -1) {
        return ret;
    }
    if (h==H || len==0) {
        return (ret = 1);
    }
    
    ret = 0;
    if (must_empty) {
        for (int empty=1; empty<=len; ++empty) {
            ret += go(h, len-empty, 0, 0);
            if (ret >= mod) {
                ret -= mod;
            }
        }
    } else if (can_empty) {
        ret = go(h, len, 0, 0) + go(h, len, 1, 1);
        if (ret >= mod) {
            ret -= mod;
        }
    } else {
        for (int sz=1; sz<=len; ++sz) {
            ret += (long long)lenways[sz]*go(h+1, sz, 1, 0)%mod*go(h, len-sz, 1, 1)%mod;
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }

    return ret;
}
class BricksN {
public:
    int countStructures(int w, int h, int k) {
        lenways[0] = 1;
        for (int len=1; len<=w; ++len) {
            lenways[len] = 0;
            for (int first=1; first<=min(k, len); ++first) {
                lenways[len] += lenways[len-first];
                if (lenways[len] >= mod) {
                    lenways[len] -= mod;
                }
            }
        }
        memset(dp, 0xff, sizeof dp);
        H = h;
        return go(0, w, 1, 0);
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
			int w                     = 3;
			int h                     = 1;
			int k                     = 3;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 2;
			int k                     = 3;
			int expected__            = 83;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 1;
			int h                     = 5;
			int k                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 10;
			int h                     = 10;
			int k                     = 3;
			int expected__            = 288535435;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int w                     = ;
			int h                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int w                     = ;
			int h                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w                     = ;
			int h                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
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
