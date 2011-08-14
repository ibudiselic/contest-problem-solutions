#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class EscapeFromRectangle {
	public:
	int shortest(int x, int y, int w, int h) {
		return min(x, min(y, min(w-x, h-y)));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(0, Arg4, shortest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 10; int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, shortest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 653; int Arg1 = 375; int Arg2 = 1000; int Arg3 = 1000; int Arg4 = 347; verify_case(2, Arg4, shortest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 161; int Arg1 = 181; int Arg2 = 762; int Arg3 = 375; int Arg4 = 161; verify_case(3, Arg4, shortest(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EscapeFromRectangle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
