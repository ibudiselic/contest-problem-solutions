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

int sqr(int x) { return x*x; }
double dist(int x1, int y1, int x2, int y2) {
	return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
class EllipseCoverage {
	public:
	int calculateCoverage(int x1, int y1, int x2, int y2, int d) {
		int sol = 0;
		for (int x=-500; x<=500; ++x)
			for (int y=-500; y<=500; ++y)
				if (dist(x, y, x1, y1) + dist(x, y, x2, y2) < d - 1e-9)
					++sol;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 4; int Arg5 = 9; verify_case(0, Arg5, calculateCoverage(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = -3; int Arg1 = 0; int Arg2 = 3; int Arg3 = 0; int Arg4 = 10; int Arg5 = 59; verify_case(1, Arg5, calculateCoverage(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 12; int Arg2 = 8; int Arg3 = 14; int Arg4 = 50; int Arg5 = 1941; verify_case(2, Arg5, calculateCoverage(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 200; int Arg5 = 31397; verify_case(3, Arg5, calculateCoverage(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 13; int Arg1 = -23; int Arg2 = 49; int Arg3 = 91; int Arg4 = 200; int Arg5 = 25187; verify_case(4, Arg5, calculateCoverage(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EllipseCoverage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
