#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(const string &s, char c) {
	int ret = 0;
	int cur = 0;
	bool in = false;
	for (int i=0; i<(int)s.size(); ++i) {
		if (s[i]=='<' || s[i]=='>') {
			if (in || s[i]=='>')
				ret = max(cur+1, ret);
			cur = 0;
			in = (s[i]=='<');
		} else if (s[i] == c) {
			++cur;
		} else {
			if (in)
				ret = max(cur+1, ret);
			cur = 0;
			in = false;
		}
	}
	if (in)
		ret = max(cur+1, ret);
	return ret;
}

class Arrows {
	public:
	int longestArrow(string s) {
		const int sol = max(f(s, '-'), f(s, '='));
		return sol ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<--->--==>"; int Arg1 = 4; verify_case(0, Arg1, longestArrow(Arg0)); }
	void test_case_1() { string Arg0 = "<<<<<<<<<<"; int Arg1 = 1; verify_case(1, Arg1, longestArrow(Arg0)); }
	void test_case_2() { string Arg0 = "----==-"; int Arg1 = -1; verify_case(2, Arg1, longestArrow(Arg0)); }
	void test_case_3() { string Arg0 = "<----=====>"; int Arg1 = 6; verify_case(3, Arg1, longestArrow(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Arrows ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
