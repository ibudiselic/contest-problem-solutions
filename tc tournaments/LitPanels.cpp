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

using namespace std;

int A, B;
int DX, DY;
const int mod = 1000000007;

int dp[41][41][2][2][2][2];
int ways(int x, int y, bool top, bool bottom, bool left, bool right) {
    int &ret = dp[x][y][top][bottom][left][right];
    if (ret != -1) {
        return ret;
    }
    if (x == DX) {
        assert(top);
        ret = bottom && left && right;
    } else if (y == DY) {
        if (x==0 && !top) {
            ret = 0;
        } else {
            ret = ways(x+1, 0, top, bottom, left, right);
        }
    } else {
        ret = ways(x, y+1, top, bottom, left, right);
        if ((x<A && y<B) || (DX-x<=A && DY-y<=B)) {
            ret += ways(x, y+1, top||(x==0), bottom||(x==DX-1), left||(y==0), right||(y==DY-1));
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    return ret;
}
int sym_dp[41][41][2][2][2][2];
int sym_ways(int x, int y, bool top, bool bottom, bool left, bool right) {
    int &ret = sym_dp[x][y][top][bottom][left][right];
    if (ret != -1) {
        return ret;
    }
    if (x == DX) {
        assert(top);
        ret = bottom && left && right;
    } else if (y == DY) {
        if (x==0 && !top) {
            ret = 0;
        } else {
            ret = sym_ways(x+1, 0, top, bottom, left, right);
        }
    } else {
        ret = sym_ways(x, y+1, top, bottom, left, right);
        if ((x<A && DX-x<=A) || (y<B && DY-y<=B)) {
            ret += sym_ways(x, y+1, top||(x==0), bottom||(x==DX-1), left||(y==0), right||(y==DY-1));
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    return ret;
}

int cnt[41][41];
class LitPanels {
public:
    int countPatterns(int X, int Y, int sx, int sy) {
        A = sx;
        B = sy;

        for (DX=1; DX<=X; ++DX) {
            for (DY=1; DY<=Y; ++DY) {
                memset(dp, 0xff, sizeof dp);
                cnt[DX][DY] = ways(0, 0, 0, 0, 0, 0);
                if (DX>A && DY>B) {
                    cnt[DX][DY] *= 2;
                    if (cnt[DX][DY] >= mod) {
                        cnt[DX][DY] -= mod;
                    }
                    memset(sym_dp, 0xff, sizeof sym_dp);
                    cnt[DX][DY] -= sym_ways(0, 0, 0, 0, 0, 0);
                    if (cnt[DX][DY] < 0) {
                        cnt[DX][DY] += mod;
                    }
                }
            }
        }
        long long sol = 1;
        for (int x1=0; x1<X; ++x1) {
            for (int x2=x1; x2<X; ++x2) {
                for (int y1=0; y1<Y; ++y1) {
                    for (int y2=y1; y2<Y; ++y2) {
                        sol += cnt[x2-x1+1][y2-y1+1];
                    }
                }
            }
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
			int X                     = 2;
			int Y                     = 2;
			int sx                    = 1;
			int sy                    = 1;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int X                     = 2;
			int Y                     = 3;
			int sx                    = 1;
			int sy                    = 2;
			int expected__            = 40;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int X                     = 4;
			int Y                     = 4;
			int sx                    = 3;
			int sy                    = 2;
			int expected__            = 14096;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int X                     = 40;
			int Y                     = 39;
			int sx                    = 5;
			int sy                    = 8;
			int expected__            = 877713074;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int X                     = ;
			int Y                     = ;
			int sx                    = ;
			int sy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int X                     = ;
			int Y                     = ;
			int sx                    = ;
			int sy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X                     = ;
			int Y                     = ;
			int sx                    = ;
			int sy                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LitPanels().countPatterns(X, Y, sx, sy);
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
