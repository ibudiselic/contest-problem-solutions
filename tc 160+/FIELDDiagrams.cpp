#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[31][35];
int O;
long long go(int order, int level) {
    order = min(order, O-level);
    if (order <= 0) {
        return 1;
    }

    long long &ret = dp[order][level];
    if (ret != -1) {
        return ret;
    }

    ret = 1;
    for (int i=1; i<=order; ++i) {
        ret += go(i, level+1);
    }

    return ret;
}

class FIELDDiagrams {
	public:
	long long countDiagrams(int fieldOrder) {
		memset(dp, 0xff, sizeof dp);
        O = fieldOrder;

        return go(fieldOrder, 0)-1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FIELDDiagrams ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
