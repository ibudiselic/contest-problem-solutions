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

double sqr(double x) {
	return x*x;
}
double dist(double cur, double next, int spread) {
	return sqrt(sqr(spread) + sqr((cur-next)/2 + next));
}
class ShoelaceLength {
	public:
	double calculate(int sw, int ew, int spread, int n) {
		double inc = double(sw-ew)/(n-1);

		double cur = ew;
		double sol = 0.0;

		for (int i=1; i<n; ++i) {
			double next = ew + i*inc;

			sol += 2*dist(cur, next, spread);

			cur = next;
		}

		return sol + sw;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; double Arg4 = 6.47213595499958; verify_case(0, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 10; double Arg4 = 111.1786186482248; verify_case(1, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; int Arg3 = 10; double Arg4 = 102.17861864822481; verify_case(2, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; double Arg4 = 3.8284271247461903; verify_case(3, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 19; int Arg3 = 2; double Arg4 = 107.97663296253066; verify_case(4, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ShoelaceLength ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
