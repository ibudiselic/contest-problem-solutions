#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int M;
struct mat {
	long long x[2][2];
};
mat operator*(const mat &a, const mat &b) {
	mat c;
	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j) {
			c.x[i][j] = 0;
			for (int k=0; k<2; ++k)
				c.x[i][j] += a.x[i][k]*b.x[k][j];
			c.x[i][j] %= M;
		}
	return c;
}
class BigFibonacci {
	public:
	int fibNumber(string index, int M_) {
		M = M_;
		istringstream is(index);
		unsigned long long x;
		is >> x;
		if (x == 0) return 0;
		--x;

		mat A;
		A.x[0][0] = 1; A.x[0][1] = 1;
		A.x[1][0] = 1; A.x[1][1] = 0;

		mat I;
		I.x[0][0] = 1; I.x[0][1] = 0;
		I.x[1][0] = 0; I.x[1][1] = 1;

		for (int i=0; (1ull<<i)<=x; ++i) {
			if ((x&(1ull<<i)) != 0) I = I * A;
			A = A * A;
		}
		return I.x[0][0] % M;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7"; int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "5"; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; int Arg1 = 23; int Arg2 = 0; verify_case(2, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "17"; int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "54"; int Arg1 = 341890; int Arg2 = 177022; verify_case(4, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "300"; int Arg1 = 77531; int Arg2 = 0; verify_case(5, Arg2, fibNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BigFibonacci ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
