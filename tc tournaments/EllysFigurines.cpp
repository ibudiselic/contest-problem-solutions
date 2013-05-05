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

const int inf = 12345;
bool B[15][15];
int Rmask[15];
int m;
int n;
int R, C;
int cols(int mask) {
    int ret = 0;
    for (int j=0; j<n; ++j) {
        if (mask & (1<<j)) {
            ++ret;
            j += C - 1;
        }
    }
    return ret;
}
int colmask;
int go(int r) {
    if (r >= m) {
        return 0;
    } else {
        if (Rmask[r] & ~colmask) {
            return 1 + go(r+R);
        } else {
            return go(r+1);
        }
    }
}
class EllysFigurines {
public:
    int getMoves(vector <string> board, int R, int C) {
        ::R = R;
        ::C = C;
        m = board.size();
        n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                B[i][j] = (board[i][j] == 'X');
            }
        }

        for (int i=0; i<m; ++i) {
            int mask = 0;
            for (int j=0; j<n; ++j) {
                if (B[i][j]) {
                    mask |= (1<<j);
                }
            }
            Rmask[i] = mask;
        }

        int sol = inf;
        for (colmask=0; colmask<(1<<n); ++colmask) {
            sol = min(sol, go(0) + cols(colmask));
        }
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
			string board[]            = {".X.X.", "XX..X", ".XXX.", "...X.", ".X.XX"};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".X.X.", "XX..X", ".X.X.", "...X.", ".X.XX"};
			int R                     = 2;
			int C                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"XXXXXXX"};
			int R                     = 2;
			int C                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"XXXXX", "X....", "XXX..", "X....", "XXXXX"};
			int R                     = 1;
			int C                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"XXX..XXX..XXX.", ".X..X....X...X", ".X..X....X...X", ".X..X....X...X", ".X...XXX..XXX.", "..............", "...XX...XXX...", "....X......X..", "....X....XXX..", "....X......X..", "...XXX..XXX..."};
			int R                     = 1;
			int C                     = 2;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int R                     = ;
			int C                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysFigurines().getMoves(vector <string>(board, board + (sizeof board / sizeof board[0])), R, C);
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
