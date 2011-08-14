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

int dp[52][52][52];
vector<int> L;
int go(int l, int r, int seed_ind) {
    int &ret = dp[l][r][seed_ind];
    if (ret != -1) {
        return ret;
    }
    if (l+1 == r) {
        ret = abs(L[seed_ind] - L[l]);
    } else {
        ret = 1234567890;
        for (int i=l+1; i<r; ++i) {
            ret = min(ret, go(l, i, seed_ind) + 1 + go(i, r, seed_ind));
            for (int j=l; j<=i; ++j) {
                ret = min(ret, go(l, i, j) + abs(L[j]-L[seed_ind]) + 1 + go(i, r, j));
            }
        }
    }
    return ret;
}
class WhiteSpaceEditing {
	public:
	int getMinimum(vector <int> lines) {
        L = lines;
        L.insert(L.begin(), 0);
        /* uncomment for memo solution
        memset(dp, 0xff, sizeof dp);
        return go(0, L.size(), 0) - 1;*/
        
        // bottom-up solution
        int n = L.size();
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<n; ++j) {
                dp[i-1][i][j] = abs(L[j] - L[i-1]);
            }
        }
        for (int len=2; len<=n; ++len) {
            for (int i=0; i+len<=n; ++i) {
                for (int seed_ind=0; seed_ind<n; ++seed_ind) {
                    dp[i][i+len][seed_ind] = 1234567890;
                    for (int split_after=1; split_after<len; ++split_after) {
                        dp[i][i+len][seed_ind] = min(dp[i][i+len][seed_ind],
                            dp[i][i+split_after][seed_ind] + 1 + dp[i+split_after][i+len][seed_ind]);
                        for (int new_seed=0; new_seed<=split_after; ++new_seed) {
                            dp[i][i+len][seed_ind] = min(dp[i][i+len][seed_ind],
                                dp[i][i+split_after][i+new_seed] + abs(L[seed_ind] - L[i+new_seed]) + 1 + dp[i+split_after][i+len][i+new_seed]);
                        }
                    }
                }
            }
        }
        return dp[0][n][0] - 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 2, 4 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = { 250, 105, 155, 205, 350 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(3, Arg1, getMinimum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WhiteSpaceEditing ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
