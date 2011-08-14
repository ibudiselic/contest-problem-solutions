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

double calc(double x) {
	return exp(-x*x);
}
class NumericalIntegral {
	public:
	string integrate(double x1, double x2) {
		double d = (x2-x1)/10000000.0;

		double sol = 0.0;
		for (int c=0; c<10000000; ++c)
			sol += calc(x1+c*d)*d;

		char buff[100];
		sprintf(buff, "%1.5f", sol);
		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = -0.5; double Arg1 = 0.5; string Arg2 = "0.92256"; verify_case(0, Arg2, integrate(Arg0, Arg1)); }
	void test_case_1() { double Arg0 = 0.0; double Arg1 = 0.1; string Arg2 = "0.09967"; verify_case(1, Arg2, integrate(Arg0, Arg1)); }
	void test_case_2() { double Arg0 = -9.0001; double Arg1 = -9.0; string Arg2 = "0.00000"; verify_case(2, Arg2, integrate(Arg0, Arg1)); }
	void test_case_3() { double Arg0 = 2.71828183; double Arg1 = 3.14159265; string Arg2 = "0.00010"; verify_case(3, Arg2, integrate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumericalIntegral ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
