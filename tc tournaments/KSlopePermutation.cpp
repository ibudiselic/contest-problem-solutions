#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int F;
long long dp[20][20][21][20];
long long go(int pos, int n, int last, int k) {
	if (k < 0)
		return 0;
	if (n == 0)
		return (k==0);
	if (pos == F)
		return go(pos+1, n, -1, k);

	long long &ret = dp[pos][n][last+1][k];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i=0; i<n; ++i)
		ret += go(pos+1, n-1, i, k - (i<last));

	return ret;
}
class KSlopePermutation {
	public:
	long long getCount(int n, int k, int f) {
		F = f;
		memset(dp, 0xff, sizeof dp);
		return go(0, n-1, -1, k-(f>0));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 0; long long Arg3 = 4LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 0; long long Arg3 = 0LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 1; long long Arg3 = 0LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 2; long long Arg3 = 330LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KSlopePermutation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
