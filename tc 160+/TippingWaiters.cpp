#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TippingWaiters {
	public:
	int possiblePayments(long long bill, long long cash) {
		long long tip = 0;
		while (bill%5 != 0) {
			++tip;
			++bill;
		}

		int sol = 0;
		while (bill <= cash) {
			if (tip*100 > bill*10)
				break;
			if (5*bill <= tip*100)
				++sol;
			bill += 5;
			tip += 5;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 100; int Arg2 = 0; verify_case(0, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 23; int Arg1 = 100; int Arg2 = 1; verify_case(1, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 24; int Arg2 = 0; verify_case(2, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 220; int Arg1 = 239; int Arg2 = 1; verify_case(3, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1234567; int Arg1 = 12345678; int Arg2 = 14440; verify_case(4, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1880000000; int Arg1 = 1980000000; int Arg2 = 210527; verify_case(5, Arg2, possiblePayments(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 171000000; int Arg1 = 179999999; int Arg2 = 0; verify_case(6, Arg2, possiblePayments(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TippingWaiters ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
