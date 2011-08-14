#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BitwiseEquations {
	public:
	long long kthPlusOrSolution(int x, int k) {
		long long sol = 0;
        long long dig = 0;
        while (x || k) {
            if ((x&1) == 0) {
                sol += ((long long)(k&1))<<dig;
                k >>= 1;
            }
            x >>= 1;
            ++dig;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; long long Arg2 = 2LL; verify_case(0, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; long long Arg2 = 18LL; verify_case(1, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; long long Arg2 = 5LL; verify_case(2, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1000000000; long long Arg2 = 2000000000LL; verify_case(3, Arg2, kthPlusOrSolution(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BitwiseEquations ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
