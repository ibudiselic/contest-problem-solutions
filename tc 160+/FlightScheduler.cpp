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

double calc(double D, double K, double em, double tof, int n) {
	return n*(tof + em*(exp(D/K/n) - 1));
}
class FlightScheduler {
	public:
	double minimizeFuel(int distance, int K, int emptyMass, int takeoffFuel) {
		double sol = 1e64;
		int lo = 1;
		int hi = 2000000000;

		while (hi-lo > 20) {
			int m1 = lo + (hi-lo)/3;
			int m2 = m1 + (hi-lo)/3;

			const double t1 = calc(distance, K, emptyMass, takeoffFuel, m1);
			const double t2 = calc(distance, K, emptyMass, takeoffFuel, m2);
			sol = min(sol, min(t1, t2));
			if (t1 < t2)
				hi = m2;
			else
				lo = m1;
		}

		while (lo <= hi)
			sol = min(sol, calc(distance, K, emptyMass, takeoffFuel, lo++));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 40000; int Arg1 = 100000; int Arg2 = 150000; int Arg3 = 5000; double Arg4 = 76420.82744805096; verify_case(0, Arg4, minimizeFuel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 40000; int Arg1 = 55000; int Arg2 = 150000; int Arg3 = 5000; double Arg4 = 138450.61724934017; verify_case(1, Arg4, minimizeFuel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 500; int Arg2 = 1000; int Arg3 = 50; double Arg4 = 2664.9853821314487; verify_case(2, Arg4, minimizeFuel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000; int Arg1 = 100; int Arg2 = 200; int Arg3 = 5; double Arg4 = 24635.869665316768; verify_case(3, Arg4, minimizeFuel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 140000; int Arg1 = 4; int Arg2 = 10000; int Arg3 = 10; double Arg4 = 3.6576871282155204E8; verify_case(4, Arg4, minimizeFuel(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FlightScheduler ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
