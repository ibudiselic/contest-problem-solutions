#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<double> S;
bool done[4][3];
double dp[4][3];
inline double val(double p, double q, double a, double b, double c, double d) {
	return p*q*a + p*(1-q)*b + (1-p)*q*c + (1-p)*(1-q)*d;
}
double calc(double p, double a, double b, double c, double d) {
	double lo = 0.0;
	double hi = 1.0;
	for (int i=0; i<200; ++i) {
		double mid1 = lo + (hi-lo)/3;
		double mid2 = mid1 + (hi-lo)/3;
		if (val(p, mid1, a, b, c, d) < val(p, mid2, a, b, c, d))
			hi = mid2;
		else
			lo = mid1;
	}

	return val(p, (lo+hi)/2, a, b, c, d);
}
double go(int balls, int strikes) {
	if (balls==4)
		return 0.0;

	if (strikes == 3)
		return 1.0;

	if (done[balls][strikes])
		return dp[balls][strikes];

	double x = go(balls+1, strikes  );
	double y = go(balls  , strikes+1);

	double a = S[0]*x + S[1]*y;
	double b = S[2]*x + S[3]*y;
	double c = S[4]*x + S[5]*y;
	double d = S[6]*x + S[7]*y;

	double loP=0.0, hiP=1.0;
	for (int i=0; i<200; ++i) {
		double midP1 = loP + (hiP-loP)/3;
		double midP2 = midP1 + (hiP-loP)/3;
		if (calc(midP1, a, b, c, d) > calc(midP2, a, b, c, d))
			hiP = midP2;
		else
			loP = midP1;
	}

	done[balls][strikes] = 1;
	return dp[balls][strikes] = calc((loP+hiP)/2, a, b, c, d);
}

class Pitches {
	public:
	double strikeOut(vector <double> stats, int balls, int strikes) {
		S = stats;

		memset(done, 0, sizeof done);
		return go(balls, strikes);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = { 0, 0,
  0, 1,
  0, 1,
  0, 0 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; double Arg3 = 0.5; verify_case(0, Arg3, strikeOut(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arr0[] = { 0.375, 0.25,
  0.375, 0.25,
  0.375, 0.25,
  0.375, 0.25 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; double Arg3 = 0.39208984375; verify_case(1, Arg3, strikeOut(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arr0[] = { 0.33, 0,
  0, 1,
  0.44, 0,
  0, 1 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.0; verify_case(2, Arg3, strikeOut(Arg0, Arg1, Arg2)); }
	void test_case_3() { double Arr0[] = { 0, 1,
  0, 1,
  0, 0,
  0, 0 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.0; verify_case(3, Arg3, strikeOut(Arg0, Arg1, Arg2)); }
	void test_case_4() { double Arr0[] = { 0, 0.4,
  0.05, 0.75,
  0.2, 0.7,
  0.85, 0.1 }; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; double Arg3 = 0.32194802205218886; verify_case(4, Arg3, strikeOut(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Pitches ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
