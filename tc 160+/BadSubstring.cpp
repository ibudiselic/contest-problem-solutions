#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long dp[50][3];
class BadSubstring {
	public:
	long long howMany(int length) {
		memset(dp, 0, sizeof dp);

		if (length == 0) return 1;
		if (length == 1) return 3;
		for (int i=0; i<3; ++i)
			dp[1][i] = 1;
		for (int i=2; i<=length; ++i) {
			dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
			dp[i][1] =         0  + dp[i-1][1] + dp[i-1][2];
			dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
		}

		return accumulate(dp[length], dp[length]+3, 0ll);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; long long Arg1 = 1LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arg0 = 29; long long Arg1 = 1548008755920LL; verify_case(2, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BadSubstring ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
