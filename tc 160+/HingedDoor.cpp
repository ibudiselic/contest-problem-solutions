#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class HingedDoor {
	public:
	int numSwings(int initialAngle, int reduction) {
		double x = initialAngle;

		for (int cnt=0; ; ++cnt) {
			if (x <= 5+1e-9)
				return cnt;
			x /= reduction;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, numSwings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 45; int Arg1 = 6; int Arg2 = 2; verify_case(1, Arg2, numSwings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, numSwings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 0; verify_case(3, Arg2, numSwings(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 73; int Arg1 = 5; int Arg2 = 2; verify_case(4, Arg2, numSwings(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HingedDoor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
