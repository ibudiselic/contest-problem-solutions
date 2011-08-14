#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[51][64][64];
int mask[3][4] = { {0, 1, 2, 4}, {0, 0, 8, 16}, {0, 0, 0, 32} };
class RectangleAvoidingColoring {
	public:
	long long count(vector <string> board) {
		int m = board.size();
        int n = board[0].size();
        if (m > n) {
            vector<string> tmp(n, string(m, ' '));
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    tmp[j][i] = board[i][j];
                }
            }
            board.swap(tmp);
            swap(m, n);
        }
        
        if (m > 4) {
            return 0;
        }
        
        int lim = 64;
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int col=0; col<n; ++col) {
            for (int w=0; w<lim; ++w) {
                for (int b=0; b<lim; ++b) {
                    if (dp[col][w][b] == 0) {
                        continue;
                    }
                    for (int white=0; white<(1<<m); ++white) {
                        bool ok = true;
                        for (int i=0; i<m; ++i) {
                            if (board[i][col]=='W' && !(white&(1<<i))
                                ||
                                board[i][col]=='B' && (white&(1<<i))) {
                                    ok = false;
                                    break;
                            }
                            for (int j=i+1; j<m; ++j) {
                                if ((white&(1<<i)) && (white&(1<<j)) && (w&mask[i][j])
                                    ||
                                    !(white&(1<<i)) && !(white&(1<<j)) && (b&mask[i][j])) {
                                        ok = false;
                                        goto KRAJ;
                                }
                            }
                        }
                        KRAJ:;
                        if (!ok) {
                            continue;
                        }
                        
                        int next_w = w;
                        int next_b = b;
                        for (int i=0; i<m; ++i) {
                            for (int j=i+1; j<m; ++j) {
                                if ((white&(1<<i)) && (white&(1<<j))) {
                                    next_w |= mask[i][j];
                                } else if (!(white&(1<<i)) && !(white&(1<<j))) {
                                    next_b |= mask[i][j];
                                }
                            }
                        }
                        dp[col+1][next_w][next_b] += dp[col][w][b];
                    }
                }
            }
        }
        
        long long sol = 0;
        for (int w=0; w<lim; ++w) {
            for (int b=0; b<lim; ++b) {
                sol += dp[n][w][b];
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 14LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "?B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"??B??",
 "W???W",
 "??B??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 12LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"??",
 "W?",
 "W?",
 "?W",
 "W?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RectangleAvoidingColoring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
