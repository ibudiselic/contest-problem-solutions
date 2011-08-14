#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TemperatureScales {
	public:
	double convert(int f1, int b1, int f2, int b2, int t) {
		double x = double(b2-f2)/(b1-f1);
		double y = f2 - x*f1;
		return t*x + y;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 100; int Arg2 = 0; int Arg3 = 100; int Arg4 = 28; double Arg5 = 28.0; verify_case(0, Arg5, convert(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 100; int Arg2 = 1; int Arg3 = 101; int Arg4 = 28; double Arg5 = 29.0; verify_case(1, Arg5, convert(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = -1000; int Arg1 = -999; int Arg2 = -1000; int Arg3 = 1000; int Arg4 = 1000; double Arg5 = 3999000.0; verify_case(2, Arg5, convert(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = -10; int Arg1 = 0; int Arg2 = 1; int Arg3 = 2; int Arg4 = 17; double Arg5 = 3.7; verify_case(3, Arg5, convert(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 17; int Arg1 = 98; int Arg2 = -123; int Arg3 = 12; int Arg4 = 22; double Arg5 = -114.66666666666667; verify_case(4, Arg5, convert(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TemperatureScales ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
