#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > next;
long long dp[31][11];
long long go(int pos, int dig) {
	if (pos == 0)
		return 1;
	if (dp[pos][dig] != -1)
		return dp[pos][dig];

	long long ret = 0;
	for (int i=0; i<(int)next[dig].size(); ++i)
		ret += go(pos-1, next[dig][i]);

	return dp[pos][dig] = ret;
}
class UnsealTheSafe {
	public:
	long long countPasswords(int N) {
		next.assign(11, vector<int> ());
		next[0].push_back(7);
		next[1].push_back(2); next[1].push_back(4);
		next[2].push_back(1); next[2].push_back(5); next[2].push_back(3);
#define PB(a, b) next[a].push_back(b)
		PB(3, 2); PB(3, 6);
		PB(4, 1); PB(4, 5); PB(4, 7);
		PB(5, 4); PB(5, 2); PB(5, 6); PB(5, 8);
		PB(6, 3); PB(6, 5); PB(6, 9);
		PB(7, 4); PB(7, 8); PB(7, 0);
		PB(8, 5); PB(8, 7); PB(8, 9);
		PB(9, 6); PB(9, 8);

		for (int i=0; i<10; ++i)
			PB(10, i);

		memset(dp, 0xff, sizeof dp);
		return go(N, 10);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 26LL; verify_case(0, Arg1, countPasswords(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 74LL; verify_case(1, Arg1, countPasswords(Arg0)); }
	void test_case_2() { int Arg0 = 25; long long Arg1 = 768478331222LL; verify_case(2, Arg1, countPasswords(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnsealTheSafe ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
