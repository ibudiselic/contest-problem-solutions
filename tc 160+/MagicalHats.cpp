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
#include <numeric>

using namespace std;

const int MASK_LIM = 1594323; // 3^13
bool done[MASK_LIM], can_memo[MASK_LIM];
int p3[14];
int N;
int rows, cols;
int R[13], C[13];
enum {
    UNUSED, EMPTY, COIN
};
bool can(int mask, int remcoins, vector<char> &status) {
    if (done[mask]) {
        return can_memo[mask];
    }
    done[mask] = 1;
    bool ret = false;
    bool final = true;
    for (int i=0; i<N; ++i) {
        if (status[i] == UNUSED) {
            final = false;
            status[i] = EMPTY;
            if (can(mask + EMPTY*p3[i], remcoins, status)) {
                ret = true;
            }
            if (remcoins > 0) {
                status[i] = COIN;
                if (can(mask + COIN*p3[i], remcoins-1, status)) {
                    ret = true;
                }
            }
            status[i] = UNUSED;
        }
    }
    if (final) {
        if (remcoins > 0) {
            ret = false;
        } else {
            char rsum[13] = {0};
            char csum[13] = {0};
            for (int i=0; i<N; ++i) {
                if (status[i] == EMPTY) {
                    ++rsum[R[i]];
                    ++csum[C[i]];
                }
            }
            ret = true;
            for (int i=0; i<rows; ++i) {
                if (rsum[i] & 1) {
                    ret = false;
                    break;
                }
            }
            if (ret) {
                for (int i=0; i<cols; ++i) {
                    if (csum[i] & 1) {
                        ret = false;
                        break;
                    }
                }
            }
        }
    }
    return (can_memo[mask] = ret);
}

signed char dp[14][MASK_LIM];
signed char go(int nguess, int mask, int remcoins, vector<char> &status) {
    signed char &ret = dp[nguess][mask];
    if (ret != -1) {
        return ret;
    }
    if (!can(mask, remcoins, status)) {
        ret = 123;
    } else {
        ret = 0;
        if (nguess > 0) {
            for (int i=0; i<N; ++i) {
                if (status[i] == UNUSED) {
                    status[i] = EMPTY;
                    signed char cand = go(nguess-1, mask + EMPTY*p3[i], remcoins, status);
                    status[i] = COIN;
                    cand = min(cand, (signed char)(1 + go(nguess-1, mask + COIN*p3[i], remcoins-1, status)));
                    status[i] = UNUSED;
                    ret = max(ret, cand);
                }
            }
        }
    }
    return ret;
}
class MagicalHats {
public:
    int findMaximumReward(vector <string> board, vector <int> coins, int nguess) {
        p3[0] = 1;
        for (int i=1; i<14; ++i) {
            p3[i] = p3[i-1]*3;
        }
        N = 0;
        rows = board.size();
        cols = board[0].size();
        for (int i=0; i<(int)board.size(); ++i) {
            for (int j=0; j<(int)board[i].size(); ++j) {
                if (board[i][j] == 'H') {
                    R[N] = i;
                    C[N] = j;
                    ++N;
                }
            }
        }

        memset(done, 0, sizeof done);
        vector<char> status(N, 0);
        if (!can(0, int(coins.size()), status)) {
            return -1;
        }
        memset(dp, 0xff, sizeof dp);
        int best = go(nguess, 0, int(coins.size()), status);
        sort(coins.begin(), coins.end());
        return accumulate(coins.begin(), coins.begin() + best, 0);
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
			string board[]            = {"H"};
			int coins[]               = {1};
			int numGuesses            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"HHH", "H.H", "HH."};
			int coins[]               = {9};
			int numGuesses            = 1;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"HH", "HH"};
			int coins[]               = {1,2,3,4};
			int numGuesses            = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"HHH", "HHH", "H.H"};
			int coins[]               = {13,13,13,13};
			int numGuesses            = 2;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"HHH", "HHH", "H.H"};
			int coins[]               = {13,13,13,13};
			int numGuesses            = 3;
			int expected__            = 26;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"H.H.", ".H.H", "H.H."};
			int coins[]               = {17};
			int numGuesses            = 6;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string board[]            = {"HHH", "H.H", "HHH", "H.H", "HHH"};
			int coins[]               = {33,337,1007,2403,5601,6003,9999};
			int numGuesses            = 5;
			int expected__            = 1377;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			string board[]            = {".............", ".............", ".............", ".............", ".............", ".............", ".....H.H.....", "......H......", ".....H.H.....", ".............", ".............", ".............", "............."};
			int coins[]               = {22};
			int numGuesses            = 3;
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string board[]            = ;
			int coins[]               = ;
			int numGuesses            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicalHats().findMaximumReward(vector <string>(board, board + (sizeof board / sizeof board[0])), vector <int>(coins, coins + (sizeof coins / sizeof coins[0])), numGuesses);
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
