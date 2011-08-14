#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class OneDigitDifference {
	public:
	int getSmallest(int N) {
		if (N == 0) {
            return 1;
        }
        long long p10 = 10;
        while (N >= p10) {
            p10 *= 10;
        }
        p10 /= 10;
        return N%p10;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 0; verify_case(0, Arg1, getSmallest(Arg0)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 1; verify_case(1, Arg1, getSmallest(Arg0)); }
	void test_case_2() { int Arg0 = 900000123; int Arg1 = 123; verify_case(2, Arg1, getSmallest(Arg0)); }
	void test_case_3() { int Arg0 = 30000; int Arg1 = 0; verify_case(3, Arg1, getSmallest(Arg0)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 7; verify_case(4, Arg1, getSmallest(Arg0)); }
	void test_case_5() { int Arg0 = 1907654321; int Arg1 = 907654321; verify_case(5, Arg1, getSmallest(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    OneDigitDifference ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
