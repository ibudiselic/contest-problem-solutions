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
#include <set>

using namespace std;

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
long long lcm(long long m, long long n) {
    return m/gcd(m, n)*n;
}
long long LCM[1<<15];
int LG[1<<15];
int bc[1<<15];
long long divs(long long A, const vector<int> &D) {
    int n = D.size();
    assert(n <= 15);
    LCM[0] = 1;
    long long ret = 0;
    for (int mask=1; mask<(1<<n); ++mask) {
        LCM[mask] = lcm(LCM[mask&(mask-1)], D[LG[mask&-mask]]);
        ret += ((bc[mask]&1) ? +1 : -1) * (A/LCM[mask]);
    }
    assert(ret >= 0);
    return ret;
}
long long nums(int A, int B) {
    long long ret = 0;
    for (int i=1; i<=A; ++i) {
        vector<int> vals;
        for (int j=i; j<=A; ++j) {
            for (int k=0; k<(int)vals.size(); ++k) {
                if (j % vals[k] == 0) {
                    goto SKIP;
                }
            }
            vals.push_back(j);
            SKIP:;
        }
        ret += divs((long long)i*B, vals) - divs((long long)(i-1)*B, vals);
    }
    assert(ret >= 0);
    return ret;
}
class ThePowers {
public:
    long long find(int A, int B) {
        for (int i=0; i<15; ++i) {
            LG[1<<i] = i;
        }
        for (int mask=1; mask<(1<<15); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }
        int cnt[30] = {0};
        cnt[1] = A - 1;
        set<int> used;
        for (int base=2; base*base<=A; ++base) {
            if (!used.count(base)) {
                int x = base;
                int sz = 1;
                while (x <= A/base) {
                    ++sz;
                    x *= base;
                    used.insert(x);
                }
                cnt[1] -= sz;
                ++cnt[sz];
            }
        }
        long long sol = 1;
        for (int i=1; i<30; ++i) {
            sol += cnt[i] * nums(i, B);
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
			int A                     = 7;
			int B                     = 4;
			long long expected__      = 23;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 1;
			int B                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 1000000000;
			int B                     = 1000000000;
			long long expected__      = 999983644283653287LL;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 999999999;
			int B                     = 5;
			long long expected__      = 4999934406LL;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ThePowers().find(A, B);
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
