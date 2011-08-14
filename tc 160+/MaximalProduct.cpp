#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[21][101][101];
long long go(int k, int s, int start) {
    if (start > s) {
        return 0;
    }
    if (k == 1) {
        return s;
    }
    long long &ret = dp[k][s][start];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int x=start; x<=s; ++x) {
        ret = max(ret, x * go(k-1, s-x, x));
    }

    return ret;
}

class MaximalProduct {
	public:
	long long maximalProduct(int s, int k) {
		memset(dp, 0xff, sizeof dp);

        return go(k, s, 1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; long long Arg2 = 36LL; verify_case(0, Arg2, maximalProduct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; long long Arg2 = 10LL; verify_case(1, Arg2, maximalProduct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; long long Arg2 = 1LL; verify_case(2, Arg2, maximalProduct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 13; int Arg1 = 8; long long Arg2 = 32LL; verify_case(3, Arg2, maximalProduct(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 2; long long Arg2 = 12LL; verify_case(4, Arg2, maximalProduct(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MaximalProduct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
