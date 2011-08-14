#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int C[10][10];
int cnt[11];
int exp[] = { 0, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0 };
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const int diag_i[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int diag_j[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
vector<string> B;
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=10 || j>=10)
		return false;
	return true;
}
bool test(int i, int j, int d) {
	const int r = i + di[d];
	const int c = j + dj[d];
	return (valid(r, c) && B[r][c]=='X');
}
bool diagtest(int i, int j, int comp) {
	for (int d=0; d<8; ++d) {
		const int r = i + diag_i[d];
		const int c = j + diag_j[d];
		if (valid(r, c) && C[r][c]!=-1 && C[r][c]!=comp)
			return true;
	}
	return false;
}
int go(int i, int j, int comp, int d) {
	C[i][j] = comp;
	if (diagtest(i, j, comp))
		return -100000;
	if (test(i, j, d))
		return 1 + go(i+di[d], j+dj[d], comp, d);
	else
		return 1;
}
bool ok() {
	memset(C, 0xff, sizeof C);
	memset(cnt, 0, sizeof cnt);
	int c = 0;
	for (int i=0; i<10; ++i)
		for (int j=0; j<10; ++j)
			if (C[i][j]==-1 && B[i][j]=='X') {
				int x = 0;
				for (int d=0; d<2; ++d)
					x += test(i, j, d);
				if (x == 2)
					return false;
				const int t = go(i, j, c++, test(i, j, 1));
				if (t < 0)
					return false;
				++cnt[t];
			}
	for (int i=0; i<11; ++i)
		if (cnt[i] != exp[i])
			return false;

	return true;
}
class BattleshipChecker {
	public:
	string checkBoard(vector <string> board) {
		B = board;

		if (!ok()) {
			return "REJECTED";
		} else {
			int sol = 0;
			for (int i=0; i<10; ++i) {
				int cnt1 = 0;
				int cnt2 = 0;
				for (int j=0; j<10; ++j) {
					cnt1 += (B[i][j]=='X');
					cnt2 += (B[j][i]=='X');
				}
				sol += (cnt1==0) + (cnt2==0);
			}
			ostringstream os;
			os << "ACCEPTED, " << sol << " POINTS";
			return os.str();
		}
		return ":CRY";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......X...",
 ".XXX..X...",
 "......X...",
 "X.X...X...",
 "X.........",
 "...XX.X...",
 "......X...",
 ".XX...X...",
 "..........",
 ".X.X..X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 5 POINTS"; verify_case(0, Arg1, checkBoard(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.X.X.X...",
 "......X...",
 ".XX...X...",
 "......X...",
 "......X..X",
 "...X..X...",
 "...X..X...",
 "......X...",
 "..XX..X...",
 "......X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(1, Arg1, checkBoard(Arg0)); }
	void test_case_2() { string Arr0[] = {".....XX...",
 ".XX.......",
 "..........",
 ".X....XXX.",
 ".X........",
 ".....X....",
 "..X..X....",
 ".....X....",
 "...X......",
 "X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(2, Arg1, checkBoard(Arg0)); }
	void test_case_3() { string Arr0[] = {".....XX..X",
 ".XX......X",
 "..........",
 ".X....XXX.",
 ".X........",
 ".....X..X.",
 "..X..X....",
 ".....X....",
 "...X......",
 "X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(3, Arg1, checkBoard(Arg0)); }
	void test_case_4() { string Arr0[] = {"X.......X.",
 "...XXXX...",
 ".X......X.",
 "....XX....",
 ".........X",
 ".........X",
 ".....XXX..",
 ".........X",
 "..X......X",
 "..X......X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 0 POINTS"; verify_case(4, Arg1, checkBoard(Arg0)); }
	void test_case_5() { string Arr0[] = {"X.......X.",
 "...XXXX...",
 ".X......X.",
 "....XX....",
 "...X.....X",
 "...X.....X",
 ".....XXX..",
 ".........X",
 ".........X",
 ".........X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(5, Arg1, checkBoard(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BattleshipChecker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
