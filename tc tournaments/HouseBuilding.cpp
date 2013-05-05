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

int calc1(const vector<string> &area, int target) {
    int m = area.size();
    int n = area[0].size();
    int ret = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int have = area[i][j]-'0';
            if (have > target) {
                ret += have-1-target;
            } else {
                ret += target-have;
            }
        }
    }
    return ret;
}
int calc2(const vector<string> &area, int target) {
    int m = area.size();
    int n = area[0].size();
    int ret = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int have = area[i][j]-'0';
            if (have >= target) {
                ret += have-target;
            } else {
                ret += target-have-1;
            }
        }
    }
    return ret;
}
class HouseBuilding {
public:
    int getMinimum(vector <string> area) {
        int sol = 12345678;
        for (int target=0; target<10; ++target) {
            sol = min(sol, min(calc1(area, target), calc2(area, target)));
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
			string area[]             = {"10", "31"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string area[]             = {"54454", "61551"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string area[]             = {"989"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string area[]             = {"90"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string area[]             = {"5781252", "2471255", "0000291", "1212489"};
			int expected__            = 53;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
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
