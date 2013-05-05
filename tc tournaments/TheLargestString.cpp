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

typedef pair<string, string> pss;
pss extend(pss p, char a, char b) {
    p.first += a;
    p.second += b;
    return p;
}
string flatten(const pss &p) {
    return p.first + p.second;
}
class TheLargestString {
public:
    string find(string s, string t) {
        int n = s.size();
        vector< vector<pss> > best(n+1, vector<pss>(n+1, pss("", "")));
        for (int i=1; i<=n; ++i) {
            for (int len=1; len<i; ++len) {
                best[i][len] = max(best[i-1][len], extend(best[i-1][len-1], s[i-1], t[i-1]));
            }
            best[i][i] = extend(best[i-1][i-1], s[i-1], t[i-1]);
        }

        string sol;
        for (int len=1; len<=n; ++len) {
            sol = max(sol, flatten(best[n][len]));
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string s                  = "ab";
			string t                  = "zy";
			string expected__         = "by";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "abacaba";
			string t                  = "zzzaaaa";
			string expected__         = "cbaaaa";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "x";
			string t                  = "x";
			string expected__         = "xx";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "abbabbabbababaaaabbababab";
			string t                  = "bababbaabbbababbbbababaab";
			string expected__         = "bbbbbbbbbbbbbbbbbbaaab";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
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
