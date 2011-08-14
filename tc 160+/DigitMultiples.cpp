#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string calc(int m, string s) {
	for (int i=0; i<(int)s.size(); ++i) {
		const int t = (s[i]-'0')*m;
		if (t > 9)
			return "";
		s[i] = '0'+t;
	}
	return s;
}
class DigitMultiples {
	public:
	int getLongest(string single, string multiple) {
		for (int l=(int)single.size(); l>0; --l)
			for (int i=0; i+l<=(int)single.size(); ++i)
				for (int m=0; m<10; ++m) {
					const string s = calc(m, single.substr(i, l));
					if (s!="" && multiple.find(s)!=string::npos)
						return l;
				}

		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3211113321571"; string Arg1 = "5555266420"; int Arg2 = 5; verify_case(0, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "100200300"; string Arg1 = "100400600"; int Arg2 = 8; verify_case(1, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "111111111100000000000000000000000000000000000"; string Arg1 = "122333444455555666666777777788888888999999999"; int Arg2 = 9; verify_case(2, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "000000000000"; string Arg1 = "000000000000"; int Arg2 = 12; verify_case(3, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "11111111111"; string Arg1 = "11111111111"; int Arg2 = 11; verify_case(4, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "89248987092734709478099"; string Arg1 = "00000000000000000000000"; int Arg2 = 23; verify_case(5, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "11111111111111111111111111111111111111111111111111"; string Arg1 = "00000000000000000000000001111111111111111111111111"; int Arg2 = 25; verify_case(6, Arg2, getLongest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigitMultiples ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
