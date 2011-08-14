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

int dp[101][101]; // [i, j> intervals
string sol;
string pal;
void go(int l, int r) {
	assert(dp[l][r] != -1);
	if (dp[l][r] == 0) {
		sol += pal.substr(l, r-l);
	} else {
		go(l, dp[l][r]);
		sol += ' ';
		go(dp[l][r], r);
	}
}
class Palindromist {
	public:
	string palindrome(string text, vector <string> words) {
		set<string> w(words.begin(), words.end());
		string rev(text.size(), 0);
		for (int i=0; i<(int)text.size(); ++i)
			rev[i] = text[text.size()-1-i];
		pal = text + rev;

		memset(dp, 0xff, sizeof dp);
		// 0 will mean no spaces (the whole interval is a word)
		int n = pal.size();
		for (int i=0; i<n; ++i) {
			if (w.count(string(1, pal[i])) != 0)
				dp[i][i+1] = 0;
		}
		for (int len=2; len<=n; ++len) {
			for (int i=0; i+len<=n; ++i) {
				const int l = i;
				const int r = i+len;
				for (int j=l+1; j<r; ++j) {
					if (dp[l][j]!=-1 && dp[j][r]!=-1) {
						dp[l][r] = j;
						break;
					}
				}
				if (dp[l][r] == -1)
					if (w.count(string(pal.begin()+l, pal.begin()+r)) != 0)
						dp[l][r] = 0;
			}
		}

		sol.clear();
		if (dp[0][n] != -1)
			go(0, n);

		pal = text.substr(0, text.size()-1) + rev;
		memset(dp, 0xff, sizeof dp);
		n = pal.size();
		for (int i=0; i<n; ++i) {
			if (w.count(string(1, pal[i])) != 0)
				dp[i][i+1] = 0;
		}
		for (int len=2; len<=n; ++len) {
			for (int i=0; i+len<=n; ++i) {
				const int l = i;
				const int r = i+len;
				for (int j=l+1; j<r; ++j) {
					if (dp[l][j]!=-1 && dp[j][r]!=-1) {
						dp[l][r] = j;
						break;
					}
				}
				if (dp[l][r] == -1)
					if (w.count(string(pal.begin()+l, pal.begin()+r)) != 0)
						dp[l][r] = 0;
			}
		}
		string t;
		if (!sol.empty())
			t = sol;
		sol.clear();
		if (dp[0][n] != -1)
			go(0, n);
		if (sol.empty() && !t.empty())
			return t;
		else if (sol.empty() && t.empty())
			return "";
		else if (!sol.empty() && t.empty())
			return sol;
		else
			return sol<t ? sol : t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AMANAPLANAC"; string Arr1[] = { "A", "CANAL", "MAN", "PANAMA", "PLAN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A MAN A PLAN A CANAL PANAMA"; verify_case(0, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAAA"; string Arr1[] = { "AA", "A", "AAA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A A A A A A A A A"; verify_case(1, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "CBA"; string Arr1[] = { "CBABC", "CBAABC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CBAABC"; verify_case(2, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "RACEFAST"; string Arr1[] = { "AR", "CAR", "FAST", "RACE", "SAFE", "CEFA", "ACE", "STTS", "AFEC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RACE FAST SAFE CAR"; verify_case(3, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AABAABA"; string Arr1[] = { "AA", "AAB", "BAA", "BAB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AA BAA BAA BAA BAA"; verify_case(4, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "STRAWNOTOOSTUPIDAF"; string Arr1[] = { "WARTS", "I", "TOO", "A", "FAD", "STUPID", "STRAW", "PUT", "NO", "ON", "SOOT" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "STRAW NO TOO STUPID A FAD I PUT SOOT ON WARTS"; verify_case(5, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "AAAAA"; string Arr1[] = { "AAAA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(6, Arg2, palindrome(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "A"; string Arr1[] = { "A", "AA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A"; verify_case(7, Arg2, palindrome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Palindromist ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
