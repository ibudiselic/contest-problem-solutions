#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[101][101];
void add(long long &a, long long b) {
	a = (a+b)%1000000000;
}
long long go(int n, int k, bool first=false) {
	if (n < 3)
		return first ? -1 : 0;
	if (k < 1)
		return first ? -1 : 0;
	if (k == 1)
		return 1;
	if (n == 3)
		return first ? -1 : 0;
	if (k > n-2)
		return first ? -1 : 0;

	if (dp[n][k] != -1)
		return dp[n][k];

	long long &ret = dp[n][k];

	ret = go(n-1, k-1);
	add(ret, go(n-1, k));

	for (int i=2; i<=n-2; ++i)
		for (int m=1; m<k; ++m)
			add(ret, go(n-i+1, m) * (i==2 ? (long long)(k-m==1) : (go(i, k-m) + go(i, k-m-1))));

	return ret;
}

class PolygonDecomposition {
	public:
	int howMany(int n, int k) {
		memset(dp, 0xff, sizeof dp);
		return (int)go(n, k, true);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; int Arg2 = 14; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 20; int Arg2 = 956146480; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 4; int Arg2 = -1; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PolygonDecomposition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
