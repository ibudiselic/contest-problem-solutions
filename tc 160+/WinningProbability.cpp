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

int pw, pl, gl, mw;
double choose[201][201];
double f(double p) {
	double ret = 0.0;

	for (int win=mw; win<=gl; ++win)
		ret += pow(p, win)*pow((1-p), gl-win)*choose[gl][win];

	return ret;
}
double w(double p) {
	return pow(p, pw)*pow((1-p), pl)*choose[pw+pl][pw];
}

class WinningProbability {
	public:
	double probability(int prevWins, int prevLosses, int gamesLeft, int mustWin) {
		choose[0][0] = 1.0;
		for (int i=1; i<201; ++i) {
			choose[i][0] = 1.0;
			for (int j=1; j<201; ++j)
				choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
		}
		pw = prevWins;
		pl = prevLosses;
		gl = gamesLeft;
		mw = mustWin;

		double num = f(0)*w(0) + f(1)*w(1);
		for (int i=1; i<1000000; i+=2)
			num += 4*f(i*1e-6)*w(i*1e-6);

		for (int i=2; i<1000000; i+=2)
			num += 2*f(i*1e-6)*w(i*1e-6);

		double denom = w(0) + w(1);
		for (int i=1; i<1000000; i+=2)
			denom += 4*w(i*1e-6);

		for (int i=2; i<1000000; i+=2)
			denom += 2*w(i*1e-6);

		return num/denom;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.75; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 3; int Arg2 = 4; int Arg3 = 4; double Arg4 = 0.0142857142857; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; int Arg2 = 5; int Arg3 = 1; double Arg4 = 0.9995284409077; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 20; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.0454545454545; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.5; verify_case(4, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WinningProbability ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
