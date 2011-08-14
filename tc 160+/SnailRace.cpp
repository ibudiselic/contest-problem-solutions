#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int cnt, dist, snail, george;
double calc(double d) {
	const double td = d / george;
	const double dd = td * snail;
	const double t1 = (d-dd)/(george+snail);
	const double t2 = t1 + td;

	return t2*(cnt-1) + d/george;
}
class SnailRace {
	public:
	double shortestTime(int snails, int distance, int snailSpeed, int georgeSpeed) {
		cnt = snails;
		dist = distance;
		snail = snailSpeed;
		george = georgeSpeed;
		if (snail > george)
			return (dist-1)/(double)snail;

		const double t = 2*(cnt-1)*snail/(double)(george+snail) + 1;
		return calc((dist-1)/t);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 11; int Arg2 = 4; int Arg3 = 8; double Arg4 = 1.75; verify_case(0, Arg4, shortestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 12; int Arg2 = 2; int Arg3 = 100; double Arg4 = 0.502; verify_case(1, Arg4, shortestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 11; int Arg2 = 50; int Arg3 = 40; double Arg4 = 0.2; verify_case(2, Arg4, shortestTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 1; int Arg3 = 1000; double Arg4 = 0.09323356231599604; verify_case(3, Arg4, shortestTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SnailRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
