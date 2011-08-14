#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int m, int n) {
	return n==0 ? m : gcd(n, m%n);
}
class FracCount {
	public:
	int position(int numerator, int denominator) {
		int cnt = 1;
		int n = 1;
		int d = 2;
		while (1) {
			if (n == numerator && d == denominator)
				return cnt;

			if (n == d) {
				++d;
				n = 1;
				continue;
			}
			if (gcd(n, d) == 1)
				++cnt;
			++n;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, position(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 11; verify_case(1, Arg2, position(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999; int Arg1 = 1000; int Arg2 = 304191; verify_case(2, Arg2, position(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FracCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
