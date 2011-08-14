//#include <algorithm>
//#include <cassert>
//#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include <cstring>

using namespace std;

const int di[] = { 1, -1 };
const int dj[] = { -1, 1 };

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=8 || j>=8)
		return false;
	return true;
}
int can_jump(const vector<string> &board, int i, int j) {
	int ret = 0;
	const int C = board[i][j];
	for (int d=0; d<2; ++d) {
		int r = i + di[C];
		int c = j + dj[d];
		if (valid(r, c) && board[r][c]==1-C) {
			r += di[C];
			c += dj[d];
			if (valid(r, c) && board[r][c]==' ')
				++ret;
		}
	}
	return ret;
}
int can_slide(const vector<string> &board, int i, int j) {
	const int C = board[i][j];
	int ret = 0;
	for (int d=0; d<2; ++d) {
		const int r = i + di[C];
		const int c = j + dj[d];
		if (valid(r, c) && board[r][c]==' ')
			++ret;
	}
	return ret;
}
int calc(const vector<string> &board, int c) {
	int jump=0, slide=0;

	for (int i=0; i<8; ++i)
		for (int j=0; j<8; ++j)
			if (board[i][j] == c) {
				jump += can_jump(board, i, j);
				slide += can_slide(board, i, j);

			}
	return (jump!=0 ? jump : slide);
}
class CheckersBoard {
	public:
	int numMoves(vector <string> board) {
		for (int i=0; i<8; ++i)
			for (int j=0; j<8; ++j)
				if (board[i][j] == 'B')
					board[i][j] = 0;
				else if (board[i][j] == 'W')
					board[i][j] = 1;

		return calc(board, 0) + calc(board, 1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"B       ",
"        ",
"        ",
"        ",
"        ",
"        ",
"        ",
" W      "
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, numMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {
"B B     ",
" W      ",
"        ",
"        ",
"        ",
"        ",
"        ",
"        "
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, numMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {
"B B B B ",
" B B B B",
"B B B B ",
"        ",
"        ",
" W W W W",
"W W W W ",
" W W W W"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(2, Arg1, numMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {
"B B B B ",
" W W W W",
"W W W W ",
"        ",
"        ",
"        ",
"        ",
"        "
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, numMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {
"    B B ",
"   B B W",
"    B W ",
"     W W",
"      W ",
"       W",
"        ",
"        "
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, numMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CheckersBoard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
