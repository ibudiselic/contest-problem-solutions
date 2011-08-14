#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[51];
long long go(int n) {
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];

	dp[n] = 0;
	for (int i=1; i<n; ++i)
		dp[n] += go(i-1)*go(n-1-i);

	return dp[n];
}
class HandsShaking {
	public:
	long long countPerfect(int n) {
		memset(dp, 0xff, sizeof dp);
		return go(n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(0, Arg1, countPerfect(Arg0)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 2LL; verify_case(1, Arg1, countPerfect(Arg0)); }
	void test_case_2() { int Arg0 = 8; long long Arg1 = 14LL; verify_case(2, Arg1, countPerfect(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HandsShaking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
