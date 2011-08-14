#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[101][51][51][51];
int mod = 1000001;
int go(int k, int m, int n, int oneAttacked) {
	assert(n >= oneAttacked);
	assert(n >= 0);
	assert(oneAttacked >= 0);
	if (k == 0)
		return 1;
	if (k == 1)
		return m*n;
	if (m==0 || n==0)
		return 0;
	if (dp[k][m][n][oneAttacked] != -1)
		return dp[k][m][n][oneAttacked];

	// place none
	int ret = go(k, m-1, n, oneAttacked);

	// place one
	ret = ((ret + (n>oneAttacked ? (n-oneAttacked)*go(k-1, m-1, n, oneAttacked+1) : 0))%mod + (oneAttacked>0 ? oneAttacked*go(k-1, m-1, n-1, oneAttacked-1) : 0)) % mod;

	if (n-oneAttacked >= 2) {
		// place two
		const int t = n-oneAttacked;
		ret = (ret + t*(t-1)/2*go(k-2, m-1, n-2, oneAttacked)) % mod;
	}

	return dp[k][m][n][oneAttacked] = ret;
}
class RooksPlacement {
	public:
	int countPlacements(int N, int M, int K) {
		memset(dp, 0xff, sizeof dp);
		return go(K, M, N, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 2; int Arg3 = 190; verify_case(0, Arg3, countPlacements(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, countPlacements(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 7; int Arg2 = 20; int Arg3 = 0; verify_case(2, Arg3, countPlacements(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 23; int Arg1 = 37; int Arg2 = 39; int Arg3 = 288688; verify_case(3, Arg3, countPlacements(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RooksPlacement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
