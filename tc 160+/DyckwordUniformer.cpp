#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

string go(const string &s) {
	int x = 0;
	vector<string> children;
	int start = 0;

	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] == 'X') {
			++x;
		} else {
			--x;
			if (x < 0)
				throw -1;

			if (x == 0) {
				children.push_back(s.substr(start, i-start+1));
				start = i+1;
			}
		}

	if (x != 0)
		throw -1;

	if (children.size() == 1) {
		assert(s[0] == 'X');
		assert(s[s.size()-1] == 'Y');

		children[0] = string("X") + go(s.substr(1, s.size()-2)) + "Y";
	} else {
		for (int i=0; i<(int)children.size(); ++i)
			children[i] = go(children[i]);
	}
	sort(children.begin(), children.end());

	return accumulate(children.begin(), children.end(), string());
}
class DyckwordUniformer {
	public:
	string uniform(string dyckword) {
		try {
			return go(dyckword);
		} catch (...) {
			;
		}

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XXYXXYYY"; string Arg1 = "XXXYYXYY"; verify_case(0, Arg1, uniform(Arg0)); }
	void test_case_1() { string Arg0 = "XYXYXXXYYYXXYY"; string Arg1 = "XXXYYYXXYYXYXY"; verify_case(1, Arg1, uniform(Arg0)); }
	void test_case_2() { string Arg0 = "XXXYYYXXYXXXYYYY"; string Arg1 = "XXXXYYYXYYXXXYYY"; verify_case(2, Arg1, uniform(Arg0)); }
	void test_case_3() { string Arg0 = "XXYYYX"; string Arg1 = ""; verify_case(3, Arg1, uniform(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DyckwordUniformer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
