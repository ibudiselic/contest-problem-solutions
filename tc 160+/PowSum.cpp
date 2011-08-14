#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class PowSum {
	public:
	long long power(int a, int b) {
		long long ret = 1;
		while (b--)
			ret *= a;
		return ret;
	}
	int getSum(int low, int high, int p) {
		long long sol = 0;

		for (int i=low; i<=high; ++i)
			for (int j=1; j<=p; ++j)
				sol += power(i, j);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 2; int Arg3 = 20; verify_case(0, Arg3, getSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = -12; int Arg1 = 12; int Arg2 = 9; int Arg3 = 1637738440; verify_case(1, Arg3, getSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = -100; int Arg1 = 100; int Arg2 = 2; int Arg3 = 676700; verify_case(2, Arg3, getSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PowSum ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
