#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int n;
vector<string> W;
int cnt[1<<10][26];
bool done[1<<10];
double dp[1<<10];
bool memo[10][10][26];
bool dmemo[10][10][26];
bool match(int i, int j, int c) {
	if (dmemo[i][j][c])
		return memo[i][j][c];

	dmemo[i][j][c] = 1;
	for (int k=0; k<(int)W[i].size(); ++k)
		if ((W[i][k]-'a'==c || W[j][k]-'a'==c) && W[i][k]!=W[j][k])
			return memo[i][j][c] = 0;

	return memo[i][j][c] = 1;
}
double go(int m, int bc) {
	if (bc == 1)
		return 1.0;

	if (done[m])
		return dp[m];

	done[m] = 1;
	dp[m] = 0.0;

	// guess the answer
	for (int i=0; i<n; ++i)
		if (m & (1<<i))
			dp[m] = max(dp[m], 1.0/bc + (1-1.0/bc)*(1-go(m ^ (1<<i), bc-1)));

	// guess a letter
	for (int i=0; i<26; ++i)
		if (cnt[m][i] > 0) {
			double p = 0.0;
			vector<int> nm;
			vector<int> nbc;
			vector<bool> used(n, 0);
			for (int j=0; j<n; ++j)
				if (!used[j] && (m & (1<<j))) {
					used[j] = 1;
					int nm_=(1<<j);
				int nbc_ = 1;
				for (int k=0; k<n; ++k)
					if (!used[k] && (m & (1<<k)))
						if (match(j, k, i)) {
							nm_ |= (1<<k);
							++nbc_;
							used[k] = 1;
						}
				nm.push_back(nm_);
				nbc.push_back(nbc_);
			}

			int wo = 0;
			int wocnt = 0;
			for (int w=0; w<n; ++w)
				if (m & (1<<w))
					if (W[w].find(i+'a') == string::npos) {
						wo |= (1<<w);
						++wocnt;
					}

			if (wo == m)
				continue;

			for (int w=0; w<n; ++w)
				if (m & (1<<w)) {
					if (wo & (1<<w))
						p += (1-go(wo, wocnt));
					else
						for (int j=0; j<(int)nm.size(); ++j)
							if (nm[j] & (1<<w)) {
								if ((wo & (1<<w)) == 0)
									p += go(nm[j], nbc[j]);
								break;
							}
				}

			dp[m] = max(dp[m], p/bc);
		}

	return dp[m];
}
class Hangman42 {
	public:
	double probability(vector <string> words) {
		W = words;
		n = W.size();

		memset(cnt, 0, sizeof cnt);
		for (int m=0; m<(1<<n); ++m)
			for (int i=0; i<n; ++i)
				if (m & (1<<i))
					for (int j=0; j<(int)W[i].size(); ++j)
						++cnt[m][W[i][j]-'a'];

		memset(dmemo, 0, sizeof dmemo);
		memset(done, 0, sizeof done);

		return go((1<<n)-1, n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"top","web","cam","buy","now"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.6; verify_case(0, Arg1, probability(Arg0)); }
	void test_case_1() { string Arr0[] = {"a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, probability(Arg0)); }
	void test_case_2() { string Arr0[] = {"ozeexsuaihtuucqghqsjzqzugmaebvdrddyztehr",
"lvjvwhqyeqpapbjusjtxfbcgfbsudrbhpydzryyp",
"cigacdzesqanrlflmsxvhvtvtnzelbzlopcchdob",
"edqogzausmjxzoagpsssxwnmfranrrswjsdgqcqv",
"ptvbnhdcecegnnsofcxaqtizrkwvazfngvzgcsqb",
"guiqkikpwwbzgpvtikaaxxjitqkqfughdlmjtdax",
"gbubcxhxscszrcuzbggjmnzlzihftpmpmaamtxcp",
"tuijqvgvbiwbyjhjmkmmqlmhayvdqhlkpptqqide",
"yidryvjmpbjkdzhmhtoynhbwlbsehcbymltrddsj"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8888888888888888; verify_case(2, Arg1, probability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Hangman42 ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
