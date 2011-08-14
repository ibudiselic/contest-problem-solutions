#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int rem;
bool done[101][101][2][4];
double dp[101][101][2][4];
double go(int red, int blue, bool lastRedMine, int take) {
	if (red+blue == rem)
		return 1-lastRedMine;

	if (done[red][blue][lastRedMine][take])
		return dp[red][blue][lastRedMine][take];

	done[red][blue][lastRedMine][take] = 1;
	double ret = 0;

	if (take == 0) {
		ret = 1.0;
		for (int i=1; i<=3; ++i)
			if (red+blue-i >= rem)
				ret = min(ret, 1-go(red, blue, 1-lastRedMine, i));
	} else {
		if (red > 0)
			ret += double(red)/(red+blue) * go(red-1, blue, 1, take-1);
		if (blue > 0)
			ret += double(blue)/(red+blue) * go(red, blue-1, lastRedMine, take-1);
	}

	return dp[red][blue][lastRedMine][take] = ret;
}
class LastMarble {
	public:
	double winningChance(int red, int blue, int removed) {
		memset(done, 0, sizeof done);
		rem = removed;

		return 1-go(red, blue, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; double Arg3 = 0.5; verify_case(0, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 0; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 0; double Arg3 = 0.6666666666666666; verify_case(2, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.5; verify_case(3, Arg3, winningChance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LastMarble ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
