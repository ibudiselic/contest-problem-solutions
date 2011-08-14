#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[10][51][51][51];
long long fact[11];
long long go(int n, int r, int g, int b) {
	if (n == 0)
		return 1;
	if (dp[n-1][r][g][b] != -1)
		return dp[n-1][r][g][b];

	long long ret = 0;
	if (n%3 == 0) {
		int cnt = n/3;
		if (cnt<=r && cnt<=g && cnt<=b)
			ret += fact[n]/fact[cnt]/fact[cnt]/fact[cnt] * go(n-1, r-cnt, g-cnt, b-cnt);
	}
	if (n%2 == 0) {
		int cnt = n/2;
		if (cnt<=r && cnt<=g)
			ret += fact[n]/fact[cnt]/fact[cnt] * go(n-1, r-cnt, g-cnt, b);
		if (cnt<=g && cnt<=b)
			ret += fact[n]/fact[cnt]/fact[cnt] * go(n-1, r, g-cnt, b-cnt);
		if (cnt<=b && cnt<=r)
			ret += fact[n]/fact[cnt]/fact[cnt] * go(n-1, r-cnt, g, b-cnt);
	}
	if (n <= r)
		ret += go(n-1, r-n, g, b);
	if (n <= g)
		ret += go(n-1, r, g-n, b);
	if (n <= b)
		ret += go(n-1, r, g, b-n);

	return dp[n-1][r][g][b] = ret;
}
class ChristmasTree {
	public:
	long long decorationWays(int N, int red, int green, int blue) {
		if (N*(N+1)/2 > red+green+blue)
			return 0;

		fact[0] = 1;
		for (int i=1; i<11; ++i)
			fact[i] = fact[i-1]*i;
		memset(dp, 0xff, sizeof dp);
		return go(N, red, green, blue);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 6LL; verify_case(0, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; long long Arg4 = 3LL; verify_case(1, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; long long Arg4 = 36LL; verify_case(3, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 1; int Arg2 = 15; int Arg3 = 20; long long Arg4 = 197121LL; verify_case(4, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChristmasTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
