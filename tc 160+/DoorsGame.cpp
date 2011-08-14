#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string S;
int T;
int a_need, b_need;
int dp[2][1<<16];
bool is_draw[2][1<<16];
int need[2];
int go(int p, int mask) {
    int &ret = dp[p][mask];
    if (ret != -1) {
        return ret;
    }
    int best_win = 123;
    int best_win_i = -1;
    int best_draw = 123;
    int best_draw_i = -1;
    int best_loss = 0;
    int best_loss_i = -1;
    for (int i=0; i<16; ++i) {
        if ((mask & (1<<i)) == 0) {
            const int nmask = (mask | (1<<i));
            bool win=false, loss=false, draw=false;
            bool i_win = ((nmask & need[p])==need[p]);
            bool he_wins = ((nmask & need[1-p])==need[1-p]);
            if (i_win && he_wins) {
                draw = true;
            } else if (i_win) {
                win = true;
            } else if (he_wins) {
                loss = true;
            }
            int moves = 1;
            if (!win && !loss && !draw) {
                moves += go(1-p, nmask);
                draw = is_draw[1-p][nmask];
                if (!draw) {
                    if (moves & 1) {
                        win = true;
                    } else {
                        loss = true;
                    }
                }
            }
            
            if (draw) {
                if (moves < best_draw) {
                    best_draw = moves;
                    best_draw_i = i;
                }
            } else if (win) {
                if (moves < best_win) {
                    best_win = moves;
                    best_win_i = i;
                }
            } else if (loss) {
                if (moves > best_loss) {
                    best_loss = moves;
                    best_loss_i = i;
                }
            } else {
                assert(0);
            }
        }
    }
    
    is_draw[p][mask] = false;
    if (best_win_i != -1) {
        ret = best_win;
    } else if (best_draw_i != -1) {
        is_draw[p][mask] = true;
        ret = 0;
    } else {
        assert(best_loss_i != -1);
        ret = best_loss;
    }
    
    return ret;
}
class DoorsGame {
	public:
	int determineOutcome(string doors, int trophy) {
		S = doors;
        T = trophy;
        a_need = 0;
        b_need = 0;
        for (int i=0; i<T; ++i) {
            a_need |= (1<<(S[i]-'A'));
        }
        for (int i=T; i<(int)S.size(); ++i) {
            b_need |= (1<<(S[i]-'A'));
        }
        
        need[0] = a_need;
        need[1] = b_need;
        memset(dp, 0xff, sizeof dp);
        memset(is_draw, 0, sizeof is_draw);
        const int t = go(0, 0);
        if (is_draw[0][0]) {
            return 0;
        }
        return (t&1) ? t : -t;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCC"; int Arg1 = 2; int Arg2 = -2; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABABAB"; int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABAPDCAA"; int Arg1 = 5; int Arg2 = -4; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "MOCFDCE"; int Arg1 = 3; int Arg2 = 5; verify_case(4, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ABCCDE"; int Arg1 = 3; int Arg2 = 0; verify_case(5, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABCCD"; int Arg1 = 3; int Arg2 = 0; verify_case(6, Arg2, determineOutcome(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DoorsGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
