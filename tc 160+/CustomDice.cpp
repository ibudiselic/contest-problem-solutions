#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;
int dp[2][6000001];
class CustomDice {
	public:
	int countDice(int M) {
	    M *= 6;
        memset(dp, 0, sizeof dp);
        for (int i=0; i<=M; ++i) {
            dp[0][i] = 1;
        }
        for (int i=1; i<=6; ++i) {
            for (int j=0; j<i; ++j) {
                dp[i&1][j] = 0;
            }
            for (int j=i; j<=M; ++j) {
                dp[i&1][j] = dp[i&1][j-i] + dp[(i-1)&1][j-i];
                if (dp[i&1][j] >= mod) {
                    dp[i&1][j] -= mod;
                }
            }
        }
        
        return (dp[0][M] * 30LL) % mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; verify_case(0, Arg1, countDice(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 210; verify_case(1, Arg1, countDice(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 863010; verify_case(2, Arg1, countDice(Arg0)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 375588112; verify_case(3, Arg1, countDice(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CustomDice ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
