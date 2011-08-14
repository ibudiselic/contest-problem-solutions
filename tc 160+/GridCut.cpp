#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int go(int a, int b, int c) {
	if (c==0 || a*b==c)
		return 0;

	int ret = 1234567890;
	for (int i=1; i<=a; ++i)
		for (int j=1; j<=b; ++j)
			if (i*j >= c)
				ret = min(ret, i+j);

	ret = min(ret, a + (c%a != 0));

	return ret;
}
class GridCut {
	public:
	int cutLength(int width, int height, int n) {
		int sol = 1234567890;
		sol = min(sol, go(width, height, n));
		sol = min(sol, go(height, width, n));
		sol = min(sol, go(width, height, width*height-n));
		sol = min(sol, go(height, width, width*height-n));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; int Arg3 = 3; verify_case(0, Arg3, cutLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, cutLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 43; int Arg3 = 1; verify_case(2, Arg3, cutLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 15; int Arg3 = 8; verify_case(3, Arg3, cutLength(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 20; int Arg3 = 0; verify_case(4, Arg3, cutLength(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GridCut ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
