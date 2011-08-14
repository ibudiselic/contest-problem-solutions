#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int y;
class MooresLaw {
	public:
	double calc(double x) {
		return x + y/pow(2.0, x/1.5);
	}
	double shortestComputationTime(int years) {
		y = years;
		double lo = 0;
		double hi = years;

		for (int i=0; i<100; ++i) {
			double mid1 = lo + (hi-lo)/3;
			double mid2 = hi - (hi-lo)/3;
			if (calc(mid1) < calc(mid2))
				hi = mid2;
			else
				lo = mid1;
		}
		return calc(lo);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; double Arg1 = 6.2044816339207705; verify_case(0, Arg1, shortestComputationTime(Arg0)); }
	void test_case_1() { int Arg0 = 3; double Arg1 = 2.870893001916099; verify_case(1, Arg1, shortestComputationTime(Arg0)); }
	void test_case_2() { int Arg0 = 47; double Arg1 = 8.82533252835082; verify_case(2, Arg1, shortestComputationTime(Arg0)); }
	void test_case_3() { int Arg0 = 123; double Arg1 = 10.907221008843223; verify_case(3, Arg1, shortestComputationTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MooresLaw ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
