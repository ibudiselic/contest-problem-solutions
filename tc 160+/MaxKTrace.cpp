#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

int dp[50][50][50]; // [i][j][curk]
int best[50][50][50]; // [k][i][j]

using namespace std;

class MaxKTrace {
	public:
	int getLargest(vector <string> mat, int k) {
		int n = mat.size();
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				mat[i][j] -= '0';

		--k;
		memset(dp, 0, sizeof dp);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dp[i][j][0] = mat[i][j];
		memset(best, 0, sizeof best);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				best[0][i][j] = mat[i][j];
				if (i > 0) best[0][i][j] = max(best[0][i][j], best[0][i-1][j]);
				if (j > 0) best[0][i][j] = max(best[0][i][j], best[0][i][j-1]);
			}

		for (int i=1; i<n; ++i)
			for (int j=1; j<n; ++j) {
				const int lim = min(min(i, j), k);
				for (int curk=1; curk<=lim; ++curk) {
					dp[i][j][curk] = best[curk-1][i-1][j-1]==0 ? 0 : best[curk-1][i-1][j-1]+mat[i][j];
					best[curk][i][j] = dp[i][j][curk];
					best[curk][i][j] = max(best[curk][i][j], best[curk][i-1][j  ]);
					best[curk][i][j] = max(best[curk][i][j], best[curk][i  ][j-1]);
				}
			}

		/*for (int curk=0; curk<=k; ++curk) {
			cerr << "---------------" << curk << '\n';
			for (int i=0; i<n; ++i) {
				for (int j=0; j<n; ++j)
					cerr << dp[i][j][curk] << ' ';
				cerr << '\n';
			}
			cerr << '\n';
			for (int i=0; i<n; ++i) {
				for (int j=0; j<n; ++j)
					cerr << best[curk][i][j] << ' ';
				cerr << '\n';
			}
			cerr << '\n';
		}*/

		return best[k][n-1][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"123",
"456",
"789"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 15; verify_case(0, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"12",
"93"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 9; verify_case(1, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {
"12689",
"55555",
"55555",
"55555",
"55555"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 16; verify_case(2, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"494599520389852",
"303896953907791",
"287493604901139",
"149554299340006",
"893640109028429",
"564962730433253",
"075854577852319",
"453201529585621",
"950489162577436",
"630040569640126",
"415141646262027",
"837673828874883",
"785041862021729",
"850806584119109",
"217671590991247"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 45; verify_case(3, Arg2, getLargest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MaxKTrace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
