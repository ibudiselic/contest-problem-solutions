#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double memo[1<<10];
bool v[1<<10];
unsigned long long mask[10][26];
vector<string> w;
int n, m;

class Hangman42 {
	public:
	double go(int state) {
		if (v[state]) return memo[state];
		v[state] = 1;

		if (state == 0) return 0.0;

		double res = 0.0;
		int k = 0;
		for (int i=0; i<n; ++i)
			if (state & (1<<i))
				++k;
		if (k==1) return memo[state] = 1.0;
		for (int i=0; i<n; ++i)
			if (state & (1<<i)) {
				double prob = 1.0/k + (k-1)*(1-go(state - (1<<i)))/k;
				res >?= prob;
			}
		for (int c=0; c<26; ++c) {
			double t = 0.0;
			int negstate = ~state;

			for (int i=0; i<n; ++i)
				if (!(negstate & (1<<i))) {
					int next = 0;
					int cnt = 0;
					for (int j=0; j<n; ++j)
						if (!(negstate & (1<<j)) && mask[i][c]==mask[j][c]) {
							next |= (1<<j);
							++cnt;
						}
					negstate |= next;
					if (state==next) continue;
					double prob = go(next);
					if (mask[i][c]==0ULL) prob = cnt*(1-prob)/k;
					else prob = cnt*prob/k;
					t += prob;

				}
			res >?= t;
		}
		return memo[state] = res;
	}
	double probability(vector <string> words) {
		n = (int)words.size();
		m = (int)words[0].size();
		w = words;

		for (int c=0; c<26; ++c)
			for (int i=0; i<n; ++i) {
				mask[i][c] = 0;
				for (int j=0; j<m; ++j)
					if (w[i][j]==c+'a') mask[i][c] |= (1ULL<<j);
			}
		memset(v, false, sizeof v);

		return go((1<<n)-1);
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
