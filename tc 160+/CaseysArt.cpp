#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CaseysArt {
	public:
	double howManyWays(int length, int width) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; double Arg2 = 4.0; verify_case(0, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; double Arg2 = 4.0; verify_case(1, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.0; verify_case(2, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 9; double Arg2 = 384.0; verify_case(3, Arg2, howManyWays(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CaseysArt ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
