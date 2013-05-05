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

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int dist(int a, int da, int b, int db) {
    if (a < b) {
        return dist(b, db, a, da);
    }
    if (b > 0) {
        a -= b;
    }
    int d = gcd(da, db);
    return min(a%d, d-a%d);
}
class FruitTrees {
public:
    int maxDist(int apple, int kiwi, int grape) {
        int sol = 0;
        for (int k=0; k<kiwi; ++k) {
            for (int g=0; g<grape; ++g) {
                int cand = min(dist(0, apple, k, kiwi), dist(0, apple, g, grape));
                cand = min(cand, dist(k, kiwi, g, grape));
                sol = max(sol, cand);
            }
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
			int apple                 = 1;
			int kiwi                  = 5;
			int grape                 = 8;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int apple                 = 3;
			int kiwi                  = 3;
			int grape                 = 6;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int apple                 = 40;
			int kiwi                  = 30;
			int grape                 = 20;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int apple                 = 899;
			int kiwi                  = 1073;
			int grape                 = 1147;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int apple                 = 2000;
			int kiwi                  = 2000;
			int grape                 = 2000;
			int expected__            = 666;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
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
