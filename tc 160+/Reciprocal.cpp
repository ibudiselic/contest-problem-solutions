#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Reciprocal {
	public:
	string digits(int x, int d, int n) {
		int cur = 1;
		int pot = 10;
		--d;
		while (d > 0) {
			if (d%2 == 1)
				cur = cur*pot % x;

			pot = pot*pot % x;
			d /= 2;
		}

		string sol;
		for (int i=0; i<n; ++i) { cur = cur%x * 10; sol += char(cur/x + '0'); }

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 2; int Arg2 = 4; string Arg3 = "4285"; verify_case(0, Arg3, digits(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 1; int Arg2 = 7; string Arg3 = "0001000"; verify_case(1, Arg3, digits(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5000; int Arg2 = 8; string Arg3 = "33333333"; verify_case(2, Arg3, digits(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 9; int Arg2 = 13; string Arg3 = "0001000100010"; verify_case(3, Arg3, digits(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7549; int Arg1 = 50000; int Arg2 = 1; string Arg3 = "0"; verify_case(4, Arg3, digits(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Reciprocal ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
