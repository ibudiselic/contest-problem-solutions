#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[1001][1001];
int D;
long long go(int n, int m) {
	if (m < 0)
		return 0;
	if (m == 0)
		return 1;

	long long &ret = dp[n][m];
	if (ret != -1)
		return ret;

	ret = go(n, m-n);
	for (int i=1; i<n; ++i) {
		m -= D;
		if (m < 0)
			break;
		ret += go(i, m);
	}

	return ret;
}
class Computers {
	public:
	long long choices(int n, int minDif, int minInComp, int amount) {
		D = minDif;
		memset(dp, 0xff, sizeof dp);

		return go(amount, n-minInComp*amount);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 6; int Arg2 = 5; int Arg3 = 2; long long Arg4 = 4LL; verify_case(0, Arg4, choices(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 500; int Arg2 = 400; int Arg3 = 1; long long Arg4 = 0LL; verify_case(1, Arg4, choices(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 5; int Arg2 = 5; int Arg3 = 10; long long Arg4 = 113420686168080LL; verify_case(2, Arg4, choices(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Computers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
