#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AmountApproximation {
	public:
	int approximate(long long D, long long p1, long long p2) {
		if (p1 > p2)
			swap(p1, p2);

		if (p1 == 1)
			return D;
		if (p1 == 2)
			return D + (D%2 == 1);

		long long sol = INT_MAX;
		long long cur = 0;
		while (cur <= D) {
			sol = min(sol, cur + (D-cur+p1-1)/p1 * p1);
			cur += p2;
		}

		return min(sol, cur);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 17; int Arg1 = 7; int Arg2 = 9; int Arg3 = 18; verify_case(0, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 17; int Arg1 = 7; int Arg2 = 13; int Arg3 = 20; verify_case(1, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 21; int Arg1 = 7; int Arg2 = 13; int Arg3 = 21; verify_case(2, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 37; int Arg1 = 9; int Arg2 = 17; int Arg3 = 43; verify_case(3, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 287341; int Arg1 = 2345; int Arg2 = 7253; int Arg3 = 287398; verify_case(4, Arg3, approximate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AmountApproximation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
