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

class BallAndHats {
public:
    int getHat(string hats, int numSwaps) {
        int at = -1;
        for (int i=0; i<3; ++i) {
            if (hats[i] == 'o') {
                at = i;
                break;
            }
        }
        assert(at != -1);
        if (numSwaps == 0) {
            return at;
        }
        return (numSwaps+(at!=1)+1)&1;
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
			string hats               = ".o.";
			int numSwaps              = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string hats               = "..o";
			int numSwaps              = 0;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string hats               = "o..";
			int numSwaps              = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string hats               = "..o";
			int numSwaps              = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string hats               = "o..";
			int numSwaps              = 101;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
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
