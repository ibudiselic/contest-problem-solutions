#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BalancedTrees {
	public:
	int fewest(int h, int k) {
		if (h <= 0) return 0;
		return 1+fewest(h-1, k)+fewest(h-k-1, k);
	}
	int maxHeight(int k, int n) {
		for (int h=0; ; ++h)
			if (fewest(h, k) > n)
				return h-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 4; verify_case(0, Arg2, maxHeight(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 40; int Arg2 = 9; verify_case(1, Arg2, maxHeight(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 5; verify_case(2, Arg2, maxHeight(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BalancedTrees ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
