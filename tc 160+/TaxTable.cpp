#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
	100,000     117,250        25%             6,525.00

    117,250     178,650        28%            10,042.50

    178,650     319,100        33%            18,975.00

    319,100        -           35%            25,357.00
*/
int a[] = { 100000, 117250, 178650, 319100, 2000000000 };
double p[] = { 0.25, 0.28, 0.33, 0.35 };
double rem[] = { 6525, 10042.5, 18975, 25357 };

int round(double x) {
	return (int)(x+0.5);
}
class TaxTable {
	public:
	int income(int taxAmount) {
		for (int i=1; i<5; ++i) {
			double lo = a[i-1]*p[i-1] - rem[i-1];
			double hi = a[i]*p[i-1] - rem[i-1];

			if (lo<=taxAmount && taxAmount<=hi) {
				double x = taxAmount + rem[i-1];
				x /= p[i-1];
				return round(x);
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 47025; int Arg1 = 200000; verify_case(0, Arg1, income(Arg0)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = -1; verify_case(1, Arg1, income(Arg0)); }
	void test_case_2() { int Arg0 = 47026; int Arg1 = 200003; verify_case(2, Arg1, income(Arg0)); }
	void test_case_3() { int Arg0 = 86304; int Arg1 = 319027; verify_case(3, Arg1, income(Arg0)); }
	void test_case_4() { int Arg0 = 22792; int Arg1 = 117266; verify_case(4, Arg1, income(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TaxTable ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
