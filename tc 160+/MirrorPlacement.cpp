#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
enum { UP, RIGHT, DOWN, LEFT };

vector<string> B;
int M, N;

bool valid(int i, int j) {
	if (i<0 || i>=M || j<0 || j>=N)
		return false;

	return true;
}
char newChar(char c, int d) {
	if (c == '.')
		return d==LEFT || d==RIGHT ? '-' : '|';
	else
		return '+';
}
int newDir(char c, int d) {
	if (c == '/')
		switch (d) {
			case LEFT: return DOWN;
			case RIGHT: return UP;
			case UP: return RIGHT;
			case DOWN: return LEFT;
		}
	else
		switch (d) {
			case LEFT: return UP;
			case RIGHT: return DOWN;
			case UP: return LEFT;
			case DOWN: return RIGHT;
		}
	assert(0);
	return -1;
}
struct State {
	int i, j, d, c;
	State(int i_, int j_, int d_, int c_): i(i_), j(j_), d(d_), c(c_) {}
};

bool done[50][50][4];
int starti, startj, startd;
int go(int i, int j, int d) {
	starti = i;
	startj = j;
	startd = d;
	deque<State> Q;
	Q.push_back(State(i-di[d], j-dj[d], d, 0));

	memset(done, 0, sizeof done);
	while (!Q.empty()) {
		i = Q.front().i;
		j = Q.front().j;
		d = Q.front().d;
		int cost = Q.front().c;
		Q.pop_front();

		if (i==starti && j==startj && d==(startd+2)%4)
			continue;
		if (valid(i, j)) {
			if (done[i][j][d])
				continue;
			else
				done[i][j][d] = 1;
		}

		int r = i + di[d];
		int c = j + dj[d];

		if (!valid(r, c))
			return cost;

		if (B[r][c]=='/' || B[r][c]=='`') {
			int nd = newDir(B[r][c], d);
			if (!done[r][c][nd])
				Q.push_front(State(r, c, nd, cost));
		} else if (B[r][c] == '.') {
			if (!done[r][c][d])
				Q.push_front(State(r, c, d, cost));
			d = (d+3)%4;
			if (!done[r][c][d])
				Q.push_back(State(r, c, d, cost+1));
			d = (d+2)%4;
			if (!done[r][c][d])
				Q.push_back(State(r, c, d, cost+1));
		}
	}
	return -1;
}

class MirrorPlacement {
	public:
	int mirrors(vector <string> map) {
		B = map;
		M = B.size();
		N = B[0].size();

		for (int i=0; i<M; ++i)
			if (B[i][0] == '.') {
				return go(i, 0, RIGHT);
			} else if (B[i][N-1] == '.') {
				return go(i, N-1, LEFT);
			}

		for (int j=0; j<N; ++j)
			if (B[0][j] == '.') {
				return go(0, j, DOWN);
			} else if (B[M-1][j] == '.') {
				return go(M-1, j, UP);
			}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "#######",
  "##....#",
  "##.##.#",
  "##.##.#",
  "......#",
  "##.####",
  "##.####" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, mirrors(Arg0)); }
	void test_case_1() { string Arr0[] = { "########",
  "##....##",
  "##.##.##",
  "##...`..",
  "#####.##" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, mirrors(Arg0)); }
	void test_case_2() { string Arr0[] = { "##################################################",
  "#................................................#",
  ".................................................#",
  "#................................................#",
  "#.................................................",
  "#................................................#",
  "##################################################" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, mirrors(Arg0)); }
	void test_case_3() { string Arr0[] = { "###########",
  "...../.....",
  "#####.#####",
  "###.....###",
  "###.###.###",
  "###.....###",
  "###########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, mirrors(Arg0)); }
	void test_case_4() { string Arr0[] = { "########.##",
  "#./......`#",
  "#../.`....#",
  "#.`...../.#",
  "#....`.../#",
  "###.#######" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, mirrors(Arg0)); }
	void test_case_5() { string Arr0[] = { "#.#####",
  "#..####",
  "##..###",
  "###..##",
  "####..#",
  "#####.#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(5, Arg1, mirrors(Arg0)); }
	void test_case_6() { string Arr0[] = { "####",
  "####",
  "#..#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, mirrors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MirrorPlacement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
