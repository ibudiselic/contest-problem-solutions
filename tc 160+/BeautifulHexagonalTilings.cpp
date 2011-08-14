#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = { 0, 1, 1, 0, -1, -1 };
const int dy[] = { 1, 1, 0, -1, -1, 0 };
int C[11][11], border[11][11], A[11][11], B[11][11];
int limA, limB;
vector<int> lim;
bool valid(int x, int y) {
	if (x<0 || y<0)
		return false;
	if (x > lim[2] + lim[3] - 2)
		return false;
	if (y > lim[1] + lim[2] - 2)
		return false;
	if (x-y > lim[0]-1)
		return false;
	if (y-x > lim[1]-1)
		return false;
	return true;
}
bool isBorder(int x, int y) {
	for (int d=0; d<6; ++d)
		if (!valid(x+dx[d], y+dy[d]))
			return true;
	return false;
}
void color(int x, int y, int c) {
	C[x][y] = c;
	for (int d=0; d<6; ++d) {
		int i = x + dx[d];
		int j = y + dy[d];
		if (valid(i, j))
			++((c==1 ? A : B)[i][j]);
	}
}
void uncolor(int x, int y, int c) {
	C[x][y] = 0;
	for (int d=0; d<6; ++d) {
		int i = x + dx[d];
		int j = y + dy[d];
		if (valid(i, j))
			--((c==1 ? A : B)[i][j]);
	}
}
bool check(int x, int y) {
	if (!border[x][y])
		if (C[x][y]==1 && A[x][y]>limA || C[x][y]==2 && B[x][y]>limB)
			return false;
	for (int d=0; d<6; ++d) {
		int i = x + dx[d];
		int j = y + dy[d];
		if (valid(i, j) && !border[i][j]) {
			int tot = A[i][j] + B[i][j];
			if (tot == 6) {
				if (C[i][j]==1 && A[i][j]!=limA || C[i][j]==2 && B[i][j]!=limB)
					return false;
			} else {
				if (C[i][j]==1 && A[i][j]>limA || C[i][j]==2 && B[i][j]>limB)
					return false;
			}
		}
	}
	return true;
}
int sol;
void go(int x, int y) {
	if (x == 11) {
		++sol;
		return;
	}
	if (y == 11) {
		go(x+1, 0);
		return;
	}
	if (!valid(x, y)) {
		go(x, y+1);
		return;
	}

	color(x, y, 1);
	if (check(x, y))
		go(x, y+1);
	uncolor(x, y, 1);

	color(x, y, 2);
	if (check(x, y))
		go(x, y+1);
	uncolor(x, y, 2);
}
class BeautifulHexagonalTilings {
	public:
	int howMany(vector <int> s, int a, int b) {
		lim = s;

		limA = a;
		limB = b;
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);
		memset(C, 0, sizeof C);
		for (int x=0; x<11; ++x)
			for (int y=0; y<11; ++y)
				border[x][y] = isBorder(x, y);

		sol = 0;
		go(0, 0);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 6; int Arg3 = 2; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {6,6,6,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 6; int Arg3 = 2; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 30; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4,4,3,5,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 213; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BeautifulHexagonalTilings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
