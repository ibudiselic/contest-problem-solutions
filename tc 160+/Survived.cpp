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

class Survived {
	public:
	double minTime(int x, int y, int V, int U) {
		if (x==0 && y==0)
			return 0.0;

		const double a = V*V - U*U;
		const double b = 2*x*U;
		const double c = -(x*x + y*y);

		if (fabs(a) < 1e-12) {
			if (b == 0)
				return -1.0;
			const double t = -c/b;
			return t>0 ? t:-1.0;
		}

		double D = b*b - 4*a*c;
		if (D < 0)
			return -1.0;
		D = sqrt(D);

		double t1 = (-b + D)/2/a;
		double t2 = (-b - D)/2/a;
		if (t1 > t2)
			swap(t1, t2);

		if (t1<0 && t2<0)
			return -1.0;
		if (t1 < 0)
			return t2;
		return t1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = -1; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; double Arg4 = 1.4142135623730951; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; double Arg4 = 2.0593413823019864; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.0; verify_case(4, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 12; int Arg2 = 24; int Arg3 = 26; double Arg4 = 1.3; verify_case(5, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Survived ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
