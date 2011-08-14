#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool dp[50][3][5], done[50][3][5];
vector<int> a;
bool ugly(int x, int v, int c) {
	if (v==3 || c==5)
		return true;
	if (x == (int)a.size())
		return false;

	if (done[x][v][c])
		return dp[x][v][c];

	done[x][v][c] = 1;
	if (a[x] == 0)
		return dp[x][v][c] = ugly(x+1, 0, c+1);
	else if (a[x] == 1)
		return dp[x][v][c] = ugly(x+1, v+1, 0);
	else
		return dp[x][v][c] = ugly(x+1, 0, c+1) || ugly(x+1, v+1, 0);
}
bool nice(int x, int v, int c) {
	if (v==3 || c==5)
		return false;
	if (x == (int)a.size())
		return true;

	if (done[x][v][c])
		return dp[x][v][c];

	done[x][v][c] = 1;
	if (a[x] == 0)
		return dp[x][v][c] = nice(x+1, 0, c+1);
	else if (a[x] == 1)
		return dp[x][v][c] = nice(x+1, v+1, 0);
	else
		return dp[x][v][c] = nice(x+1, 0, c+1) || nice(x+1, v+1, 0);
}
class NiceOrUgly {
	public:
	int is_vowel(char c) {
		return string("AEIOU").find(c) != string::npos;
	}
	string describe(string s) {
		a.clear();
		for (int i=0; i<(int)s.size(); ++i)
			a.push_back(s[i]=='?' ? 2 : is_vowel(s[i]));

		memset(done, 0, sizeof done);
		bool x = ugly(0, 0, 0);
		memset(done, 0, sizeof done);
		bool y = nice(0, 0, 0);
		if (x && y)
			return "42";
		return x ? "UGLY":"NICE";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "HELLOWORLD"; string Arg1 = "NICE"; verify_case(0, Arg1, describe(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "UGLY"; verify_case(1, Arg1, describe(Arg0)); }
	void test_case_2() { string Arg0 = "HELLOW?RLD"; string Arg1 = "42"; verify_case(2, Arg1, describe(Arg0)); }
	void test_case_3() { string Arg0 = "H??LOWOR??"; string Arg1 = "NICE"; verify_case(3, Arg1, describe(Arg0)); }
	void test_case_4() { string Arg0 = "EE?FFFF"; string Arg1 = "UGLY"; verify_case(4, Arg1, describe(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NiceOrUgly ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
