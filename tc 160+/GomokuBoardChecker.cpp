#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char winner;
int m, n;
vector<string> B;
bool marked[50][50];
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=m || j>=n)
		return false;
	return true;
}
bool full() {
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (B[i][j] == '.')
				return false;
	return true;
}
void test(int i, int j, int di, int dj) {
	if (valid(i-di, j-dj) && B[i][j]==B[i-di][j-dj])
		return;

	int cnt = 0;
	int r = i;
	int c = j;
	bool isMarked = false;
	while (valid(i, j) && B[i][j]==B[r][c]) {
		++cnt;
		if (cnt <= 5)
			isMarked |= marked[i][j];

		i += di;
		j += dj;
	}

	if (cnt >= 10) {
		winner = '-';
	} else if (cnt >= 5) {
		if (winner==B[r][c] && isMarked) {
			i = r;
			j = c;
			for (int t=0; t<5; ++t) {
				if (marked[i][j]) {
					memset(marked, 0, sizeof marked);
					marked[i][j] = 1;
					break;
				}
				i += di;
				j += dj;
			}
			return;
		}

		if (winner != '.') {
			winner = '-';
		} else {
			winner = B[r][c];
			i = r;
			j = c;
			for (int t=0; t<5; ++t) {
				marked[i][j] = 1;
				i += di;
				j += dj;
			}
		}
	}
}
class GomokuBoardChecker {
	public:
	string check(vector <string> board) {
		int cntO = 0;
		int cntX = 0;
		B = board;
		m = board.size();
		n = board[0].size();
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (board[i][j] == 'X')
					++cntX;
				else if (board[i][j] == 'O')
					++cntO;

		for (int i=0; i<m; ++i)
			cerr << B[i] << '\n';

		if (abs(cntX-cntO) > 1)
			return "INVALID";


		winner = '.';
		memset(marked, 0, sizeof marked);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (B[i][j] != '.') {
				for (int di=0; di<=1; ++di)
					for (int dj=0; dj<=1; ++dj)
						if (abs(di)+abs(dj) > 0)
							test(i, j, di, dj);
				test(i, j, -1, 1);
				}

		if (winner == '-')
			return "INVALID";
		if (winner=='X' && cntX<cntO || winner=='O' && cntO<cntX)
			return "INVALID";

		if (winner == '.')
			return full() ? "DRAW" : "IN PROGRESS";
		return winner + string(" WON");
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"O.X..",
 ".OX..",
 "X.O..",
 "X..O.",
 "....O"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "O WON"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arr0[] = {"O.X..",
 ".OX..",
 "X.O..",
 "X..O.",
 "...XO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "O WON"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arr0[] = {"OOOOO",
 "OOOOO",
 "OOOOO",
 "OOOOO",
 "OOOOX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INVALID"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arr0[] = {"O...",
 "...X",
 "....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IN PROGRESS"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arr0[] = {"O.X.O.",
 ".OX.O.",
 "X.O.O.",
 "X..OO.",
 "..XXOX",
 "XXXXOO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "O WON"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arr0[] = {"O.XX.O",
 ".OX..O",
 "X.O..O",
 "X..O.O",
 "..XXOO",
 "XXXX.O"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INVALID"; verify_case(5, Arg1, check(Arg0)); }
	void test_case_6() { string Arr0[] = {"XXXXO",
 "OOOOX",
 "XXXXO",
 "OOOOX",
 "XOXOX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRAW"; verify_case(6, Arg1, check(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GomokuBoardChecker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
