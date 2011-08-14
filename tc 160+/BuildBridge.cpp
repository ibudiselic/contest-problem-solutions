#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BuildBridge {
	public:
	int howManyCards(int D, int L) {
		double x = 0;
		for (int k=1; ; ++k) {
			x += L / (2.0*k);
			if (x >= D-1e-9)
				return k;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, howManyCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 1; verify_case(1, Arg2, howManyCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 1; verify_case(2, Arg2, howManyCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 2; verify_case(3, Arg2, howManyCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 1; int Arg2 = 36865412; verify_case(4, Arg2, howManyCards(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BuildBridge ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
