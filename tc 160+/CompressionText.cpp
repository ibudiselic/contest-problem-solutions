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

int dp[50];
string S, A, B;
int go(int pos) {
	if (pos+3 > (int)S.size())
		return (int)S.size()-pos;
	if (dp[pos] != -1)
		return dp[pos];

	int ret = 1 + go(pos+1);
	if (S.substr(pos, 3) == A)
		ret = min(ret, 2 + go(pos+3));
	if (S.substr(pos, 3) == B)
		ret = min(ret, 2 + go(pos+3));

	return dp[pos] = ret;
}
class CompressionText {
	public:
	int shortestLength(string original) {
		S = original;
		int best = original.size();
		if (best < 3)
			return best;
		if (best == 3)
			return 2;

		set<string> S_;
		for (int i=0; i+3<=(int)original.size(); ++i)
			S_.insert(original.substr(i, 3));

		vector<string> SS(S_.begin(), S_.end());
		for (int i=0; i<(int)SS.size(); ++i) {
			A = SS[i];
			for (int j=i+1; j<(int)SS.size(); ++j) {
				B = SS[j];
				memset(dp, 0xff, sizeof dp);
				best = min(best, go(0));
			}
		}
		A = SS[0];
		B = "";
		memset(dp, 0xff, sizeof dp);
		best = min(best, go(0));

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BARXFOO"; int Arg1 = 5; verify_case(0, Arg1, shortestLength(Arg0)); }
	void test_case_1() { string Arg0 = "FOOFOO BAR"; int Arg1 = 7; verify_case(1, Arg1, shortestLength(Arg0)); }
	void test_case_2() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXY"; int Arg1 = 46; verify_case(2, Arg1, shortestLength(Arg0)); }
	void test_case_3() { string Arg0 = "QWERTYUIOPASDFGHJKLZXCVBNM"; int Arg1 = 24; verify_case(3, Arg1, shortestLength(Arg0)); }
	void test_case_4() { string Arg0 = "BBAAAABBBBAAABABABBBABABAAABABABAAABBAABABBBABAAAB"; int Arg1 = 40; verify_case(4, Arg1, shortestLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CompressionText ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
