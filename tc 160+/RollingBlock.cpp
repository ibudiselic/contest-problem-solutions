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

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[100][100][2][4]; // i, j, onSide, dir
int M, N;
int Ti, Tj;
struct State {
	int i, j;
	bool onSide;
	int d;
	State(int i_, int j_, bool onSide_, int d_): i(i_), j(j_), onSide(onSide_), d(d_) {}
};

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N)
		return false;
	return true;
}
int bfs(int i, int j) {
	done[i][j][0][0] = 1;
	queue<State> Q;
	Q.push(State(i, j, 0, 0));
	int t = 0;
	int sol = -1;

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++sol;
		}
		--t;
		i = Q.front().i;
		j = Q.front().j;
		bool onSide = Q.front().onSide;
		int dir = Q.front().d;
		Q.pop();

		if (!onSide) {
			for (int d=0; d<4; ++d) {
				int r = i + di[d];
				int c = j + dj[d];
				if (valid(r, c) && valid(r+2*di[d], c+2*dj[d]) && !done[r][c][1][d]) {
					done[r][c][1][d] = 1;
					Q.push(State(r, c, 1, d));
				}
			}
		} else {
			int d = dir;
			if (valid(i+3*di[d], j+3*dj[d]) && !done[i+3*di[d]][j+3*dj[d]][0][0]) {
				if (i+3*di[d]==Ti && j+3*dj[d]==Tj)
					return sol+1;
				done[i+3*di[d]][j+3*dj[d]][0][0] = 1;
				Q.push(State(i+3*di[d], j+3*dj[d], 0, 0));
			}
			if (valid(i-di[d], j-dj[d]) && !done[i-di[d]][j-dj[d]][0][0]) {
				if (i-di[d]==Ti && j-dj[d]==Tj)
					return sol+1;
				done[i-di[d]][j-dj[d]][0][0] = 1;
				Q.push(State(i-di[d], j-dj[d], 0, 0));
			}
			for (d=0; d<4; ++d)
				if (d!=dir && d!=(dir+2)%4) {
					int r = i + di[d];
					int c = j + dj[d];
					if (valid(r, c) && valid(r+2*di[dir], c+2*dj[dir]) && !done[r][c][1][dir]) {
						done[r][c][1][dir] = 1;
						Q.push(State(r, c, 1, dir));
					}
				}
		}
	}

	return -1;
}
class RollingBlock {
	public:
	int minMoves(int rows, int cols, vector <int> start, vector <int> target) {
		if (start == target)
			return 0;
		M = rows;
		N = cols;
		Ti = target[0];
		Tj = target[1];

		memset(done, 0, sizeof done);
		return bfs(start[0], start[1]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {3, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {3, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(2, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {3, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(3, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 100; int Arr2[] = {4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 97}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; verify_case(4, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 20; int Arg1 = 20; int Arr2[] = {7, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(5, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RollingBlock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
