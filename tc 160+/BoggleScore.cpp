#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long mod = 10000000000000LL;
long long dp[4][4][50][50];
vector<string> A, W;
const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void add(long long &a, long long b) {
	a = (a+b)%mod;
}

int sqr(int x) { return x*x; }
long long go(int i, int j, int wInd, int wPos) {
	if (A[i][j]==W[wInd][wPos] && wPos+1==(int)W[wInd].size())
		return sqr(wPos+1);
	if (A[i][j] != W[wInd][wPos])
		return 0;

	long long &ret = dp[i][j][wInd][wPos];

	if (ret != -1)
		return ret;

	ret = 0;
	for (int d=0; d<8; ++d) {
		int r = i + di[d];
		int c = j + dj[d];

		if (r>=0 && r<4 && c>=0 && c<4)
			add(ret, go(r, c, wInd, wPos+1));
	}

	return ret;
}
class BoggleScore {
	public:
	long long bestScore(vector <string> grid, vector <string> words) {
		memset(dp, 0xff, sizeof dp);
		A = grid;
		W = words;

		long long sol = 0;
		for (int k=0; k<(int)words.size(); ++k)
			for (int i=0; i<4; ++i)
				for (int j=0; j<4; ++j)
					add(sol, go(i, j, k, 0));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"XXEY",
 "XXXX",
 "XXXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EYE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(0, Arg2, bestScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"XEYE",
 "XXXX",
 "XXXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EYE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 36LL; verify_case(1, Arg2, bestScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TEXX",
 "REXX",
 "XXXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"TREE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 32LL; verify_case(2, Arg2, bestScore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"XXXX",
 "XSAX",
 "XDNX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SANDS", "SAND", "SAD", "AND"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 59LL; verify_case(3, Arg2, bestScore(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"TREX",
 "XXXX",
 "XXXX",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"TREE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(4, Arg2, bestScore(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BoggleScore ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
