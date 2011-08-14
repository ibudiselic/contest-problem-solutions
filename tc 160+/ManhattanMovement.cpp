#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class ManhattanMovement {
	public:
	double getDistance(int a, int b, int x0, int y0) {
		if (a == 0)
			return fabs(y0 - 1.0/b);
		if (b == 0)
			return fabs(x0 - 1.0/a);

		return min(fabs(x0 - (1.0 - double(b)*y0)/a), fabs(y0 - (1.0 - double(a)*x0)/b));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = -2; int Arg3 = 3; double Arg4 = 1.5; verify_case(0, Arg4, getDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 37; int Arg1 = 37; int Arg2 = 42; int Arg3 = 19; double Arg4 = 60.97297297297297; verify_case(1, Arg4, getDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = -100; int Arg1 = 0; int Arg2 = -999999; int Arg3 = 314159; double Arg4 = 999998.99; verify_case(2, Arg4, getDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = -2147483648; int Arg2 = 1; int Arg3 = 100000; double Arg4 = 100000.00000000047; verify_case(3, Arg4, getDistance(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ManhattanMovement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
