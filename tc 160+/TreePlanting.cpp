#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[61][61][2];
long long go(int n, int f, bool lastFancy) {
	if (n==0 && f==0)
		return 1;

	if (dp[n][f][lastFancy] != -1)
		return dp[n][f][lastFancy];

	return dp[n][f][lastFancy] = (lastFancy ? 0 : (f > 0 ? go(n, f-1, 1) : 0)) + (n > 0 ? go(n-1, f, 0) : 0);
}
class TreePlanting {
	public:
	long long countArrangements(int total, int fancy) {
		memset(dp, 0xff, sizeof dp);

		return go(total-fancy, fancy, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; long long Arg2 = 3LL; verify_case(0, Arg2, countArrangements(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; long long Arg2 = 3LL; verify_case(1, Arg2, countArrangements(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; long long Arg2 = 0LL; verify_case(2, Arg2, countArrangements(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 4; long long Arg2 = 35LL; verify_case(3, Arg2, countArrangements(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TreePlanting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
