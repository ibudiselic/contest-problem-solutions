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
#include <utility>

using namespace std;

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
struct frac {
    int a, b;
    frac(int a_, int b_): a(a_), b(b_) { norm(); }
    void norm() {
        int d = gcd(a, b);
        a /= d;
        b /= d;
    }
};
bool operator<(const frac &x, const frac &y) {
    return (long long)x.a*y.b < (long long)x.b*y.a;
}
bool operator==(const frac &x, const frac &y) {
    return x.a==y.a && x.b==y.b;
}
bool operator<=(const frac &x, const frac &y) {
    return x==y || x<y;
}

bool ok(const frac &step, long long D, const vector<int> &L, const vector<int> &R) {
    for (int i=0; i<(int)L.size(); ++i) {
        long long nsteps = (long long)L[i]*step.b/step.a + 1;
        if (nsteps*step.a < (long long)R[i]*step.b) {
            return false;
        }
    }
    return true;
}
frac minstep(1, 1);
frac test(int x, int D, const vector<int> &L, const vector<int> &R) {
    frac best(D, 1);
    frac cand(x, 1);
    int denom = 1;
    while (minstep <= cand) {
        if (ok(cand, D, L, R)) {
            best = cand;
        }
        cand = frac(x, ++denom);
    }
    return best;
}
class TheFrog {
public:
    double getMinimum(int D, vector <int> L, vector <int> R) {
        vector<pair<int, int> > v;
        for (int i=0; i<(int)L.size(); ++i) {
            v.push_back(make_pair(L[i], R[i]));
        }
        sort(v.begin(), v.end());
        for (int i=0; i<(int)L.size(); ++i) {
            L[i] = v[i].first;
            R[i] = v[i].second;
        }

        frac sol(D, 1);
        minstep = sol;
        for (int i=0; i<(int)L.size(); ++i) {
            minstep = min(minstep, frac(R[i]-L[i], 1));
        }
        for (int i=0; i<(int)L.size(); ++i) {
            sol = min(sol, test(L[i], D, L, R));
            sol = min(sol, test(R[i], D, L, R));
        }

        return double(sol.a)/sol.b;
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
			int D                     = 16;
			int L[]                   = {2};
			int R[]                   = {7};
			double expected__         = 7.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int D                     = 25;
			int L[]                   = {11, 3};
			int R[]                   = {21, 7};
			double expected__         = 10.5;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int D                     = 100;
			int L[]                   = {0};
			int R[]                   = {100};
			double expected__         = 100.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int D                     = 100;
			int L[]                   = {0, 50};
			int R[]                   = {50, 100};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int D                     = 30000;
			int L[]                   = {17, 25281, 5775, 2825, 14040};
			int R[]                   = {55, 26000, 5791, 3150, 14092};
			double expected__         = 787.8787878787879;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int D                     = 30000;
			int L[]                   = {10132,10609,10877,11197,11386,11807,12119,12488,12996,13324,13542,14023,14333,14393,14683,14734,14932,15212,15473,15783,16296,16723,17180,17716,18177,18212,18360,18508,18644,18921,19406,19628,19890,19991,20085,20616,20746,21109,21514,21588,21871,21974,22145,22202,22622,23103,23285,23370,23688,23798};
			int R[]                   = {10151,10611,10921,11200,11391,11836,12159,12513,13024,13357,13577,14031,14336,14420,14705,14750,14976,15235,15501,15826,16303,16725,17226,17740,18180,18228,18397,18534,18675,18933,19445,19645,19898,19997,20117,20642,20792,21132,21560,21604,21873,21978,22146,22229,22625,23121,23286,23392,23730,23817};
			double expected__         = 132.57;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int D                     = ;
			int L[]                   = ;
			int R[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheFrog().getMinimum(D, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
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
