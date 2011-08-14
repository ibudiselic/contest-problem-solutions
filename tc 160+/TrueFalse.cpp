#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char cur[20];
bool ok[20];
int n;
vector<int> c;
vector<string> a;
int cnt(int x) {
	int ret = 0;
	for (int i=0; i<n; ++i)
		if (cur[i] == a[x][i]) {
			++ret;
			ok[i] = 1;
		}
	return ret;
}
bool go(int x) {
	if (x == n) {
		memset(ok, 0, sizeof ok);
		for (int i=0; i<(int)a.size(); ++i)
			if (cnt(i) != c[i])
				return false;

		for (int i=0; i<n; ++i)
			if (!ok[i])
				return false;

		return true;
	}

	for (char c='F'; c<='T'; c+='T'-'F') {
		cur[x] = c;
		if (go(x+1))
			return true;
	}
	return false;
}
class TrueFalse {
	public:
	string answerKey(vector <string> graded) {
		c.clear();
		a.clear();
		for (int i=0; i<(int)graded.size(); ++i) {
			istringstream is(graded[i]);
			int x;
			string s;
			is >> x >> s;
			c.push_back(x);
			a.push_back(s);
		}

		n = a[0].size();
		cur[n] = '\0';
		if (go(0))
			return string(cur);
		else
			return "inconsistent";

		return "OH NOUZ";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2 TTF",
 "1 FTF",
 "2 FTT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TTT"; verify_case(0, Arg1, answerKey(Arg0)); }
	void test_case_1() { string Arr0[] = {"7 TTFFTFT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TTFFTFT"; verify_case(1, Arg1, answerKey(Arg0)); }
	void test_case_2() { string Arr0[] = {"9 TTTFFFFTTFFTTFT",
 "7 FFFFFFFFFFFFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "inconsistent"; verify_case(2, Arg1, answerKey(Arg0)); }
	void test_case_3() { string Arr0[] = {"9 TTTFFFFTTFFTTFT",
 "7 FFFFFFFFFFFFFFF",
 "8 TTTTTTTTTTTTTTT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "FFFFFFFTTTTTTTT"; verify_case(3, Arg1, answerKey(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TrueFalse ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
