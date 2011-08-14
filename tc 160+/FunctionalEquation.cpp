#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FunctionalEquation {
	public:
	long long minAbsSum(int C, int N, int xzero, int xprod, int xadd, int xmod, int yzero, int yprod, int yadd, int ymod) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 456; int Arg6 = 1; int Arg7 = 1; int Arg8 = 1; int Arg9 = 456; long long Arg10 = 0LL; verify_case(0, Arg10, minAbsSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 456; int Arg6 = 1; int Arg7 = 1; int Arg8 = 1; int Arg9 = 456; long long Arg10 = 5LL; verify_case(1, Arg10, minAbsSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 10000; int Arg2 = 654816386; int Arg3 = 163457813; int Arg4 = 165911619; int Arg5 = 987654321; int Arg6 = 817645381; int Arg7 = 871564816; int Arg8 = 614735118; int Arg9 = 876543210; long long Arg10 = 3150803357206LL; verify_case(2, Arg10, minAbsSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FunctionalEquation ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
