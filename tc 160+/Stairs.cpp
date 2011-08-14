#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Stairs {
	public:
	int designs(int maxHeight, int minWidth, int totalHeight, int totalWidth) {
		int sol = 0;
		for (int r=1; r<=maxHeight; ++r) {
			if (totalHeight % r) continue;
			if (totalHeight/r >= 2)
				if (totalWidth%(totalHeight/r - 1) == 0)
					sol += (totalWidth/(totalHeight/r-1) >= minWidth);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 22; int Arg1 = 25; int Arg2 = 100; int Arg3 = 100; int Arg4 = 1; verify_case(0, Arg4, designs(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 25; int Arg1 = 25; int Arg2 = 60; int Arg3 = 100; int Arg4 = 2; verify_case(1, Arg4, designs(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 1; int Arg2 = 600; int Arg3 = 600; int Arg4 = 6; verify_case(2, Arg4, designs(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Stairs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
