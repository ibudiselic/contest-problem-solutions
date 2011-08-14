#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FoxMakingDiceEasy {
	public:
	int theCount(int N, int K) {
		if (N < 6) {
            return 0;
        }
        int sol = 0;
        while (K < 2*N) {
            int ways = max(0, (K<=N+1 ? (K-1)/2 : (2*N-K+1)/2));
            sol += ways*(ways-1)*(ways-2)/3;
            ++K;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 1; int Arg2 = 105800; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 46; int Arg2 = 504; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 48; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxMakingDiceEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
