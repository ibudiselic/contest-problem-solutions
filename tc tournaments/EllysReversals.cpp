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

int pair_repr(char a, char b) {
    if (a > b) {
        return pair_repr(b, a);
    }
    return (a-'a')*26 + (b-'a');
}
vector<int> repr(const string &s) {
    vector<int> ret;
    for (int i=0; 2*i+1<(int)s.size(); ++i) {
        ret.push_back(pair_repr(s[2*i], s[2*i+1]));
    }
    sort(ret.begin(), ret.end());
    if (s.size() & 1) {
        ret.push_back(-1);
        ret.push_back(s[s.size()-1]-'a');
    }
    return ret;
}
class EllysReversals {
public:
    int getMin(vector <string> words) {
        vector< vector<int> > W;
        for (int i=0; i<(int)words.size(); ++i) {
            W.push_back(repr(words[i]));
        }

        int n = W.size();
        int sol = n;
        vector<char> dead(n, 0);
        for (int i=0; i<n; ++i) {
            if (dead[i]) continue;
            for (int j=i+1; j<n; ++j) {
                if (dead[j]) continue;
                if (W[i] == W[j]) {
                    dead[i] = dead[j] = 1;
                    sol -= 2;
                    break;
                }
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
			string words[]            = {"esprit", "god", "redotopc", "odcpoter", "dog"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"no", "zaphod", "just", "very", "improbable"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt", "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux", "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut", "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda", "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
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
