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

class CountingSeries {
public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
        long long sol = a<=upperBound ? (upperBound-a)/b + 1 : 0;
        if (d == 1) {
            return sol + (c<=upperBound && (c<a || (c-a)%b != 0));
        } else {
            long long val = c;
            while (1) {
                if (val > upperBound) {
                    break;
                }
                if (val<a || (val-a)%b!=0) {
                    ++sol;
                }
                if (val <= upperBound/d) {
                    val *= d;
                } else {
                    break;
                }
            }
            return sol;
        }
        return -1;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long a               = 1;
			long long b               = 1;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 1000;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 3;
			long long b               = 3;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 343;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 40;
			long long b               = 77;
			long long c               = 40;
			long long d               = 100000;
			long long upperBound      = 40;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 452;
			long long b               = 24;
			long long c               = 4;
			long long d               = 5;
			long long upperBound      = 600;
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long a               = 234;
			long long b               = 24;
			long long c               = 377;
			long long d               = 1;
			long long upperBound      = 10000;
			long long expected__      = 408;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
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
