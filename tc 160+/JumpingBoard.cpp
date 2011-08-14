#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool old[50][50];
bool next[50][50];
class JumpingBoard {
	public:
	int maxJumps(vector <string> board) {
		int m = board.size();
		int n = board[0].size();
		int sol = 0;
		memset(old, 0, sizeof old);
		old[0][0] = 1;
		for (int t=0; t<=n*m; ++t) {
			memset(next, 0, sizeof next);
			for (int i=0; i<m; ++i) {
				for (int j=0; j<n; ++j) {
					if (old[i][j]) {
						int step = board[i][j]-'0';
						for (int di=-1; di<2; ++di) {
							for (int dj=-1; dj<2; ++dj) {
								if (abs(di) + abs(dj) == 1) {
									int r = i + step*di;
									int c = j + step*dj;
									if (r<0 || c<0 || r>=m || c>=n || board[r][c]=='H') {
										continue;
									}
									sol = t+1;
									next[r][c] = 1;
								}
							}
						}
					}
				}
			}
			memcpy(old, next, sizeof old);
		}

		return sol>m*n ? -1 : sol+1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3942178",
 "1234567",
 "9123532"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxJumps(Arg0)); }
	void test_case_1() { string Arr0[] = {"2H3HH4HHH5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxJumps(Arg0)); }
	void test_case_2() { string Arr0[] = {"3994",
 "9999",
 "9999",
 "2924"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, maxJumps(Arg0)); }
	void test_case_3() { string Arr0[] = {"123456",
 "234567",
 "345678",
 "456789"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maxJumps(Arg0)); }
	void test_case_4() { string Arr0[] = {"9"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, maxJumps(Arg0)); }
	void test_case_5() { string Arr0[] = {"2H9HH11",
 "HHHHH11",
 "9HHHH11"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, maxJumps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    JumpingBoard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
