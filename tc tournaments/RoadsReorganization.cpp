#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<string> G;
int dp[50][2];
int go(int x, int prev, bool taken) {
	if (dp[x][taken] != -1)
		return dp[x][taken];

	int sum = 0;

	for (int i=0; i<N; ++i)
		if (i!=prev && G[x][i]=='1')
			sum += go(i, x, 0);

	int ret = sum;
	for (int i=0; i<N; ++i)
		if (i!=prev && G[x][i]=='1')
			ret = max(ret, sum-go(i, x, 0) + 1 + go(i, x, 1));

	if (taken)
		return dp[x][taken] = ret;

	for (int i=0; i<N-1; ++i)
		if (i!=prev && G[x][i]=='1')
			for (int j=i+1; j<N; ++j)
				if (j!=prev && G[x][j]=='1')
					ret = max(ret, sum - go(i, x, 0) - go(j, x, 0) + 2 + go(i, x, 1) + go(j, x, 1));

	return dp[x][taken] = ret;
}
class RoadsReorganization {
	public:
	int minDaysCount(vector <string> kingdom) {
		G = kingdom;
		N = G.size();

		memset(dp, 0xff, sizeof dp);

		return 2*(N-go(0, -1, 0)) - 1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010", "101", "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minDaysCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"0111",
 "1000",
 "1000",
 "1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minDaysCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"01010", "10100", "01000", "10001", "00010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minDaysCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"0100100", "1011000", "0100000", "0100000", "1000011", "0000100", "0000100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, minDaysCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"011111", "100000", "100000", "100000", "100000", "100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minDaysCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoadsReorganization ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
