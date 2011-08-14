#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
int dp[50][50];
string s;
map<string, int> unit_cost;
int calc(int l, int r) {
	string t;
	t += s[l];
	t += s[r];
	return unit_cost[t];
}
int go(int l, int r) {
	if (dp[l][r] != -1)
		return dp[l][r];
	if (r-l == 1)
		return dp[l][r] = calc(l, r);

	int ret = calc(l, r);
	ret += go(l+1, r-1);
	for (int k=l+1; k<r-1; k+=2)
		ret = min(ret, go(l, k) + go(k+1, r));
	return dp[l][r] = ret;
}

class CorrectingParenthesization {
	public:
	int getMinErrors(string s_) {
		s = s_;
		memset(dp, 0xff, sizeof dp);
		unit_cost["()"] = 0; unit_cost["(]"] = 1; unit_cost["(}"] = 1;
		unit_cost["[)"] = 1; unit_cost["[]"] = 0; unit_cost["[}"] = 1;
		unit_cost["{)"] = 1; unit_cost["{]"] = 1; unit_cost["{}"] = 0;

		unit_cost["))"] = 1; unit_cost[")]"] = 1; unit_cost[")}"] = 1;
		unit_cost["])"] = 1; unit_cost["]]"] = 1; unit_cost["]}"] = 1;
		unit_cost["})"] = 1; unit_cost["}]"] = 1; unit_cost["}}"] = 1;

		unit_cost["(("] = 1; unit_cost["(["] = 1; unit_cost["({"] = 1;
		unit_cost["[("] = 1; unit_cost["[["] = 1; unit_cost["[{"] = 1;
		unit_cost["{("] = 1; unit_cost["{["] = 1; unit_cost["{{"] = 1;

		unit_cost[")("] = 2; unit_cost[")["] = 2; unit_cost["){"] = 2;
		unit_cost["]("] = 2; unit_cost["]["] = 2; unit_cost["]{"] = 2;
		unit_cost["}("] = 2; unit_cost["}["] = 2; unit_cost["}{"] = 2;

		return go(0, s.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([{}])()[]{}"; int Arg1 = 0; verify_case(0, Arg1, getMinErrors(Arg0)); }
	void test_case_1() { string Arg0 = "([)]"; int Arg1 = 2; verify_case(1, Arg1, getMinErrors(Arg0)); }
	void test_case_2() { string Arg0 = "([{}[]"; int Arg1 = 1; verify_case(2, Arg1, getMinErrors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CorrectingParenthesization ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
