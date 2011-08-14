#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CakeDivision {
	public:
	double ratio(double length, double width, int pieces) {
		if (pieces == 1)
			return max(length, width)/min(length, width);

		double ret = 1e32;
		for (int i=1; i<=pieces/2; ++i)
			ret = min(
					ret,
					min(
						max(ratio(length*i/pieces, width, i), ratio(length*(1-double(i)/pieces), width, pieces-i)),
						max(ratio(length, width*i/pieces, i), ratio(length, width*(1-double(i)/pieces), pieces-i))
					)
				  );

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 6; double Arg3 = 1.0; verify_case(0, Arg3, ratio(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; double Arg3 = 1.8; verify_case(1, Arg3, ratio(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 333; int Arg1 = 333; int Arg2 = 9; double Arg3 = 1.0; verify_case(2, Arg3, ratio(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 500; int Arg1 = 1; int Arg2 = 10; double Arg3 = 50.0; verify_case(3, Arg3, ratio(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 950; int Arg1 = 430; int Arg2 = 9; double Arg3 = 1.2573099415204678; verify_case(4, Arg3, ratio(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CakeDivision ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
