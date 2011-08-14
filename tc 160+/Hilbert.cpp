#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int go(int x, int y, int k) {
	if (k == 0)
		return 0;

	int sz = (1<<(k-1));
	int quad = sz*sz;
	if (x <= sz) {
		if (y <= sz)
			return go(y, x, k-1);
		else
			return quad + go(x, y-sz, k-1);
	} else {
		if (y > sz)
			return 2*quad + go(x-sz, y-sz, k-1);
		else
			return 3*quad + go(sz-y+1, 2*sz-x+1, k-1);
	}
}
class Hilbert {
	public:
	int steps(int k, int x, int y) {
		return go(x, y, k);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; int Arg3 = 13; verify_case(0, Arg3, steps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(1, Arg3, steps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 32768; int Arg2 = 1; int Arg3 = 1073741823; verify_case(2, Arg3, steps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, steps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 546; int Arg2 = 109; int Arg3 = 955129; verify_case(4, Arg3, steps(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 15; int Arg1 = 30000; int Arg2 = 30000; int Arg3 = 706873514; verify_case(5, Arg3, steps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Hilbert ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
