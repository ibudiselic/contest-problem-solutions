#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Multiples {
	public:
	int number(int min, int max, int factor) {
		int sol = 0;

		while (min <= max) {
			sol += (min%factor == 0);
			++min;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 14; int Arg2 = 5; int Arg3 = 3; verify_case(0, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 24; int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = -123456; int Arg1 = 654321; int Arg2 = 997; int Arg3 = 780; verify_case(2, Arg3, number(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = -75312; int Arg1 = 407891; int Arg2 = 14; int Arg3 = 34515; verify_case(3, Arg3, number(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Multiples ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
