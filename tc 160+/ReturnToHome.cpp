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

inline int sqr(int x) { return x*x; }
class ReturnToHome {
	public:
	double goHome(int X, int Y, int D, int T) {
		const double d = sqrt(sqr(X) + sqr(Y));

		double sol = d;
		sol = min(sol, T + fabs(d-D));
		sol = min(sol, floor(d/D + 1e-9)*T + fabs(d - floor(d/D + 1e-9)*D));
		sol = min(sol, max(2.0, ceil(d/D - 1e-9))*T);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 8; int Arg2 = 5; int Arg3 = 3; double Arg4 = 6.0; verify_case(0, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 6; int Arg3 = 3; double Arg4 = 4.0; verify_case(1, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 400; int Arg1 = 300; int Arg2 = 150; int Arg3 = 10; double Arg4 = 40.0; verify_case(2, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 318; int Arg1 = 445; int Arg2 = 1200; int Arg3 = 800; double Arg4 = 546.9451526432975; verify_case(3, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 8; int Arg2 = 3; int Arg3 = 2; double Arg4 = 7.0; verify_case(4, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 1000; int Arg3 = 5; double Arg4 = 10.0; verify_case(5, Arg4, goHome(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ReturnToHome ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
