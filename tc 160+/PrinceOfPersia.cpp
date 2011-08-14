#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[10][10];
int pi, pj;
vector<string> M;
bool valid(int i, int j) {
	return i>=0 && j>=0 && i<(int)M.size() && j<(int)M[0].size();
}
int bfs() {
	queue< pair<int, int> > Q;
	Q.push(make_pair(pi, pj));
	memset(done, 0, sizeof done);
	done[pi][pj] = 1;

	while (!Q.empty()) {
		int i = Q.front().first;
		int j = Q.front().second;
		Q.pop();

		for (int d=0; d<4; ++d) {
			int r = i + di[d];
			int c = j + dj[d];
			if (valid(r, c) && M[r][c]!='#' && !done[r][c]) {
				if (M[r][c] == 'P')
					return 1;
				done[r][c] = 1;
				Q.push(make_pair(r, c));
			}
		}
	}
	return 0;
}
bool canBlock(int i, int j, int cnt) {
	if (cnt == 0)
		return !bfs();
	if (i == (int)M.size())
		return false;
	if (j == (int)M[0].size())
		return canBlock(i+1, 0, cnt);

	if (M[i][j] == '.') {
		M[i][j] = '#';
		if (canBlock(i, j+1, cnt-1))
			return true;
		M[i][j] = '.';
	}
	return canBlock(i, j+1, cnt);
}
bool isNeigbor() {
	for (int d=0; d<4; ++d) {
		int i = pi + di[d];
		int j = pj + dj[d];
		if (valid(i, j) && M[i][j]=='P')
			return true;
	}
	return false;
}
class PrinceOfPersia {
	public:
	int minObstacles(vector <string> maze) {
		M = maze;
		for (int i=0; i<(int)M.size(); ++i)
			for (int j=0; j<(int)M[0].size(); ++j)
				if (M[i][j] == 'P') {
					pi = i;
					pj = j;
					M[i][j] = 'O';
					goto FOUND_P;
				}
		FOUND_P:;

		if (isNeigbor())
			return -1;

		for (int cnt=0; cnt<4; ++cnt) {
			if (canBlock(0, 0, cnt))
				return cnt;
		}

		return 4;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"P....",
 "...##",
 "##...",
 "....P"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minObstacles(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".P.P.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minObstacles(Arg0)); }
	void test_case_2() { string Arr0[] = {".#P.",
 ".P#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minObstacles(Arg0)); }
	void test_case_3() { string Arr0[] = {"####",
 "#PP#",
 "####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minObstacles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrinceOfPersia ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
