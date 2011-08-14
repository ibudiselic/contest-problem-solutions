#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AdditionCycles {
	public:
	int cycleLength(int n) {
		int x = n;
		int cnt = 0;
		do {
			const int sum = x/10 + x%10;
			x = x%10*10 + sum%10;
			++cnt;
		} while (x != n);
		return cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; int Arg1 = 4; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { int Arg0 = 55; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { int Arg0 = 71; int Arg1 = 12; verify_case(3, Arg1, cycleLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AdditionCycles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
