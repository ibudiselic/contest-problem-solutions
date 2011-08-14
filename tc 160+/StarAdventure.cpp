#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[2][50][50][50];
class StarAdventure {
	public:
	int mostStars(vector <string> level) {
		int m = level.size();
		int n = level[0].size();

		int cur = 0;
		int next = 1;

		for (int t=1; t<=m+n-2; ++t) {
		for (int ac=0; ac<n; ++ac)
			for (int bc=0; bc<n; ++bc)
				for (int cc=0; cc<n; ++cc) {
					const int ar = t-ac;
					const int br = t-bc;
					const int cr = t-cc;
					dp[next][ac][bc][cc] = 0;
					if (ar<0 || br<0 || cr<0 || ar>=m || br>=m || cr>=m)
						continue;

					int add = level[ar][ac] - '0';
					if (ac != bc) add += level[br][bc] - '0';
					if (ac != cc && bc != cc) add += level[cr][cc] - '0';

					int best = 0;
					if (ac>0 && bc>0 && cc>0) best = max(best, dp[cur][ac-1][bc-1][cc-1] + add);
					if (ac>0 && bc>0 && cr>0) best = max(best, dp[cur][ac-1][bc-1][cc  ] + add);
					if (ac>0 && br>0 && cc>0) best = max(best, dp[cur][ac-1][bc  ][cc-1] + add);
					if (ac>0 && br>0 && br>0) best = max(best, dp[cur][ac-1][bc  ][cc  ] + add);
					if (ar>0 && bc>0 && cc>0) best = max(best, dp[cur][ac  ][bc-1][cc-1] + add);
					if (ar>0 && bc>0 && cr>0) best = max(best, dp[cur][ac  ][bc-1][cc  ] + add);
					if (ar>0 && br>0 && cc>0) best = max(best, dp[cur][ac  ][bc  ][cc-1] + add);
					if (ar>0 && br>0 && cr>0) best = max(best, dp[cur][ac  ][bc  ][cc  ] + add);

					dp[next][ac][bc][cc] = best;
				}
		cur ^= 1;
		next ^= 1;
		}

		return dp[cur][n-1][n-1][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, mostStars(Arg0)); }
	void test_case_1() { string Arr0[] = {"0999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 450; verify_case(1, Arg1, mostStars(Arg0)); }
	void test_case_2() { string Arr0[] = {"012"
,"012"
,"012"
,"012"
,"012"
,"012"
,"012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, mostStars(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123456789",
 "1123456789",
 "2223456789",
 "3333456789",
 "4444456789",
 "5555556789",
 "6666666789",
 "7777777789",
 "8888888889",
 "9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 335; verify_case(3, Arg1, mostStars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StarAdventure ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
