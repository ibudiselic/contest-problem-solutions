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

int start_dir;
double one(int n, int *di, int *dj) {
    double ret = 0.0;
    double p = 1.0/n/n;
    for (int d=start_dir; d<9; ++d) {
        int dr = di[d];
        int dc = dj[d];
        double r_range = max(0, min(n, n-dr) - max(0, -dr));
        double c_range = max(0, min(n, n-dc) - max(0, -dc));
        ret += r_range*c_range*p;
    }
    return ret;
}
double two(int n, int *di, int *dj) {
    double ret = 0.0;
    double N = double(n)*n;
    double p = 2/N/(N-1);
    for (int d1=start_dir; d1<9; ++d1) {
        for (int d2=d1+1; d2<9; ++d2) {
            double maxr = min(n, min(n-di[d1], n-di[d2]));
            double minr = max(0, max(-di[d1], -di[d2]));
            double maxc = min(n, min(n-dj[d1], n-dj[d2]));
            double minc = max(0, max(-dj[d1], -dj[d2]));
            ret += p * max(0.0, maxr-minr) * max(0.0, maxc-minc);
        }
    }
    return ret;
}

class TheKnights {
public:
    double find(int n, int a, int b) {
        int di[] = { -b, -b,  b, b, 0, -a, -a,  a, a };
        int dj[] = { -a,  a, -a, a, 0, -b,  b, -b, b };
        start_dir = (a==b ? 4 : 0);

        return 2*one(n, di, dj) - two(n, di, dj);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int n                     = 2;
			int a                     = 1;
			int b                     = 1;
			double expected__         = 3.3333333333333335;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 47;
			int a                     = 7;
			int b                     = 74;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			int a                     = 2;
			int b                     = 1;
			double expected__         = 4.888888888888889;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 9999;
			int a                     = 999;
			int b                     = 99;
			double expected__         = 16.25885103191273;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 10;
			int a                     = 1;
			int b                     = 6;
			double expected__         = 7.636363636363637;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int a                     = ;
			int b                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheKnights().find(n, a, b);
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
