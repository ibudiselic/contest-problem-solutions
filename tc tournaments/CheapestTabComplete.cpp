#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<string> names;
string W;
int dp[51];

bool starts_with(const string &s, const string &prefix) {
	if (s.size() < prefix.size())
		return false;
	else
		return s.substr(0, prefix.size()) == prefix;
}
int go(int x) {
	if (x == (int)W.size())
		return 0;
	if (dp[x] != -1)
		return dp[x];

	int ret = 1+go(x+1);
	vector<string> P;
	for (int i=0; i<(int)names.size(); ++i)
		if (starts_with(names[i], W.substr(0, x)))
			P.push_back(names[i]);

	for (int i=0; i<(int)P.size(); ++i)
		if ((int)P[i].size() > x && starts_with(W, P[i]))
			ret = min(ret, i+1 + go(P[i].size()));

	return dp[x] = ret;
}
class CheapestTabComplete {
	public:
	int getFewest(vector <string> names_, string w) {
		names = names_;
		sort(names.begin(), names.end());
		W = w;
		memset(dp, 0xff, sizeof dp);

		return go(0)+1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "myname"; int Arg2 = 7; verify_case(0, Arg2, getFewest(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"myn","myname"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "myname"; int Arg2 = 3; verify_case(1, Arg2, getFewest(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"abc","ab","abcd","frankies","frank","a","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "frankie"; int Arg2 = 5; verify_case(2, Arg2, getFewest(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a","a","f","f","fr","fr","fra","fra","fran","fran","frank","frank"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "frankie"; int Arg2 = 8; verify_case(3, Arg2, getFewest(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a","a","bcde","bcde","bcde","bcdefghij"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bcdefghijk"; int Arg2 = 6; verify_case(4, Arg2, getFewest(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"aaaa","aaaa","aaaa","aaaa","aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaaaaaaaaaaaaaaaaaaaaa"; int Arg2 = 21; verify_case(5, Arg2, getFewest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CheapestTabComplete ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
