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

bool G[50][50];
int m, n;
int match[50];
int rmatch[50];
bool used[50];
bool can_match(int i) {
    used[i] = 1;
    for (int j=0; j<n; ++j) {
        if (G[i][j] && (rmatch[j]==-1 || !used[rmatch[j]] && can_match(rmatch[j]))) {
            match[i] = j;
            rmatch[j] = i;
            return true;
        }
    }
    return false;
}
int maxmatch() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    int sol = 0;
    for (int i=0; i<m; ++i) {
        if (match[i] == -1) {
            memset(used, 0, sizeof used);
            sol += can_match(i);
        }
    }
    return sol;
}
class PointyWizardHats {
public:
    int getNumHats(vector <int> ht, vector <int> rt, vector <int> hb, vector <int> rb) {
        m = ht.size();
        n = hb.size();
        memset(G, 0, sizeof G);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (rb[j]>rt[i] && ht[i]*rb[j]>hb[j]*rt[i]) {
                    G[i][j] = 1;
                }
            }
        }

        return maxmatch();
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
			int topHeight[]           = {30};
			int topRadius[]           = {3};
			int bottomHeight[]        = {3};
			int bottomRadius[]        = {30};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int topHeight[]           = {4,4};
			int topRadius[]           = {4,3};
			int bottomHeight[]        = {5,12};
			int bottomRadius[]        = {5,4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int topHeight[]           = {3};
			int topRadius[]           = {3};
			int bottomHeight[]        = {1,1};
			int bottomRadius[]        = {2,4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int topHeight[]           = {10,10};
			int topRadius[]           = {2,5};
			int bottomHeight[]        = {2,9};
			int bottomRadius[]        = {3,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int topHeight[]           = {3,4,5};
			int topRadius[]           = {5,4,3};
			int bottomHeight[]        = {3,4,5};
			int bottomRadius[]        = {3,8,5};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int topHeight[]           = {1,2,3,4,5};
			int topRadius[]           = {2,3,4,5,6};
			int bottomHeight[]        = {2,3,4,5,6};
			int bottomRadius[]        = {1,2,3,4,5};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int topHeight[]           = {123,214,232,323,342,343};
			int topRadius[]           = {123,123,232,123,323,434};
			int bottomHeight[]        = {545,322,123,545,777,999};
			int bottomRadius[]        = {323,443,123,656,767,888};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int topHeight[]           = {999,999,999,10000,10000,10000};
			int topRadius[]           = {10000,10000,10000,1,2,3};
			int bottomHeight[]        = {2324,2323,234,5454,323,232};
			int bottomRadius[]        = {1,2,3222,434,5454,23};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats(vector <int>(topHeight, topHeight + (sizeof topHeight / sizeof topHeight[0])), vector <int>(topRadius, topRadius + (sizeof topRadius / sizeof topRadius[0])), vector <int>(bottomHeight, bottomHeight + (sizeof bottomHeight / sizeof bottomHeight[0])), vector <int>(bottomRadius, bottomRadius + (sizeof bottomRadius / sizeof bottomRadius[0])));
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
