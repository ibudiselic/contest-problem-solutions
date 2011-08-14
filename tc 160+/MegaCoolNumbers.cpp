#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mod = 1000000007;
int dp[1001][10][10][10];

class MegaCoolNumbers {
	public:
	int count(int N, int A) {
		memset(dp, 0, sizeof dp);
        if (A > 9) {
            return 0;
        }
        
        for (int d=1; d<10; ++d) {
            dp[1][1][9][d] = 1;
        }
        for (int i=2; i<=N; ++i) {
            for (int a=1; a<10; ++a) {
                for (int last=1; last<10; ++last) {
                    for (int d=last; d<10; ++d) {
                        dp[i][a][d-last][d] += dp[i-1][a][9][last];
                        dp[i][a][d-last][d] %= mod;
                    }
                    for (int diff=0; diff<9; ++diff) {
                        for (int d=last; d<10; ++d) {
                            if (d - last == diff) {
                                dp[i][a][diff][d] += dp[i-1][a][diff][last];
                                dp[i][a][diff][d] %= mod;
                            } else if (a < 9) {
                                dp[i][a+1][9][d] += dp[i-1][a][diff][last];
                                dp[i][a+1][9][d] %= mod;
                            }
                        }
                    }
                }
            }
        }
        
        int sol = 0;
        for (int last=1; last<10; ++last) {
            for (int diff=0; diff<10; ++diff) {
                sol = (sol + dp[N][A][diff][last]) % mod;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 9; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 45; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7502; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MegaCoolNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
