#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MASK_ALL = (1<<21)-1;
int bc[1<<21];
int ind[256];
int A[21][21];
int m, n;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int cnt[1<<21];
int active[1<<21];
int counter;
void gen(int i, int j, int mask) {
    if (bc[mask] == 11) {
        if (cnt[mask] == 0) {
            active[counter++] = mask;
        }
        ++cnt[mask];
        return;
    }
    for (int d=0; d<4; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (r<0 || c<0 || r>=m || c>=n || A[r][c]==-1 || (mask & (1<<A[r][c]))) {
            continue;
        }
        gen(r, c, mask | (1<<(A[r][c])));
    }
}
class AlphabetPaths {
public:
    long long count(vector <string> letterMaze) {
        bc[0] = 0;
        for (int i=1; i<=MASK_ALL; ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        m = letterMaze.size();
        n = letterMaze[0].size();
        int letter = 0;
        memset(ind, 0xff, sizeof ind);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (letterMaze[i][j] == '.') {
                    A[i][j] = -1;
                } else {
                    if (ind[letterMaze[i][j]] == -1) {
                        ind[letterMaze[i][j]] = letter++;
                    }
                    A[i][j] = ind[letterMaze[i][j]];
                }
            }
        }
        
        long long sol = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] != -1) {
                    counter = 0;
                    gen(i, j, 1<<A[i][j]);
                    for (int k=0; k<counter; ++k) {
                        const int mask = active[k];
                        const int other = (MASK_ALL ^ mask) | (1<<A[i][j]);
                        sol += (long long)cnt[mask]*cnt[other];
                    }
                    for (int k=0; k<counter; ++k) {
                        cnt[active[k]] = 0;
                    }
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
			string letterMaze[]       = {"ABCDEFZHIXKLMNOPQRST", "...................V"};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string letterMaze[]       = {".................VT.", "....................", "ABCDEFZHIXKLMNOPQRS.", "..................S.", ".................VT."};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string letterMaze[]       = {"TBCDE.PQRSA", "FZHIXKLMNOV"};
			long long expected__      = 50;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string letterMaze[]       = {"ABCDEF.", "V....Z.", "T....H.", "S....I.", "R....X.", "KLMNOPQ"};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string letterMaze[]       = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string letterMaze[]       = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlphabetPaths().count(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
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
