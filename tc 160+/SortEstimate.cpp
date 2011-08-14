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

/* return the largest double n such that c*n*lg(n) <= time */
class SortEstimate {
	public:
	double howMany(int c, int time) {
		double lo = 0;
		double hi = 1e8;

		for (int i=0; i<1000; ++i) {
			double mid = lo + (hi-lo)/2;

			if (c*mid*log(mid)/log(2) <= time)
				lo = mid;
			else
				hi = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 8; double Arg2 = 4.0; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 16; double Arg2 = 4.0; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arg1 = 12392342; double Arg2 = 23104.999312341137; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 2000000000; double Arg2 = 7.637495090348122E7; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SortEstimate ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
