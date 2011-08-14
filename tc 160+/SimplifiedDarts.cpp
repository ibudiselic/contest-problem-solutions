#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[1001][1001][2]; // [i][j][k] - probability to get j or more points in i throws with the first throw from (k==0 ? short:long) distance
double p[2];
int pts[] = { 2, 3 };
double go(int n, int need, int dist) {
	if (need <= 0)
		return 1;
	if (dp[n][need][dist] > -0.5)
		return dp[n][need][dist];
	if (n == 0)
		return dp[n][need][dist] = 0;

	const double ret = p[dist] * max( go(n-1, need-pts[dist], dist), go(n-1, need-pts[dist], !dist) ) +
					(1.0 - p[dist]) * max( go(n-1, need, dist), go(n-1, need, !dist) );
	return dp[n][need][dist] = ret;
}

class SimplifiedDarts {
	public:
	double tryToWin(int W, int N, int P1, int P2) {
		p[0] = P1/100.0;
		p[1] = P2/100.0;
		for (int i=0; i<1001; ++i)
			for (int j=0; j<1001; ++j)
				for (int k=0; k<2; ++k)
					dp[i][j][k] = -1.0;

		return max(go(N, W, 0), go(N, W, 1))*100;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 50; int Arg3 = 25; double Arg4 = 12.5; verify_case(0, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 90; int Arg3 = 20; double Arg4 = 73.30000000000001; verify_case(1, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 384; int Arg2 = 3; int Arg3 = 1; double Arg4 = 18.344490479047746; verify_case(2, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 999; int Arg1 = 333; int Arg2 = 0; int Arg3 = 100; double Arg4 = 100.0; verify_case(3, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 333; int Arg2 = 0; int Arg3 = 100; double Arg4 = 0.0; verify_case(4, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SimplifiedDarts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
