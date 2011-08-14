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
int dp[50][50][26];
int go(int i, int j, char c) {
	if (i<0 || j<0 || i>=m || j>=n || G[i][j]!=c)
		return 0;
	if (dp[i][j][c-'A'] != -1)
		return dp[i][j][c-'A'];

	int &ret = dp[i][j][c-'A'];
	ret = 0;
	for (int di=-1; di<2; ++di)
		for (int dj=-1; dj<2; ++dj)
			if (abs(di)+abs(dj) != 0)
				ret = max(ret, go(i+di, j+dj, c+1));
	ret += 1;
	return ret;
}

class ABCPath {
	public:
	int length(vector <string> grid) {
		G = grid;
		m = G.size();
		n = G[0].size();

		int sol = 0;
		memset(dp, 0xff, sizeof dp);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				sol = max(sol, go(i, j, 'A'));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "ABE",
  "CFG",
  "BDH",
  "ABC" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, length(Arg0)); }
	void test_case_1() { string Arr0[] = { "A" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, length(Arg0)); }
	void test_case_2() { string Arr0[] = { "BCDEFGHIJKLMNOPQRSTUVWXYZ" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, length(Arg0)); }
	void test_case_3() { string Arr0[] = { "C",
  "D",
  "B",
  "A" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, length(Arg0)); }
	void test_case_4() { string Arr0[] = { "KCBVNRXSPVEGUEUFCODMOAXZYWEEWNYAAXRBKGACSLKYRVRKIO",
  "DIMCZDMFLAKUUEPMPGRKXSUUDFYETKYQGQHNFFEXFPXNYEFYEX",
  "DMFRPZCBOWGGHYAPRMXKZPYCSLMWVGMINAVRYUHJKBBRONQEXX",
  "ORGCBHXWMTIKYNLFHYBVHLZFYRPOLLAMBOPMNODWZUBLSQSDZQ",
  "QQXUAIPSCEXZTTINEOFTJDAOBVLXZJLYOQREADUWWSRSSJXDBV",
  "PEDHBZOVMFQQDUCOWVXZELSEBAMBRIKBTJSVMLCAABHAQGBWRP",
  "FUSMGCSCDLYQNIXTSTPJGZKDIAZGHXIOVGAZHYTMIWAIKPMHTJ",
  "QMUEDLXSREWNSMEWWRAUBFANSTOOJGFECBIROYCQTVEYGWPMTU",
  "FFATSKGRQJRIQXGAPLTSXELIHXOPUXIDWZHWNYUMXQEOJIAJDH",
  "LPUTCFHYQIWIYCVOEYHGQGAYRBTRZINKBOJULGYCULRMEOAOFP",
  "YOBMTVIKVJOSGRLKTBHEJPKVYNLJQEWNWARPRMZLDPTAVFIDTE",
  "OOBFZFOXIOZFWNIMLKOTFHGKQAXFCRZHPMPKGZIDFNBGMEAXIJ",
  "VQQFYCNJDQGJPYBVGESDIAJOBOLFPAOVXKPOVODGPFIYGEWITS",
  "AGVBSRLBUYOULWGFOFFYAAONJTLUWRGTYWDIXDXTMDTUYESDPK",
  "AAJOYGCBYTMXQSYSPTBWCSVUMNPRGPOEAVVBGMNHBXCVIQQINJ",
  "SPEDOAHYIDYUJXGLWGVEBGQSNKCURWYDPNXBZCDKVNRVEMRRXC",
  "DVESXKXPJBPSJFSZTGTWGAGCXINUXTICUCWLIBCVYDYUPBUKTS",
  "LPOWAPFNDRJLBUZTHYVFHVUIPOMMPUZFYTVUVDQREFKVWBPQFS",
  "QEASCLDOHJFTWMUODRKVCOTMUJUNNUYXZEPRHYOPUIKNGXYGBF",
  "XQUPBSNYOXBPTLOYUJIHFUICVQNAWFMZAQZLTXKBPIAKXGBHXX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, length(Arg0)); }
	void test_case_5() { string Arr0[] = { "EDCCBA",
  "EDCCBA" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, length(Arg0)); }
	void test_case_6() { string Arr0[] = { "AMNOPA",
  "ALEFQR",
  "KDABGS",
  "AJCHUT",
  "AAIWVA",
  "AZYXAA" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(6, Arg1, length(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ABCPath ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
