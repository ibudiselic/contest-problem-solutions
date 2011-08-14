#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CalculatorDisplay {
	public:
	string numberDivision(int digits, long long n, long long d) {
		if (n == 0)
			return "0";

		if (n >= d) {
			int k = n/d;

			ostringstream os;
			os << k;
			if (n == k*d)
				return os.str().size() <= digits ? os.str() : "E";

			os << '.';

			n -= k*d;
			n *= 10;

			for (int i=0; i<30 && n>0; ++i) {
				os << n/d;
				n -= n/d * d;
				n *= 10;
			}

			return os.str().size() <= digits+1 ? os.str() : "E";
		} else {
			ostringstream os;
			os << '.';

			n *= 10;
			for (int i=0; i<30 && n>0; ++i) {
				os << n/d;
				n -= n/d * d;
				n *= 10;
			}
			return os.str().size() <= digits+1 ? os.str() : "E";
		}
		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10005; int Arg2 = 400; string Arg3 = "25.0125"; verify_case(0, Arg3, numberDivision(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 10005; int Arg2 = 400; string Arg3 = "E"; verify_case(1, Arg3, numberDivision(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 8; string Arg3 = ".125"; verify_case(2, Arg3, numberDivision(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 434544; int Arg2 = 352; string Arg3 = "1234.5"; verify_case(3, Arg3, numberDivision(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 1; int Arg2 = 3; string Arg3 = "E"; verify_case(4, Arg3, numberDivision(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 13; int Arg1 = 0; int Arg2 = 987654321; string Arg3 = "0"; verify_case(5, Arg3, numberDivision(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CalculatorDisplay ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
