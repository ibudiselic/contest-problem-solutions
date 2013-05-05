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

class EllysPairs {
public:
    int getDifference(vector <int> knowledge) {
        sort(knowledge.begin(), knowledge.end());
        const int inf = 123456789;
        int M = -inf;
        int m = +inf;
        for (int i=0; 2*i<(int)knowledge.size(); ++i) {
            int val = knowledge[i] + knowledge[knowledge.size()-1-i];
            M = max(M, val);
            m = min(m, val);
        }
        return M - m;
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
			int knowledge[]           = {2, 6, 4, 3};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int knowledge[]           = {1, 1, 1, 1, 1, 1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int knowledge[]           = {4, 2, 4, 2, 1, 3, 3, 7};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int knowledge[]           = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
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
