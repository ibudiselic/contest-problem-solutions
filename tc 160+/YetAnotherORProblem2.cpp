#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int dp[2][1<<10];
const int mod = 1000000009;
class YetAnotherORProblem2 {
	public:
	int countSequences(int N, int R) {
        for (int i=0; i<(1<<N); ++i) {
            dp[1][i] = 1;
        }
        for (int i=0; ; ++i) {
            if ((1<<i) > R) {
                return dp[(i+1)&1][0];
            }
            for (int any=0; any<(1<<N); ++any) {
                int nany = any;
                if (R & (1<<i)) {
                    nany = (1<<N)-1;
                }
                dp[i&1][any] = dp[(i+1)&1][nany];
                for (int j=0; j<N; ++j) {
                    if (!(any & (1<<j)) && !(R & (1<<i))) {
                        continue;
                    }
                    int nnany = nany;
                    if (!(any & (1<<j))) {
                        nnany ^= 1<<j;
                    }
                    dp[i&1][any] += dp[(i+1)&1][nnany];
                    if (dp[i&1][any] >= mod) {
                        dp[i&1][any] -= mod;
                    }
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 7; verify_case(0, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 16; verify_case(2, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 1023; int Arg2 = 73741815; verify_case(3, Arg2, countSequences(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    YetAnotherORProblem2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
