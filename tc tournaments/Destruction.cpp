#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[51][51][2];
bool done[51][51][2];

double go(int n, int k, bool top) {
	if (k == 0)
		return 0.5;
	if (n == 1)
		return (top ? 0.25 : 0.5);

	if (done[n][k][top])
		return dp[n][k][top];

	double a = go(n-1, k, top);
	const double b = go(n-1, k-1, 1);

	a /= (a+b);

	done[n][k][top] = 1;
	return dp[n][k][top] = a*b;
}
class Destruction {
	public:
	double minError(int numTests, int numDestroyed) {
		memset(done, 0, sizeof done);

		return 100*go(numTests, numDestroyed, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 50.0; verify_case(0, Arg2, minError(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; double Arg2 = 16.666666666666664; verify_case(1, Arg2, minError(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; double Arg2 = 0.03703703703704745; verify_case(2, Arg2, minError(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Destruction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
