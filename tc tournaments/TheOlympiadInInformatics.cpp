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

bool ok(int S, const vector<int> &R, int k) {
    for (int i=0; i<(int)R.size(); ++i) {
        k -= R[i]/(S+1);
        if (k < 0) {
            return false;
        }
    }
    return true;
}
class TheOlympiadInInformatics {
public:
    int find(vector <int> sums, int k) {
        int lo = 0;
        int hi = 1000000000;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (ok(mid, sums, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
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
			int sums[]                = {4, 7, 0, 5};
			int k                     = 0;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int sums[]                = {4, 7};
			int k                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int sums[]                = {999999999};
			int k                     = 1000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int sums[]                = {95, 23, 87, 23, 82, 78, 59, 44, 12};
			int k                     = 70;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sums[]                = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheOlympiadInInformatics().find(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])), k);
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
