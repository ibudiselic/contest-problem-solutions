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

#define EPS 1e-9

class Airways {
	public:
	double distance(int n, int east, int north) {
		double step = 2.0*M_PI/n;
		double direct = sqrt(north*north + east*east);

		double ang = atan2(north, east);
		if (ang < 0)
			ang += 2*M_PI;

		double sol = 1e32;

		for (int i=0; i<n; ++i) {
			double a = i*step;

			if (fabs(a-ang) <= EPS)
				return direct;

			double b = (i+1)*step;

			if (a<=ang+EPS && ang-EPS<=b) {
				b -= a;
				double u = direct * sin(ang-a)/sin(M_PI-b);
				double v = direct * sin(a+b-ang)/sin(M_PI-b);

				sol = min(sol, u+v);
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = -219; int Arg2 = 0; double Arg3 = 437.99999999999994; verify_case(0, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 171; int Arg2 = 0; double Arg3 = 171.0; verify_case(1, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 233; int Arg2 = 3111; double Arg3 = 3344.0000000000005; verify_case(2, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = -3840; int Arg2 = -1768; double Arg3 = 4243.534462721784; verify_case(3, Arg3, distance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Airways ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
