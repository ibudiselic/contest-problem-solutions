#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
int memo[50][51][27];
string s;
int n;

class StripePainter {
	public:
	int go(int left, int size, int color) {
		if (left>=n || size==0) return 0;
		if (s[left]-'A' == color) return go(left+1, size-1, color);

		int &ret = memo[left][size][color];
		if (ret != 0) return ret;

		ret = 100;
		for (int i=1; i<=size; ++i)
			ret <?= 1 + go(left+1, i-1, s[left]-'A') + go(left+i, size-i, color);

		return ret;
	}
	int minStrokes(string stripes) {
		memset(memo, 0, sizeof memo);
		n = (int)stripes.size();
		s = stripes;

		return go(0, n, 26);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
	void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
	void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
	void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
	void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StripePainter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
