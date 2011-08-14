#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long ways[9];
bool visited[4][4];
long long cntWays(int i, int j, int sz) {
	if (i<0 || j<0 || i>=4 || j>=4 || visited[i][j])
		return 0;
	if (sz == 1)
		return 1;

	visited[i][j] = 1;
	long long ret = 0;
	ret += cntWays(i-1, j  , sz-1);
	ret += cntWays(i  , j+1, sz-1);
	ret += cntWays(i+1, j  , sz-1);
	ret += cntWays(i  , j-1, sz-1);
	visited[i][j] = 0;

	return ret;
}

int N;
bool has[16][26];
bool done[8][1<<16];
double dp[8][1<<16];
string W;

double go(int pos, int mask, int cnt) {
	if (pos == (int)W.size())
		return 1.0;

	if (done[pos][mask])
		return dp[pos][mask];

	done[pos][mask] = 1;
	double &ret = dp[pos][mask];

	ret = 0.0;
	for (int i=0; i<N; ++i)
		if ((mask & (1<<i)) && has[i][W[pos]-'A'])
			ret += go(pos+1, mask ^ (1<<i), cnt-1);
	ret /= 6.0 * cnt;

	return ret;
}

class WordBoggle {
	public:
	double expectedScore(vector <string> cubes, vector <string> dict) {
		memset(visited, 0, sizeof visited);
		memset(ways, 0, sizeof ways);
		for (int sz=1; sz<9; ++sz)
			for (int i=0; i<4; ++i)
				for (int j=0; j<4; ++j)
					ways[sz] += cntWays(i, j, sz);

		N = cubes.size();
		memset(has, 0, sizeof has);
		for (int i=0; i<N; ++i)
			for (int j=0; j<6; ++j)
				has[i][cubes[i][j]-'A'] = 1;

		double sol = 0.0;
		for (int i=0; i<(int)dict.size(); ++i) {
			W = dict[i];
			memset(done, 0, sizeof done);
			sol += go(0, (1<<N)-1, N) * ways[W.size()] * W.size() * W.size();
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEI", "ABCDEJ", "ABCDEK", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"I"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.16666666666666666; verify_case(0, Arg2, expectedScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABCDEI", "ABCDEJ", "ABCDEK", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCDABCD","EFEFEFEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.1048729505519629; verify_case(1, Arg2, expectedScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ABCDEI", "ABCDEJ", "ABCDEK", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF",
"ABCDEF", "ABCDEF", "ABCDEF", "ABCDEF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.6666666666666665; verify_case(2, Arg2, expectedScore(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordBoggle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
