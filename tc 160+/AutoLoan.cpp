#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double calc(double price, double p, int cnt, double i) {
	while (cnt--) {
		price *= (1 + i/1200.0);
		price -= p;
		if (price < 0)
			return -1.0;
	}

	return price;
}
class AutoLoan {
	public:
	double interestRate(double price, double monthlyPayment, int loanTerm) {
		double lo=0, hi=100;

		for (int i=0; i<1000; ++i) {
			double mid = (lo+hi)/2;
			if (calc(price, monthlyPayment, loanTerm, mid) >= 0)
				hi = mid;
			else
				lo = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = 6800; double Arg1 = 100; int Arg2 = 68; double Arg3 = 1.3322616182218813E-13; verify_case(0, Arg3, interestRate(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arg0 = 2000; double Arg1 = 510; int Arg2 = 4; double Arg3 = 9.56205462458368; verify_case(1, Arg3, interestRate(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arg0 = 15000; double Arg1 = 364; int Arg2 = 48; double Arg3 = 7.687856394581649; verify_case(2, Arg3, interestRate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AutoLoan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
