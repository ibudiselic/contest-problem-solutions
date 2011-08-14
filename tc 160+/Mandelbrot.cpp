#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
Z0 = C Zn+1 = Zn*Zn+C
*/
struct Complex {
	double x, y;
	Complex(double a, double b): x(a), y(b) {}
};
Complex operator+(const Complex &a, const Complex &b) {
	return Complex(a.x+b.x, a.y+b.y);
}
Complex operator*(const Complex &a, const Complex &b) {
	return Complex(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}
double absz(const Complex &z) {
	return sqrt(z.x*z.x + z.y*z.y);
}
class Mandelbrot {
	public:
	int iterations(int max, double a, double b) {
		Complex z(a, b);
		Complex orig = z;
		for (int i=0; i<=max; ++i) {
			if (absz(z)>2)
				return i;
			z = z*z+orig;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; double Arg1 = 1; double Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, iterations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = -1; double Arg2 = -1; int Arg3 = 2; verify_case(1, Arg3, iterations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 30; double Arg1 = .25; double Arg2 = .25; int Arg3 = -1; verify_case(2, Arg3, iterations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 30; double Arg1 = -1.9; double Arg2 = 0; int Arg3 = -1; verify_case(3, Arg3, iterations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 30; double Arg1 = .375; double Arg2 = .3; int Arg3 = 21; verify_case(4, Arg3, iterations(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; double Arg1 = 2; double Arg2 = 2; int Arg3 = 0; verify_case(5, Arg3, iterations(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Mandelbrot ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
