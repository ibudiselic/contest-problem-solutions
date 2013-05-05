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

int cand(int n, int d, int first, int last) {
    int ret = last;
    for (int i=2; i<n; ++i) {
        first += d;
        if (abs(first-last) > (n-i)*d) {
            first -= abs(first-last)-(n-i)*d;
            break;
        }
        ret = max(ret, first);
    }

    return max(ret, first);
}
class TheArray {
public:
    int find(int n, int d, int first, int last) {
        return max(cand(n, d, first, last), cand(n, d, last, first));
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
			int n                     = 3;
			int d                     = 5;
			int first                 = 2;
			int last                  = 4;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int d                     = 100;
			int first                 = 999;
			int last                  = 100;
			int expected__            = 999;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1000000;
			int d                     = 0;
			int first                 = 474;
			int last                  = 474;
			int expected__            = 474;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 97;
			int d                     = 53;
			int first                 = -92;
			int last                  = 441;
			int expected__            = 2717;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 99;
			int d                     = 3;
			int first                 = -743;
			int last                  = -619;
			int expected__            = -535;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
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
