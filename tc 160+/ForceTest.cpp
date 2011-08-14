#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[102][102][21];
int go(int f1, int f2, int n) {
	if (f1 > f2)
		swap(f1, f2);

	int &ret = dp[f1][f2][n];
	if (ret == -1) {
		if (f2 == 1)
			return (ret = 0);
		if (n == 0)
			return (ret = 1234567890);

		ret = 1234567890;
		for (int f=1; f<f2; ++f)
			ret = min(ret, 1 + max(go(max(0, f1-f), f2-f, n), go(f1, f, n-1)));
	}

	return ret;
}
class ForceTest {
	public:
	int fewestTests(int maxForce, int testUnits) {
		memset(dp, 0xff, sizeof dp);

		return go(maxForce+1, maxForce+1, testUnits);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, fewestTests(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, fewestTests(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, fewestTests(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 101; verify_case(3, Arg2, fewestTests(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ForceTest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
