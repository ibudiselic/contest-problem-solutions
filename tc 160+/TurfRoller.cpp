#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TurfRoller {
	public:
	int stripNum(int lawnWidth, int lawnHeight, int stripAngle, int stripLength, int stripBreadth) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 60; int Arg1 = 90; int Arg2 = 39; int Arg3 = 60; int Arg4 = 25; int Arg5 = 8; verify_case(0, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 26; int Arg1 = 6; int Arg2 = 38; int Arg3 = 20; int Arg4 = 14; int Arg5 = 2; verify_case(1, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 9; int Arg2 = 0; int Arg3 = 3; int Arg4 = 3; int Arg5 = 9; verify_case(2, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; int Arg2 = 45; int Arg3 = 10; int Arg4 = 10; int Arg5 = 1; verify_case(3, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 45; int Arg3 = 2; int Arg4 = 1; int Arg5 = 6; verify_case(4, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 70; int Arg1 = 70; int Arg2 = 45; int Arg3 = 76; int Arg4 = 24; int Arg5 = 6; verify_case(5, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 45; int Arg3 = 2; int Arg4 = 1; int Arg5 = 5112; verify_case(6, Arg5, stripNum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TurfRoller ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
