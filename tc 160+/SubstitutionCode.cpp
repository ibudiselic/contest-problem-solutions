#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dig[256];
class SubstitutionCode {
	public:
	int getValue(string key, string code) {
		memset(dig, 0xff, sizeof dig);
		for (int i=0; i<9; ++i)
			dig[key[i]] = i+1;
		dig[key[9]] = 0;

		int ret = 0;
		for (int i=0; i<(int)code.size(); ++i)
			if (dig[code[i]] != -1)
				ret = ret*10 + dig[code[i]];

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TRADINGFEW"; string Arg1 = "LGXWEV"; int Arg2 = 709; verify_case(0, Arg2, getValue(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJ"; string Arg1 = "XJ"; int Arg2 = 0; verify_case(1, Arg2, getValue(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "CRYSTALBUM"; string Arg1 = "MMA"; int Arg2 = 6; verify_case(2, Arg2, getValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SubstitutionCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
