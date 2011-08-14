#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FactorialGCD {
	public:
	int factGCD(int a, int b) {
		int sol = 1;
		for (int p=2; (long long)p*p <= b; ++p)
			if (b%p == 0) {
				int d1 = 0;
				while (b%p == 0) { b /= p; ++d1; }
				int d2=0, t=a;
				while (t > 0) d2 += (t /= p);
				for (int i=0; i<min(d1, d2); ++i)
					sol *= p;
			}
		if (a >=b ) sol *= b;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 20; verify_case(0, Arg2, factGCD(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 5040; int Arg2 = 5040; verify_case(1, Arg2, factGCD(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 2425; int Arg2 = 1; verify_case(2, Arg2, factGCD(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 667024; int Arg1 = 1; int Arg2 = 1; verify_case(3, Arg2, factGCD(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 40; int Arg2 = 8; verify_case(4, Arg2, factGCD(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2097711064; int Arg1 = 2147483646; int Arg2 = 2147483646; verify_case(5, Arg2, factGCD(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FactorialGCD ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
