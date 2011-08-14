#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[1001][1001];
const long long mod = 1000000007;
class PuyoPuyo {
	public:
	int theCount(int L, int N) {
		memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i=1; i<=N; ++i) {
            dp[i][L-1] = 4*dp[i-1][0]%mod; // if empty add any color
            for (int j=1; j<N; ++j) {
                dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % mod; // otherwise either add top color
            }
            for (int j=1; j<=N-L; ++j) {
                dp[i][j+L-1] = (dp[i][j+L-1] + 3*dp[i-1][j]) % mod; // or one of the 3 other colors
            }
        }
        
        return dp[N][0];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 28; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 58; int Arg2 = 868294620; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 84; int Arg2 = 621871151; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 0; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PuyoPuyo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
