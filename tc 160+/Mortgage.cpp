#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool calc(long long loan, int interest, long long x, int term) {
	long long start = loan;
	while (term--) {
		loan -= x;
		if (loan <= 0)
			return true;
		loan += (loan*interest+11999)/12000;
		if (loan <= 0)
			return true;
		if (loan >= start)
			return false;
	}
	return false;
}
class Mortgage {
	public:
	int monthlyPayment(int loan, int interest, int term) {
		int lo = 1;
		int hi = loan;

		term *= 12;
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (calc(loan, interest, mid, term))
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 50; int Arg2 = 1; int Arg3 = 86; verify_case(0, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2000000000; int Arg1 = 6000; int Arg2 = 1; int Arg3 = 671844808; verify_case(1, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000; int Arg3 = 988143; verify_case(2, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 129; int Arg2 = 30; int Arg3 = 10868; verify_case(3, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1999999999; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 1976284585; verify_case(4, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Mortgage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
