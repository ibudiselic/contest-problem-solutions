#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
//Characters 'a' to 'z' correspond to the numbers 0 through 25 and characters 'B' to 'Z' correspond to numbers -1 through -25.
int A[30][30];
int dp[30][30][30][30][4];
int m, n;
inline int sum(int i, int j, int r, int c) {
	return A[i][c] - (j==0 ? 0:A[i][j-1]) - (r==0 ? 0:A[r-1][c]) + (r==0 || j==0 ? 0:A[r-1][j-1]);
}
int go(int i, int j, int r, int c, int k) {
	int &ret = dp[i][j][r][c][k];
	if (ret != -1234567890)
		return ret;

	assert(k > 0);
	assert(r<=i && j<=c);

	if (k == 1) {
		ret = max(ret, sum(i, j, r, c));
		if (r < i) {
			ret = max(ret, go(i-1, j, r, c, 1));
			ret = max(ret, go(i, j, r+1, c, 1));
		}
		if (j < c) {
			ret = max(ret, go(i, j+1, r, c, 1));
			ret = max(ret, go(i, j, r, c-1, 1));
		}
	} else {
		for (int p=1; k-p>=1; ++p) {
			for (int y=r; y<i; ++y)
				ret = max(ret, go(y, j, r, c, p) + go(i, j, y+1, c, k-p));
			for (int x=j; x<c; ++x)
				ret = max(ret, go(i, j, r, x, p) + go(i, x+1, r, c, k-p));
		}
	}
	return ret;
}
class ThreeMines {
	public:
	int maximumProfit(vector <string> field) {
		m = field.size();
		n = field[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				A[i][j] = (i==0 ? 0:A[i-1][j]) + (j==0 ? 0:A[i][j-1]) - (i==0 || j==0 ? 0:A[i-1][j-1]) + (islower(field[i][j]) ? field[i][j]-'a' : 'A'-field[i][j]);

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				for (int r=0; r<m; ++r)
					for (int c=0; c<n; ++c)
						for (int k=0; k<4; ++k)
							dp[i][j][r][c][k] = -1234567890;

		return go(m-1, 0, 0, n-1, 3);
		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"bbbb",
"bBBB",
"BBbb",
"BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, maximumProfit(Arg0)); }
	void test_case_1() { string Arr0[] = {"cfCBDCbcdZb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(1, Arg1, maximumProfit(Arg0)); }
	void test_case_2() { string Arr0[] = {"d", "c", "B", "m", "Z", "h", "g", "B", "z", "G", "H", "b", "Y"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(2, Arg1, maximumProfit(Arg0)); }
	void test_case_3() { string Arr0[] = {
"hBhh",
"BBBB",
"BBBB",
"hBhh",
"hBhh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 62; verify_case(3, Arg1, maximumProfit(Arg0)); }
	void test_case_4() { string Arr0[] = {
"BB",
"BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -3; verify_case(4, Arg1, maximumProfit(Arg0)); }
	void test_case_5() { string Arr0[] = {
"ZcabcaacacabcbbbcababacaccbZaa",
"acaaccccacbccbaaccabaccaacbZbc",
"bcbaacbcbbccbbcbabbbbaZcbcbccb",
"cccacbabccbZbcbabaacbbZcbacbab",
"cacbabbcabbabbcacbcbbcaacaabbc",
"bacZcacaaccbabbcccccabcaacbaca",
"cbcccacabcabacaccacaZbbcbcacbb",
"cZbbbcaacbaacaabZcaccbcZccbbab",
"Zcababaacbbbbccbcbbaccacacbbcc",
"cZcccaaabbcbcbccccbcbaabbbccbb",
"bbcaacacabccababacbccacccbbaba",
"cccbbcaZabccacabbccccabbabbbab",
"bbbacbccbbcaabaaabccbcaabcacaa",
"cbbababbccccbcccbaacacccaabaac",
"aaccaccaccbabbccaaaacbacccacca",
"bbbcabcabZZcabcabbaacZbaaabaZb",
"aaabbabcabaaacbcccccbbcabcccbc",
"bbbaccbacacaccbbaccabacbbbaaac",
"acaaacccbabbccbcbabbcbaaaccabb",
"bcaaaaabcbabaaabccacccbaacbbbc",
"bZcbcbcccaabccaabbccbababbbcca",
"cbbbbcccabcabcbacaaaaabbbbbcac",
"ccbbcbacacbbcacacbaabcbbacbaba",
"cbbbaabaabbbbaccabbcbcaccaaaac",
"abZcabaacbbcacbaaabccbabacacaa",
"aabccacbabaacaccccbbbbcccccaca",
"aabcbaaacbabcaccbaabbbabbabbca",
"ababcabaccaaaacccacbcbcabacbcb",
"bcaaaacabcabbbaccccccacabccacb",
"cbbabbbccaaaaacbccaabcbbccbacc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 671; verify_case(5, Arg1, maximumProfit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ThreeMines ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
