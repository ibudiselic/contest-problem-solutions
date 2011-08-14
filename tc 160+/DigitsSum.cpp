#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DigitsSum {
	public:
	int sum(int n) {
		int res = 0;
		while (n > 0) {
			res += n%10;
			n /= 10;
		}
		return res;
	}
	int lastDigit(int n) {
		while (n >= 10)
			n = sum(n);

		return n;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12345; int Arg1 = 6; verify_case(0, Arg1, lastDigit(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, lastDigit(Arg0)); }
	void test_case_2() { int Arg0 = 999999999; int Arg1 = 9; verify_case(2, Arg1, lastDigit(Arg0)); }
	void test_case_3() { int Arg0 = 213413512; int Arg1 = 4; verify_case(3, Arg1, lastDigit(Arg0)); }
	void test_case_4() { int Arg0 = 314; int Arg1 = 8; verify_case(4, Arg1, lastDigit(Arg0)); }
	void test_case_5() { int Arg0 = 2147483647; int Arg1 = 1; verify_case(5, Arg1, lastDigit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigitsSum ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
