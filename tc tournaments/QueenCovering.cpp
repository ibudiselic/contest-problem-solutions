#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

// only down
const int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int sz[8];
int I[8], J[8];
bool att[8][8];
vector<string> B;
int sol_sz;
int cur;
string sol;
bool valid(int i, int j) {
	if (i<0 || j<0 || i>=8 || j>=8)
		return false;
	else
		return true;
}
void update() {
	if (sol_sz*2 < (int)sol.size()) {
		sol.clear();
		for (int i=0; i<sol_sz; ++i) {
			sol += char('1' + I[i]);
			sol += char('A' + J[i]);
		}
	}
}
void go(int r) {
	if (r == 8) {
		if (cur == 64)
			update();
		return;
	}
	for (int c=0; c<8; ++c)
		if (!att[r][c]) {
			I[sol_sz] = r;
			J[sol_sz] = c;
			vector< pair<int, int> > new_att;
			att[r][c] = 1;
			new_att.push_back(make_pair(r, c));
			for (int d=0; d<8; ++d) {
				int i = r + di[d];
				int j = c + dj[d];
				while (valid(i, j)) {
					if (!att[i][j]) {
						att[i][j] = 1;
						new_att.push_back(make_pair(i, j));
					}
					i += di[d];
					j += dj[d];
				}
			}
			++sol_sz;
			cur += new_att.size();
			go(r+1);
			cur -= new_att.size();
			--sol_sz;
			for (int i=0; i<(int)new_att.size(); ++i)
				att[new_att[i].first][new_att[i].second] = 0;
		}
	go(r+1);
}
class QueenCovering {
	public:
	string getPlacement(vector <string> board) {
		B = board;
		memset(att, 0, sizeof att);
		sol_sz = 0;
		cur = 0;

		for (int i=0; i<8; ++i)
			for (int j=0; j<8; ++j)
				if (B[i][j] == '#') {
					att[i][j] = 1;
					++cur;
				}

		sol.assign(50, 'Z');
		go(0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
  "........",
  "..######",
  ".#.#####",
  ".##.####",
  ".###.###",
  ".####.##",
  ".#####.#",
  "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1A8B"; verify_case(0, Arg1, getPlacement(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "#......#",
 ".#......",
 "..#...#.",
 "........",
 "..#.....",
 "..#..#..",
 "#.......",
 "#...###."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1B2D3A4C5E"; verify_case(1, Arg1, getPlacement(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1A2C3E4B5D"; verify_case(2, Arg1, getPlacement(Arg0)); }
	void test_case_3() { string Arr0[] = {
  "..##.##.",
  ".###..##",
  "##..###.",
  "#..#...#",
  ".#.##.#.",
  "#...##..",
  "#..#####",
  "..#..#.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1A4C5H6B"; verify_case(3, Arg1, getPlacement(Arg0)); }
	void test_case_4() { string Arr0[] = {
  "########",
  "########",
  "########",
  "########",
  "########",
  "########",
  "########",
  "########"
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, getPlacement(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QueenCovering ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
