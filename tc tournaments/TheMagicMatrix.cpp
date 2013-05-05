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

const long long mod = 1234567891ll;
int expmod(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) ret = ret*n%mod;
        n = n*n%mod;
        k /= 2;
    }
    return int(ret);
}

long long ways(vector< vector<int> > A, vector<int> b, int p) {
    int m = b.size();
    int n = A[0].size();
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            A[i][j] = (A[i][j]%p + p)%p;
        }
        b[i] = (b[i]%p + p)%p;
    }

    int rank = 0;
    vector<char> used(m, 0);
    for (int j=0; j<n; ++j) {
        int i = 0;
        while (i<m && (used[i] || A[i][j]==0)) {
            ++i;
        }
        if (i == m) continue;
        ++rank;
        used[i] = 1;
        for (int k=0; k<m; ++k) {
            if (!used[k]) {
                // find coef such that A[k][j] + coef*A[i][j] = 0 (mod p)
                int coef = 0;
                while ((A[k][j] + coef*A[i][j])%p != 0) {
                    ++coef;
                }
                for (int l=0; l<n; ++l) {
                    A[k][l] = (A[k][l] + A[i][l]*coef) % p;
                }
                b[k] = (b[k] + b[i]*coef) % p;
            }
        }
    }
    for (int i=0; i<m; ++i) {
        if (!used[i] && b[i]!=0) {
            return 0;
        }
    }

    return expmod(p, n - rank);
}

class TheMagicMatrix {
public:
    int find(int n, vector <int> rows, vector <int> columns, vector <int> values) {
        int K = rows.size();
        if (n > 10) {
            return expmod(10, 1 + (long long)(n-1)*(n-1) - K);
        } else {
            vector< vector<int> > A;
            vector<int> b;
            for (int i=0; i<n; ++i) {
                // a_i1 + a_i2 + ... + a_in - d = 0
                vector<int> eq(n*n+1, 0);
                for (int j=0; j<n; ++j) {
                    eq[i*n+j] = 1;
                }
                eq.back() = -1;
                A.push_back(eq);
                b.push_back(0);
            }
            for (int j=0; j<n; ++j) {
                // a_1j + a_2j + ... + a_nj - d = 0
                vector<int> eq(n*n+1, 0);
                for (int i=0; i<n; ++i) {
                    eq[i*n+j] = 1;
                }
                eq.back() = -1;
                A.push_back(eq);
                b.push_back(0);
            }
            for (int i=0; i<K; ++i) {
                vector<int> eq(n*n+1, 0);
                eq[rows[i]*n + columns[i]] = 1;
                A.push_back(eq);
                b.push_back(values[i]);
            }
            return int(ways(A, b, 2)*ways(A, b, 5)%mod);
        }
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
			int n                     = 2;
			int rows[]                = {0, 1};
			int columns[]             = {1, 0};
			int values[]              = {4, 4};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int rows[]                = {0, 1};
			int columns[]             = {1, 0};
			int values[]              = {4, 7};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 4;
			int rows[]                = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3};
			int columns[]             = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2};
			int values[]              = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 474;
			int rows[]                = {44, 77};
			int columns[]             = {47, 74};
			int values[]              = {4, 7};
			int expected__            = 83494518;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int rows[]                = ;
			int columns[]             = ;
			int values[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int rows[]                = ;
			int columns[]             = ;
			int values[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int rows[]                = ;
			int columns[]             = ;
			int values[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheMagicMatrix().find(n, vector <int>(rows, rows + (sizeof rows / sizeof rows[0])), vector <int>(columns, columns + (sizeof columns / sizeof columns[0])), vector <int>(values, values + (sizeof values / sizeof values[0])));
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
