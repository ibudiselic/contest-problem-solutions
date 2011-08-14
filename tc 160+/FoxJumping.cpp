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

const int mod = 10007;
int all_waysX[1601][801], all_waysY[1601][801];
int partial_sum[801];
void calc_all_ways(int T, int M, int R, int (*dp)[801]) {
    // ways to reach T from 0 in exactly R steps, while each step is between 0 and M (inclusive)
    dp[0][0] = 1; // zero steps, distance zero -> one way (don't do anything)
    for (int i=0; i<=T; ++i) {
        partial_sum[i] = 1;
    }
    for (int r=1; r<=R; ++r) {
        for (int t=0; t<=T; ++t) {
            dp[r][t] = partial_sum[t] - (t>M ? partial_sum[t-M-1] : 0);
            if (dp[r][t] < 0) {
                dp[r][t] += mod;
            }
        }
        partial_sum[0] = dp[r][0];
        for (int i=1; i<=T; ++i) {
            partial_sum[i] = partial_sum[i-1] + dp[r][i];
            if (partial_sum[i] >= mod) {
                partial_sum[i] -= mod;
            }
        }
    }
}

int C[1601][1601];
int B[1601][81];
class FoxJumping {
	public:
	int getCount(int Tx, int Ty, int Mx, int My, int R, vector <int> bad) {
        bad.push_back(0);
        sort(bad.begin(), bad.end());
		calc_all_ways(Tx, Mx, R, all_waysX);
		calc_all_ways(Ty, My, R, all_waysY);
        
        C[0][0] = 1; // combs
        for (int n=1; n<=R; ++n) {
            C[n][0] = C[n][n] = 1;
            for (int k=1; k<n; ++k) {
                C[n][k] = C[n-1][k-1] + C[n-1][k];
                if (C[n][k] >= mod) {
                    C[n][k] -= mod;
                }
            }
        }

        const int lim = min(Tx, Ty)/10;
        memset(B, 0, sizeof B);
        B[0][0] = 1;
        for (int i=1; i<=R; ++i) {
            for (int j=0; j<=lim; ++j) {
                for (int n=0; n<(int)bad.size(); ++n) {
                    if (j - bad[n]/10 >= 0) {
                        B[i][j] += B[i-1][j-bad[n]/10];
                        if (B[i][j] >= mod) {
                            B[i][j] -= mod;
                        }
                    }
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<=R; ++i) {
            for (int j=0; j<=lim; ++j) {
                int add = C[R][i] * ((i&1) ? -1 : 1) * B[i][j] % mod;
                add = (add+mod)%mod;
                add = add*all_waysX[R-i][Tx-j*10]%mod*all_waysY[R-i][Ty-j*10]%mod;
                sol = (sol+add)%mod;
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; verify_case(0, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 6; verify_case(1, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 1; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; verify_case(2, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 1; int Arr5[] = {10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 0; verify_case(3, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 11; int Arg2 = 11; int Arg3 = 11; int Arg4 = 2; int Arr5[] = {10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 140; verify_case(4, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 70; int Arg3 = 80; int Arg4 = 90; int Arr5[] = {30, 40, 20, 10, 50}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 6723; verify_case(5, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxJumping ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
