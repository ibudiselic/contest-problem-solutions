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

int A[4][4];
int M, N;
int sol;

int eval() {
	vector< pair<int, int> > v;
	for (int i=0; i<M; ++i)
		for (int j=0; j<N; ++j)
			if (A[i][j])
				v.push_back(make_pair(i, j));

	int ret = 1234567890;
	for (int i=0; i<(int)v.size(); ++i)
		for (int j=i+1; j<(int)v.size(); ++j)
			ret = min(ret, abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second));

	return ret;
}
void calc(int cnt, int r, int c) {
	if (cnt == 0) {
		sol = max(sol, eval());
		return;
	}
	if (r == M)
		return;
	if (c == N) {
		calc(cnt, r+1, 0);
		return;
	}

	if (eval() <= sol)
		return;

	calc(cnt, r, c+1);
	A[r][c] = 1;
	calc(cnt-1, r, c+1);
	A[r][c] = 0;
}
class PrisonCells {
	public:
	int scatter(int m, int n, int nr) {
		memset(A, 0, sizeof A);
		M = m;
		N = n;

		sol = 0;

		calc(nr, 0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, scatter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, scatter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 4; int Arg3 = 3; verify_case(2, Arg3, scatter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 16; int Arg3 = 1; verify_case(3, Arg3, scatter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrisonCells ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
