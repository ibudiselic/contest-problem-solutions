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

int N;
int to[20];
int dp[1<<20];
int bc[1<<20];
int go(int mask) {
    int &ret = dp[mask];
    if (ret != -1) {
        return ret;
    }
    if (mask == (1<<N)-1) {
        ret = 0;
    } else {
        ret = 1234567;
        for (int i=0; i<N; ++i) {
            if (mask & (1<<i)) continue;
            ret = min(ret, bc[to[i]&mask] + go(mask | (1<<i)));
        }
    }
    return ret;
}
class OrderOfTheHats {
public:
    int minChanged(vector <string> A) {
        N = A.size();
        bc[0] = 0;
        for (int mask=1; mask<(1<<N); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }
        int base = 0;
        for (int i=0; i<N; ++i) {
            if (A[i][i] == 'Y') {
                ++base;
                A[i][i] = 'N';
            }
        }
        for (int i=0; i<N; ++i) {
            to[i] = 0;
            for (int j=0; j<N; ++j) {
                if (A[i][j] == 'Y') {
                    to[i] |= 1<<j;
                }
            }
        }
        memset(dp, 0xff, sizeof dp);
        return base + go(0);
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
			string spellChart[]       = {"Y"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string spellChart[]       = {"NYN", "NNY", "NNN"} ;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string spellChart[]       = {"NYN", "NNY", "YNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string spellChart[]       = {"NYYYYYY", "YNYYYYY", "YYNYYYY", "YYYNYYY", "YYYYNYY", "YYYYYNY", "YYYYYYN"};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string spellChart[]       = {"NNNY", "YNYN", "YNNN", "YYYN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string spellChart[]       = {"YYYYYNNYYYNYNNNNYNNY", "NYNNNYYNNYNYYYNYYYYY", "NNYNNNYYNNNNNNYYYYNY", "YYNYNYYNNYYYNYNNNYYY", "NYYNNYNYNYNNNNYYYNYN", "NNNNNYYNYNNYYYYNYYYN", "YNYNYYNNNYNNNNNYNNYY", "NYYYYNYNYNNYNNYNNNNY", "YYYYNYYNNYYYNNYNNYNY", "YYYYYYNYNYNYNNNNNNYN", "NNYYYYYNNNYNNNYNNNNY", "YYNNNYNYYNYYNYYNYNYN", "NNYNYYNYYNYYNYNYNYYN", "YNYNYYNYNNNYNYNYYNYY", "NNYNNNYYYYYYYYYYYNYY", "YYYYYNYYNYYYYYNNYNNN", "NYYYYYYYYNNNNNYYNNYN", "YNNYNNNYYNYYYNYNYYYY", "YYNNYNYYYNYYNNNYYNNY", "NNYNYNYYYNYYNYNNYNNN"};
			int expected__            = 79;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string spellChart[]       = {"YYNYNN", "YNYNNY", "YYYYNN", "NNNYNN", "NNNYNN", "YNYNYN"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			string spellChart[]       = {"NNNNNNNNNN", "NNNNNNNNNN", "NNNYNNYNNN", "NNNYNNYNNN", "NNNYNNYNNN", "NNNNNNNNNN", "NNYYYYYYNN", "NNYNNNNYNN", "NNNYYYYNNN", "NNNNNNNNNN"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
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
