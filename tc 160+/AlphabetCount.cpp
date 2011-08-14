#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> G;
int m, n;
int len;
int dp[50][50][26];
inline void update(int &x, int y) {
	x = min(x+y, 1000000000);
}
int go(int i, int j, char c) {
	if (i<0 || j<0 || i>=m || j>=n || G[i][j]!=c)
		return 0;
	if (c == 'A'+len-1)
		return 1;

	if (dp[i][j][c-'A'] != -1)
		return dp[i][j][c-'A'];

	int &ret = dp[i][j][c-'A'];
	ret = 0;
	for (int di=-1; di<2; ++di)
		for (int dj=-1; dj<2; ++dj)
			if (abs(di)+abs(dj) != 0)
				update(ret, go(i+di, j+dj, c+1));

	return ret;
}
class AlphabetCount {
	public:
	int count(vector <string> grid, int length) {
		G = grid;
		m = G.size();
		n = G[0].size();
		len = length;

		int sol = 0;
		memset(dp, 0xff, sizeof dp);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				update(sol, go(i, j, 'A'));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "ABC",
  "CBZ",
  "CZC",
  "BZZ",
  "ZAA" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "AAAA",
  "AAAA",
  "AAAA" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 12; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "ABAB",
  "BABA",
  "ABAB",
  "BABA" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 24; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "HIJKLMNOPQZZZONMLKHIDZYQR",
  "GYXWVUTSRASTZZPSTUJGECPXS",
  "FZABCDEFARQPUQRAAAVWFBOWT",
  "EONMJIHGAJMNOVAAAAAYXANUV",
  "DCBLKDEFIEKLEDWAAAZFGHMLK",
  "UVAZYBCGHFDFCAYXNPQZEDIJA",
  "TSWXAKLZGCZBGZIJOMZRUTCBZ",
  "RQPONMJIHBAZZHZZKLZZSVWXY" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 7; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "CZC",
  "ZBZ",
  "AZA" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 1000000000; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = { "BDBCBACABDDCCADCBDDCBDDDBCCCCABACADDDCCCBADDDBADCA",
  "DCBBBACBDBACCADABCCAABACDBADBCBBABACBCADADCBDABBBD" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 20; verify_case(6, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AlphabetCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
