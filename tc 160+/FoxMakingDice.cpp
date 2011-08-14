#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[4][1001];
int N, K;
long long go(int p, int n) {
    long long &ret = dp[p][n];
    if (ret != -1) {
        return ret;
    }
    if (p == 3) {
        return (ret = 1);
    }
    if (2*n+1 > K) {
        return (ret = 0);
    }
    return (ret = go(p+1, n+1) + go(p, n+1));
}
class FoxMakingDice {
	public:
	long long theCount(int N_, int K_) {
		N = N_;
        K = K_;
        if (N<6 || K>2*N-5) {
            return 0;
        }
        K = max(K, 7);
        long long sol = 0;
        while (K <= 2*N-5) {
            memset(dp, 0xff, sizeof dp);
            sol += go(0, max(1, K-N));
            ++K;
        }
        return sol*2;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; long long Arg2 = 2LL; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; long long Arg2 = 0LL; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 1; long long Arg2 = 20625666000LL; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 456; int Arg1 = 123; long long Arg2 = 879075732LL; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 913; int Arg1 = 1014; long long Arg2 = 4506149340LL; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxMakingDice ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
