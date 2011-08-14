#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1000001];
const int mod = 1000000009;
int C[21][21];
// idea:
// formula for top
//      top = (nC0)x0 + (nC1)x1 + ... + (nCn)xn, xi>=1
// how many solutions?
// change each xi with (xi-1)
//      top = (nC0)(x0-1) + (nC1)(x1-1) + ... + (nCn)(xn-1), xi>=0
//      <=>
//      top - (nC0) - (nC1) - ... - (nCn) = (nC0)x0 + (nC1)x1 + ... + (nCn)xn, xi>=0
//      <=>
//      top - 2^n = (nC0)x0 + (nC1)x1 + ... + (nCn)xn, xi>=0
// calculate number of solutions with dp[n][top-2^n] (n is actually n-1 in the problem)
class NumberPyramids {
	public:
	int count(int n, int top) {
		if (n>20 || (1<<(n-1))>top) { // the minimum top number is 2^(n-1) (Pascal's triangle)
            return 0;
        }
        C[0][0] = 1; // calc binomial coefficients
        for (int i=1; i<=n; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
        
        // dp[i][j] = # of solutions to j == (nC0)y0 + (nC1)y1 + ... + (nCi)yi, all y >= 0
        //
        // 2 cases:
        //  yi == 0:
        //      dp[i-1][j] solutions
        //  yi >= 1:
        //      replace yi with (yi+1)
        //      j == (nC0)y0 + (nC1)y1 + ... + (nCi)(yi+1), yi >= 0
        //      <=>
        //      j - (nCi) == (nC0)y0 + (nC1)y1 + ... + (nCi)yi, all y >= 0
        //      <=>
        //      dp[i][j-(nCi)] ways
        //
        // here, n is actually n-1 from the problem
        // total dp[i][j] = dp[i-1][j] + dp[i][j-(nCi)]
        // calculated in row major order with 1D array
        for (int i=0; i<=top; ++i) {
            dp[i] = 1;
        }
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=top; ++j) {
                const int t = C[n-1][i];
                if (t <= j) {
                    dp[j] += dp[j-t];
                    if (dp[j] >= mod) {
                        dp[j] -= mod;
                    }
                }
            }
        }
        
        return dp[top-(1<<(n-1))];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 16; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 15; int Arg2 = 24; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 31556; int Arg2 = 74280915; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 150; int Arg1 = 500; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberPyramids ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
