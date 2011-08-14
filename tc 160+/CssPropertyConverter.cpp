#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
class CssPropertyConverter {
	public:
	string getCamelized(string cssPropertyName) {
		vector<string> t = cutUp(cssPropertyName, "-");

		string sol = t[0];

		for (int i=1; i<(int)t.size(); ++i)
			sol += string(1, toupper(t[i][0])) + (t[i].size() > 1 ? t[i].substr(1) : "");

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "z-index"; string Arg1 = "zIndex"; verify_case(0, Arg1, getCamelized(Arg0)); }
	void test_case_1() { string Arg0 = "border-collapse"; string Arg1 = "borderCollapse"; verify_case(1, Arg1, getCamelized(Arg0)); }
	void test_case_2() { string Arg0 = "top-border-width"; string Arg1 = "topBorderWidth"; verify_case(2, Arg1, getCamelized(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CssPropertyConverter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
