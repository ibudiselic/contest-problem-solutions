#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Inchworm {
	public:
	int lunchtime(int branch, int rest, int leaf) {
		int sol = 0;

		for (int dist=0; dist<=branch; dist += rest)
			sol += (dist%leaf==0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 2; int Arg2 = 4; int Arg3 = 3; verify_case(0, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 6; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; int Arg2 = 7; int Arg3 = 1; verify_case(2, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 21; int Arg1 = 7; int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 16; int Arg2 = 5; int Arg3 = 1; verify_case(4, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 3; int Arg2 = 7; int Arg3 = 48; verify_case(5, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1000; int Arg1 = 7; int Arg2 = 3; int Arg3 = 48; verify_case(6, Arg3, lunchtime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Inchworm ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
