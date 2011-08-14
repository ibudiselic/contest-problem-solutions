#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int M, N;
int R[8];
int tog[1<<8];
int bc[1<<8];
int all;

int dp[8][1<<8][1<<8];
int go(int r, int prev, int here) {
    if (r == M) {
        return (R[M-1]^prev)==all ? 0 : 123456789;
    }

    int &ret = dp[r][prev][here];
    if (ret != -1) {
        return ret;
    }

    ret = 123456789;

    for (int mask=0; mask<(1<<N); ++mask) {
        int nprev = prev ^ tog[mask];
        int nhere = here ^ tog[mask];

        if (r==0 || ((R[r-1]^nprev) == all)) {
            ret = min(ret, bc[mask] + go(r+1, nhere, tog[mask]));
        }
    }

    return ret;
}

class LightedPanels {
	public:
	int minTouch(vector <string> board) {
		M = board.size();
        N = board[0].size();
        memset(R, 0, sizeof R);

        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] == '*') {
                    R[i] |= (1<<j);
                }
            }
        }

        all = (1<<N) - 1;
        bc[0] = 0;
        for (int mask=1; mask<(1<<N); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }

        for (int mask=0; mask<(1<<N); ++mask) {
            tog[mask] = 0;
            for (int j=0; j<N; ++j) {
                if (mask & (1<<j)) {
                    for (int i=j-1; i<j+2; ++i) {
                        if (i>=0 && i<N) {
                            tog[mask] ^= (1<<i);
                        }
                    }
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        int sol = go(0, 0, 0);

        return sol>123456 ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*****",
 "*...*",
 "*...*",
 "*...*",
 "*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minTouch(Arg0)); }
	void test_case_1() { string Arr0[] = {".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTouch(Arg0)); }
	void test_case_2() { string Arr0[] = {"**.",
 "**.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minTouch(Arg0)); }
	void test_case_3() { string Arr0[] = {"*...",
 "**..",
 "..**",
 "...*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minTouch(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LightedPanels ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
