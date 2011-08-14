#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DigitMask {
	public:
	int howMany(vector <string> patterns, int len) {
		for (int i=0; i<(int)patterns.size(); ++i)
			if (patterns[i][0] == '-')
				patterns[i] = string(max(0, len-(int)patterns[i].size()+1), '?') + patterns[i].substr(1);
			else if (patterns[i][patterns[i].size()-1] == '-')
				patterns[i] = patterns[i].substr(0, patterns[i].size()-1) + string(max(0, len-(int)patterns[i].size()+1), '?');

		for (int i=0; i<(int)patterns.size(); ++i)
			if ((int)patterns[i].size() != len)
				return 0;

		int sol = 1;
		for (int j=0; j<len; ++j) {
			char c = '?';
			for (int i=0; i<(int)patterns.size(); ++i)
				if (patterns[i][j] != '?') {
					if (c!='?' && c!=patterns[i][j])
						return 0;
					c = patterns[i][j];
				}
			if (c == '?')
				sol *= 10;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1000; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"9??","??7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 10; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"9??","??7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"9??-","-???7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 100; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {
"??????????????????????????????????????????????????",
"?????????????????????????????????????????????????9",
"?????????????????????????????????????????????????8"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 0; verify_case(4, Arg2, howMany(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {
"-?????"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(5, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigitMask ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
