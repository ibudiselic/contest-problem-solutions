#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int dp[30][30];
bool need[30][30];
class FallingBall {
	public:
	int howMany(vector <string> cells, int n) {
		memset(dp, 0, sizeof dp);
		memset(need, 0, sizeof need);

		for (int i=0; i<(int)cells.size(); ++i) {
			istringstream is(cells[i]);
			int x, y;
			is >> x >> y;
			need[x][y] = true;
		}

		dp[0][0] = 1;
		for (int r=1; r<n; ++r) {
			int cnt = 0;;
			for (int c=0; c<=r; ++c) {
				dp[r][c] += dp[r-1][c];
				if (c > 0) dp[r][c] += dp[r-1][c-1];
				cnt += need[r][c];
			}
			if (cnt > 1) {
				return 0;
			} else if (cnt == 1) {
				for (int c=0; c<=r; ++c)
					if (!need[r][c])
						dp[r][c] = 0;
			}
		}

		return accumulate(dp[n-1], dp[n-1]+n+1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 2","5 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 6; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 536870912; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 0","29 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10 0","10 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FallingBall ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
