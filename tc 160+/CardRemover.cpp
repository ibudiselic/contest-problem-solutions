#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> C;
int dp[50][50];
bool match[50][50];
bool isMatch(int a, int b) {
	static int c1[26];
	static int c2[26];
	memset(c1, 0, sizeof c1);
	memset(c2, 0, sizeof c2);
	for (int i=0; i<3; ++i) {
		++c1[C[a][i]-'A'];
		++c2[C[b][i]-'A'];
	}
	int cnt = 0;
	for (int i=0; i<26; ++i)
		cnt += (c1[i]>0 && c2[i]>0);

	return cnt >= 2;
}
int go(int a, int b) {
	if (a+1 >= b)
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];

	int ret = 0;
	for (int m=a+1; m<b; ++m) {
		int x = go(a, m);
		int y = go(m, b);
		if (match[a][b] && x+y+1==b-a-1)
			ret = max(ret, x+y+1);
		else
			ret = max(ret, x+y);
	}

	return (dp[a][b] = ret);
}
class CardRemover {
	public:
	int calculate(vector <string> cards) {
		C = cards;
		memset(match, 0xff, sizeof match);
		for (int i=0; i<(int)C.size(); ++i)
			for (int j=i+1; j<(int)C.size(); ++j)
				match[i][j] = match[j][i] = isMatch(i, j);

		memset(dp, 0xff, sizeof dp);
		return go(0, C.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "CDE",
 "ABC",
 "CDE",
 "ABC"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC",
 "CDE",
 "EFG",
 "GHI",
 "IJK"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { string Arr0[] = {"ADR",
 "FDB",
 "ABC",
 "CDE",
 "ABD"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, calculate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CardRemover ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
